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
Concentration Concentration::operator-(Concentration const& concentration)
// Algorithme:
// 
{
  return Concentration(
    o3 - concentration.o3,
    so2 - concentration.so2,
    no2 - concentration.no2,
    pm10 - concentration.pm10
  );
} // Fin de l'opérateur -

Concentration& Concentration::operator+=(Concentration const& concentration)
// Algorithme:
// 
{
  o3 += concentration.o3;
  so2 += concentration.so2;
  no2 += concentration.no2;
  pm10 += concentration.pm10;

  return *this;
} // Fin de l'opérateur -

Concentration& Concentration::operator/=(int n)
// Agorithme:
//
{
  o3 /= n;
  so2 /= n;
  no2 /= n;
  pm10 /= n;
  return *this;
} // Fin de l'opérateur /=

//-------------------------------------------- Constructeurs - destructeur

Concentration::Concentration()
// Algorithme :
//
{
  #ifdef MAP
    cout << "Appel au constructeur de <Position>" << endl;
  #endif
  o3 = 0.0;
  so2 = 0.0;
  no2 = 0.0;
  pm10 = 0.0;
} //----- Fin de Concentration


Concentration::Concentration(double pO3, double pSo2, double pNo2, double pPm10) :
o3(pO3),
so2(pSo2),
no2(pNo2),
pm10(pPm10)
// Algorithme:
//
{

} // ----- Fin de Concentration


Concentration::~Concentration ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Concentration>" << endl;
#endif
} //----- Fin de ~Position


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées