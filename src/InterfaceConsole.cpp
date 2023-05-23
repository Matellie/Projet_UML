/*************************************************************************
                           InterfaceConsole  -  description
                             -------------------
    début                : $23/05/2023$
    copyright            : (C) $2023$ par $AirWatcher$
    e-mail               : $mathieu.habran@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <InterfaceConsole> (fichier InterfaceConsole.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "InterfaceConsole.h"
#include "User.h"
//#include "Analyser.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void InterfaceConsole::SetUser(User* u)
// Algorithme :
//
{
	user = u;
}

void InterfaceConsole::Start()
// Algorithme :
//
{
	if(user == NULL){
		cout << "user has not been set" << endl;
	}else{
		if(user->clearance == User::Clearance::LAMBDA){
			cout << "lambda" << endl;
		}else{
			cout << "gouv/provider" << endl;			
		}
	}
	
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

InterfaceConsole::InterfaceConsole()
// Algorithme :
//
{
	user = NULL;
#ifdef MAP
    cout << "Appel au constructeur de <InterfaceConsole>" << endl;
#endif
} //----- Fin de InterfaceConsole

InterfaceConsole::InterfaceConsole(User* u) : user(u)
// Algorithme :
//
{
	#ifdef MAP
    cout << "Appel à l'autre constructeur de <InterfaceConsole>" << endl;
	#endif
}


InterfaceConsole::~InterfaceConsole()
// Algorithme :
//
{
	
#ifdef MAP
    cout << "Appel au destructeur de <InterfaceConsole>" << endl;
#endif
} //----- Fin de ~InterfaceConsole


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

