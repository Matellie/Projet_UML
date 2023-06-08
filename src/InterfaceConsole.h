/*************************************************************************
                           InterfaceConsole  -  description
                             -------------------
    début                : $23/05/2023$
    copyright            : (C) $2023$ par $AirWatcher$
    e-mail               : $mathieu.habran@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <InterfaceConsole> (fichier InterfaceConsole.h) ----------------
#if !defined(InterfaceConsole_H)
#define InterfaceConsole_H

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "User.h"
#include "Analyse.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <InterfaceConsole>
//
//
//------------------------------------------------------------------------

class InterfaceConsole
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    void Start();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur

    InterfaceConsole();
    // Mode d'emploi :
    //
    // Contrat :
    //

    InterfaceConsole(const char *nomDossier);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~InterfaceConsole();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    enum Clearance
    {
        GOUV,
        PROVIDER,
        LAMBDA
    };
    //----------------------------------------------------- Méthodes protégées
    int readChoice(string invite, int max);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void analyseComparaisonCapteur();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void mainMenu();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void connectUser();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void actionMenu();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void analyseQualiteZone();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //----------------------------------------------------- Attributs protégés
    // string UserId;
    Clearance clearance;
    Analyse analyse;
};

//-------------------------------- Autres définitions dépendantes de <InterfaceConsole>

#endif // InterfaceConsole_H