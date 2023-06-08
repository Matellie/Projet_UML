#ifndef CSV_READER_H
#define CSV_READER_H
#include "Data.h"

class CsvReader
{
public:
    // static Data *readCsv();
    static Data *readCsv(const char *nomDossier = "data");

protected:
    static void readSensorsCsv(Data *data, const char *nomDossier);
    static void readUsersCsv(Data *data, const char *nomDossier);
    static void readMeasurementsCsv(Data *data, const char *nomDossier);
};

#endif