#include "CsvReader.h"
#include <iostream>
#include <fstream>

using namespace std;

CsvReader::CsvReader()
{
}

CsvReader::~CsvReader()
{
}

Data CsvReader::readCsv()
{
    Data data;
    readSensorsCsv(data);
    readUsersCsv(data);
    readMeasurementsCsv(data);
}

void CsvReader::readSensorsCsv(Data &data)
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
    while (!streamSensors.eof())
    {
        getline(streamSensors, id, ';');
        getline(streamSensors, strLatitude, ';');
        latitude = stof(strLatitude);
        getline(streamSensors, strLongitude, ';');
        longitude = stof(strLongitude);
        getline(streamSensors, tmp);
        // TODO creer sensor le mettre dans data
    }
}

void CsvReader::readUsersCsv(Data &data)
{
    ifstream streamUsers;
    streamUsers.open("data/users.csv");
    if (streamUsers.fail())
    {
        cerr << "can't open users.csv" << endl;
        exit(1);
    }
    string idUser, idSensor, tmp;
    while (!streamUsers.eof())
    {
        getline(streamUsers, idUser, ';');
        getline(streamUsers, idSensor, ';');
        getline(streamUsers, tmp);
        // TODO creer
    }
}

void CsvReader::readMeasurementsCsv(Data &data)
{
    ifstream streamUsers;
    streamUsers.open("data/measurements.csv");
    if (streamUsers.fail())
    {
        cerr << "can't open measurements.csv" << endl;
        exit(1);
    }
    string strTimestamp, idSensor, attributeId, strValue, tmp;

    time_t timestamp;
    struct tm tm;

    double value;
    while (!streamUsers.eof())
    {
        getline(streamUsers, strTimestamp, ';');
        strptime(strTimestamp.c_str(), "%Y-%m-%d %H:%M:%S", &tm);
        timestamp = mktime(&tm);
        getline(streamUsers, idSensor, ';');
        getline(streamUsers, attributeId, ';');
        getline(streamUsers, strValue, ';');
        value = stol(strValue);
        getline(streamUsers, tmp);
    }
}