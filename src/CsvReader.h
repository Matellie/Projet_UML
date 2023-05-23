#ifndef CSV_READER_H
#define CSV_READER_H
#include "Data.h"

class CsvReader
{
public:
    CsvReader();
    ~CsvReader();

    Data *readCsv();

protected:
    void readSensorsCsv(Data *data);
    void readUsersCsv(Data *data);
    void readMeasurementsCsv(Data *data);
};

#endif