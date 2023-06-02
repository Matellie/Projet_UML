#ifndef CSV_READER_H
#define CSV_READER_H
#include "Data.h"

class CsvReader
{
public:
    static Data *readCsv();

protected:
    static void readSensorsCsv(Data *data);
    static void readUsersCsv(Data *data);
    static void readMeasurementsCsv(Data *data);
};

#endif