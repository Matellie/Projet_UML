
/*************************************************************************
                           Position  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Position> (fichier Position.h) ----------------
#if !defined( MEASUREMENT_H )
#define MEASUREMENT_H

//--------------------------------------------------- Interfaces utilisées

#include <time.h>

#include "Concentration.h"

class Sensor;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Measurement>
//
//
//------------------------------------------------------------------------

class Measurement
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Attributs publics
  Sensor* sensor;
  time_t timestamp;
  Concentration concentration;

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
  Measurement(Sensor* pSensor, time_t pTimestamp, Concentration pConcentration);
  // Mode d'emploi :
  //
  // Contrat :
  //

  ~Measurement();
  // Mode d'emploi :
  //
  // Contrat :
  //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Position>

#endif // POSITION_H