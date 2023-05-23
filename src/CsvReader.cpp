#include "CsvReader.h"
#include "Sensor.h"
#include "User.h"
#include "Measurement.h"
#include <iostream>
#include <fstream>

using namespace std;

CsvReader::CsvReader()
{
}

CsvReader::~CsvReader()
{
}

Data *CsvReader::readCsv()
{
    Data *data = new Data;
    readSensorsCsv(data);
    readUsersCsv(data);
    readMeasurementsCsv(data);

    return data;
}

void CsvReader::readSensorsCsv(Data *data)
{
    ifstream streamSensors;
    streamSensors.open("data/sensors.csv");
    if (streamSensors.fail())
    {
        cerr << "can't open sensors.csv" << endl;
        exit(1);
    }
    string id, strLatitude, strLongitude, tmp;
    double latitude, longitude;
    Sensor *sensor;
    getline(streamSensors, id, ';');
    while (!streamSensors.eof())
    {
        getline(streamSensors, strLatitude, ';');
        latitude = stof(strLatitude);
        getline(streamSensors, strLongitude, ';');
        longitude = stof(strLongitude);
        getline(streamSensors, tmp);
        sensor = new Sensor(id, latitude, longitude);
        data->sensors.insert({id, sensor});
        getline(streamSensors, id, ';');
    }
}

void CsvReader::readUsersCsv(Data *data)
{
    ifstream streamUsers;
    streamUsers.open("data/users.csv");
    if (streamUsers.fail())
    {
        cerr << "can't open users.csv" << endl;
        exit(1);
    }
    string idUser, idSensor, tmp;
    User *user;
    Sensor *sensor;
    while (!streamUsers.eof())
    {
        getline(streamUsers, idUser, ';');
        getline(streamUsers, idSensor, ';');
        getline(streamUsers, tmp);
        unordered_map<string, User *>::iterator itUser = data->users.find(idUser);
        if (itUser == data->users.end())
        {
            user = new User(idUser, User::Clearance::LAMBDA);
            data->users.insert({idUser, user});
        }
        user = data->users.at(idUser);
        sensor = data->sensors.at(idSensor);
        sensor->user = user;
        user->sensors.push_back(sensor);
    }
}

void CsvReader::readMeasurementsCsv(Data *data)
{
    ifstream streamUsers;
    streamUsers.open("data/measurements.csv");
    if (streamUsers.fail())
    {
        cerr << "can't open measurements.csv" << endl;
        exit(1);
    }
    string strTimestamp, idSensor, attributeId, strValue, tmp;

    time_t timestamp  =0;
    //struct tm tm;

    Concentration concentration;
    Measurement *measurement;
    Sensor* sensor;
    while (!streamUsers.eof())
    {
        getline(streamUsers, strTimestamp, ';');
        /*strptime(strTimestamp.c_str(), "%Y-%m-%d %H:%M:%S", &tm);
        timestamp = mktime(&tm);*/
        getline(streamUsers, idSensor, ';');
        getline(streamUsers, tmp, ';');
        getline(streamUsers, strValue, ';');
        concentration.o3 = stol(strValue);
        getline(streamUsers, tmp);

        getline(streamUsers, tmp, ';');
        getline(streamUsers, tmp, ';');
        getline(streamUsers, tmp, ';');
        getline(streamUsers, strValue, ';');
        concentration.so2 = stol(strValue);
        getline(streamUsers, tmp);

        getline(streamUsers, tmp, ';');
        getline(streamUsers, tmp, ';');
        getline(streamUsers, tmp, ';');
        getline(streamUsers, strValue, ';');
        concentration.no2 = stol(strValue);
        getline(streamUsers, tmp);

        getline(streamUsers, tmp, ';');
        getline(streamUsers, tmp, ';');
        getline(streamUsers, tmp, ';');
        getline(streamUsers, strValue, ';');
        concentration.pm10 = stol(strValue);
        getline(streamUsers, tmp);

        sensor = data->sensors.at(idSensor);
        measurement = new Measurement(sensor, timestamp, concentration);
        sensor->measurements.insert({timestamp, measurement});
        data->measurements.push_back(measurement);
    }
}