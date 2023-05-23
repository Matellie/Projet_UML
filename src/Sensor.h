/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : $23/05/2023$
    copyright            : (C) $2023$ par $AirWatcher$
    e-mail               : $mathieu.habran@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <Sensor> (fichier Sensor.h) -------------
#if !defined( SENSOR_H )
#define SENSOR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <vector>

#include "Measurement.h"
#include "Position.h"
#include "User.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Sensor>
// desc
//------------------------------------------------------------------------

using namespace std;

class Sensor{
	
//----------------------------------------------------------------- PUBLIC

public:

	//----------------------------------------------------- Attributs publics
	string id; 
	User* user;
	Position position;	
	vector <Measurement*> measurements;

	//----------------------------------------------------- Méthodes publiques

	//------------------------------------------------- Surcharge d'opérateurs

	//-------------------------------------------- Constructeurs - destructeur
	Sensor(string id, double latitude, double longitude);
	// Mode d'emploi :
	//
	// Contrat :
	//

	~Sensor();
	// Mode d'emploi :
	//
	// Contrat :
	//
	
	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
};

//------------------------------- Autres définitions dépendantes de <Sensor>

#endif // SENSOR_H