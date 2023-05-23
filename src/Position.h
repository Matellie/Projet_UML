/*************************************************************************
                           Position  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Position> (fichier Position.h) ----------------
#if ! defined ( POSITION_H )
#define POSITION_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Position>
//
//
//------------------------------------------------------------------------

class Position
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Attributs publics
double latitude;
double longitude;

//----------------------------------------------------- Méthodes publiques
    double toRad ( double degre );
    // Mode d'emploi :
    //
    // Contrat :
    //

    double distanceTo ( Position position );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Position ( double latitude, double longitude );
    // Mode d'emploi :
    //
    // Contrat :
    //

    ~Position ( );
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

