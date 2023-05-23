#pragma once

#include <time.h>

#include "Concentration.h"

class Sensor;

class Measurement{
  public:
    Measurement(Sensor* pSensor, time_t pTimestamp, Concentration pConcentration);

    ~Measurement();

    Sensor* sensor;
    time_t timestamp;
    Concentration concentration;
};