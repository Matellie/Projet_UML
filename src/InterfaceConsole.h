/*************************************************************************
                           InterfaceConsole  -  description
                             -------------------
    début                : $23/05/2023$
    copyright            : (C) $2023$ par $AirWatcher$
    e-mail               : $mathieu.habran@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <InterfaceConsole> (fichier InterfaceConsole.h) ----------------
#if ! defined ( InterfaceConsole_H )
#define InterfaceConsole_H

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "User.h"

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
	void SetUser(User* u);
	// Mode d'emploi :
    //
    // Contrat :
    //
	
	void Start();
	// Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur

    InterfaceConsole (User* u);
    // Mode d'emploi :
    //
    // Contrat :
    //
	
	InterfaceConsole ();
    // Mode d'emploi :
    //
    // Contrat :
    //
	
    virtual ~InterfaceConsole ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
User * user;

};

//-------------------------------- Autres définitions dépendantes de <InterfaceConsole>

#endif // InterfaceConsole_H

