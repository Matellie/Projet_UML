/*************************************************************************
                           Data  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Analyse> (fichier Analyse.h) ----------------
#if ! defined ( ANALYSE_H )
#define ANALYSE_H

//--------------------------------------------------- Interfaces utilisées
#include <unordered_map>
#include <string>
using namespace std;

#include "Data.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Analyse>
//
//
//------------------------------------------------------------------------

class Analyse
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Attributs publics
Data* data;

//----------------------------------------------------- Méthodes publiques

int GetAirQualityFromConcentration(Concentration const& concentration);
  // Mode d'emploi:
  //
  // Contrat:
  //

int AirQualityAverage(Position center, double r, time_t begin, time_t end);
  // Mode d'emploi:
  //
  // Contrat:
  //

vector<string> SensorSimilarity(Measurement* refMeasure);
  // Mode d'emploi:
  //
  // Contrat:
  //

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Analyse( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    ~Analyse( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
  int GetIndexGas(double value, vector<int>& levels);
//----------------------------------------------------- Attributs protégés
  vector<int> OzoneLevels;
  vector<int> SulfurLevels;
  vector<int> NitrogenLevels;
  vector<int> ParticleLevels;
};

//-------------------------------- Autres définitions dépendantes de <Data>

#endif // DATA_H

