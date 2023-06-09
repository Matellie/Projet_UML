#include "CsvReader.h"
#include "Sensor.h"
#include "User.h"
#include "Measurement.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
Data *CsvReader::readCsv(const char *nomDossier)
{
    Data *data = new Data;
    readSensorsCsv(data, nomDossier);
    readUsersCsv(data, nomDossier);
    readMeasurementsCsv(data, nomDossier);

    return data;
}

void CsvReader::readSensorsCsv(Data *data, const char *nomDossier)
{
    ifstream streamSensors;
    string nomFichier(nomDossier);
    nomFichier += "/sensors.csv";
    streamSensors.open(nomFichier.c_str());
    if (streamSensors.fail())
    {
        cerr << "can't open " << nomFichier << endl;
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

void CsvReader::readUsersCsv(Data *data, const char *nomDossier)
{
    ifstream streamUsers;
    string nomFichier(nomDossier);
    nomFichier += "/users.csv";
    streamUsers.open(nomFichier.c_str());
    if (streamUsers.fail())
    {
        cerr << "can't open " << nomFichier << endl;
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
            user = new User(idUser);
            data->users.insert({idUser, user});
        }
        user = data->users.at(idUser);
        sensor = data->sensors.at(idSensor);
        sensor->user = user;
        user->sensors.push_back(sensor);
    }
}

void CsvReader::readMeasurementsCsv(Data *data, const char *nomDossier)
{
    ifstream streamMeasurements;
    string nomFichier(nomDossier);
    nomFichier += "/measurements.csv";
    streamMeasurements.open(nomFichier.c_str());
    if (streamMeasurements.fail())
    {
        cerr << "can't open " << nomFichier << endl;
        exit(1);
    }
    string strTimestamp, idSensor, attributeId, strValue, tmp;

    time_t timestamp = 0;
    struct tm tm;
    memset(&tm, 0, sizeof(tm));

    Concentration concentration;
    Measurement *measurement;
    Sensor *sensor;
    while (!streamMeasurements.eof())
    {
        getline(streamMeasurements, strTimestamp, ';');
        strptime(strTimestamp.c_str(), "%Y-%m-%d %H:%M:%S", &tm);
        timestamp = mktime(&tm);
        getline(streamMeasurements, idSensor, ';');
        getline(streamMeasurements, tmp, ';');
        getline(streamMeasurements, strValue, ';');
        concentration.o3 = stol(strValue);
        getline(streamMeasurements, tmp);

        getline(streamMeasurements, tmp, ';');
        getline(streamMeasurements, tmp, ';');
        getline(streamMeasurements, tmp, ';');
        getline(streamMeasurements, strValue, ';');
        concentration.so2 = stol(strValue);
        getline(streamMeasurements, tmp);

        getline(streamMeasurements, tmp, ';');
        getline(streamMeasurements, tmp, ';');
        getline(streamMeasurements, tmp, ';');
        getline(streamMeasurements, strValue, ';');
        concentration.no2 = stol(strValue);
        getline(streamMeasurements, tmp);

        getline(streamMeasurements, tmp, ';');
        getline(streamMeasurements, tmp, ';');
        getline(streamMeasurements, tmp, ';');
        getline(streamMeasurements, strValue, ';');
        concentration.pm10 = stol(strValue);
        getline(streamMeasurements, tmp);

        sensor = data->sensors.at(idSensor);
        measurement = new Measurement(sensor, timestamp, concentration);

        /*cout << measurement->sensor->id << ":" <<
        " timestamp=" << measurement->timestamp <<
        " c(NO2)=" << measurement->concentration.no2 <<
        " c(O3)=" << measurement->concentration.o3 <<
        " c(SO2)=" << measurement->concentration.so2 <<
        " c(PM10)=" << measurement->concentration.pm10 << endl;*/

        sensor->measurements.insert({timestamp, measurement});
        /*cout << sensor->measurements.size() << endl;*/
        data->measurements.push_back(measurement);
    }
}