/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : $23/05/2023$
    copyright            : (C) $2023$ par $AirWatcher$
    e-mail               : $mathieu.habran@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <string>
using namespace std;

//------------------------------------------------------ Include personnel

#include "Sensor.h"
#include "Position.h"

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur


Sensor::Sensor(string id, double latitude, double longitude)
: id(id), position(Position(latitude, longitude))
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
#endif
} //----- Fin de Sensor

Sensor::~Sensor()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Sensor>" << endl;
#endif
} //----- Fin de ~Sensor

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées