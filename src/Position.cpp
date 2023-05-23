/*************************************************************************
                           Position  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Position> (fichier Position.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <math.h>

//------------------------------------------------------ Include personnel
#include "Position.h"

//------------------------------------------------------------- Constantes
#define _USE_MATH_DEFINES

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
double Position::toRad( double degre )
// Algorithme :
//
{
    return degre/180.0 * M_PI;
} //----- Fin de toRad

double Position::distanceTo ( Position position )
// Algorithme :
//
{
    double distance;

    distance = sin(toRad(this->latitude)) * sin(toRad(position.latitude)) 
                + cos(toRad(this->latitude)) * cos(toRad(position.latitude)) 
                * cos(toRad(this->longitude - position.longitude));
    distance = 6371 * acos(distance);

    return distance;
} //----- Fin de distanceTo


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Position::Position ( double latitude, double longitude )
: latitude(latitude), longitude(longitude)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Position>" << endl;
#endif
} //----- Fin de Position


Position::~Position ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Position>" << endl;
#endif
} //----- Fin de ~Position


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

