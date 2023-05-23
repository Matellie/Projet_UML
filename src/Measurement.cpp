#include "Measurement.h"

Measurement::Measurement(Sensor* pSensor, 
                        time_t pTimestamp, 
                        Concentration pConcentration) :
                      sensor(pSensor),
                      timestamp(pTimestamp),
                      concentration(pConcentration){
}

Measurement::~Measurement(){
  //delete sensor;
}