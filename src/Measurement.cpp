#include "Measurement.h"
#include "Sensor.h"

/*************************************************************************
                           Position  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Concentration> (fichier Concentration.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <math.h>
#include <iostream>
#include <stdio.h>

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs
  ostream& operator<<(ostream& os, const Measurement& measurement){
    os << measurement.sensor->id << ":" << 
    " c(NO2)=" << measurement.concentration.no2 <<
    " c(O3)=" << measurement.concentration.o3 <<
    " c(SO2)=" << measurement.concentration.so2 <<
    " c(PM10)=" << measurement.concentration.pm10;

    return os;
  }
//-------------------------------------------- Constructeurs - destructeur

Measurement::Measurement(Sensor* pSensor, 
                        time_t pTimestamp, 
                        Concentration pConcentration) :
                      sensor(pSensor),
                      timestamp(pTimestamp),
                      concentration(pConcentration)
//Algorithme:
//
{
  #ifdef MAP
    std::cout << "Appel au constructeur de <Measurement>" << std::endl;
  #endif
}


Measurement::~Measurement()
// Algorithme:
//
{
  #ifdef MAP
    std::cout << "Appel au constructeur de <Measurement>" << std::endl;
  #endif
  //delete sensor;
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées