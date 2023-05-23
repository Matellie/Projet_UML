
/*************************************************************************
                           Position  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Position> (fichier Position.h) ----------------
#if ! defined ( CONCENTRATION_H )
#define CONCENTRATION_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Concentration>
//
//
//------------------------------------------------------------------------

class Concentration
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Attributs publics
  double o3;
  double so2;
  double no2;
  double pm10;

//----------------------------------------------------- Méthodes publiques

double GetLengthSquared();
// Mode d'emploi :
//
// Contrat :
//

//------------------------------------------------- Surcharge d'opérateurs
Concentration operator-(Concentration const& concentration);
// Mode d'emploi :
//
// Contrat :
//

Concentration& operator/=(int n);
// Mode d'emploi :
//
// Contrat :
//


//-------------------------------------------- Constructeurs - destructeur
  Concentration();
  // Mode d'emploi :
  //
  // Contrat :
  //

  Concentration(double pO3, double pSo2, double pNo2, double pPm10);
  // Mode d'emploi :
  //
  // Contrat :
  //

  ~Concentration();
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