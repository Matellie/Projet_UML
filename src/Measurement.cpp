#include "Measurement.h"
//#include "Sensor.h"

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
#include "Concentration.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

double Concentration::GetLengthSquared()
// Algorithme:
//
{
  double ans = 0;

  ans += std::pow(o3, 2);
  ans += std::pow(no2, 2);
  ans += std::pow(so2, 2);
  ans += std::pow(pm10, 2);

  return ans;
} // ----- Fin de GetLengthSquared

//------------------------------------------------- Surcharge d'opérateurs

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