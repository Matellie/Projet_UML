/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : $23/05/2023$
    copyright            : (C) $2023$ par $AirWatcher$
    e-mail               : $mathieu.habran@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <Sensor> (fichier Sensor.h) -------------
#if ! defined ( SENSOR_H )
#define SENSOR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <vector>

#include "Measurement.h"
#include "Position.h"
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

//----------------------------------------------------- Méthodes publiques

	
	Sensor(string id, double latitude, double longitude);
	// Mode d'emploi :

	~Sensor();
	// Mode d'emploi :
	
	string id; 
	User* user;
	Position position;	
	vector <Measurement*> measurements;

}

//------------------------------- Autres définitions dépendantes de <Sensor>

#endif // SENSOR_H