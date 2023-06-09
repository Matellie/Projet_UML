/*************************************************************************
						   User  -  description
							 -------------------
	début                : $DATE$
	copyright            : (C) $YEAR$ par $AUTHOR$
	e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <User> (fichier User.h) ----------------
#if !defined(USER_H)
#define USER_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <stdlib.h>
#include <vector>
#include <string>

class Sensor;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <User>
//
//
//------------------------------------------------------------------------

class User
{

//----------------------------------------------------------------- PUBLIC

public:

	//----------------------------------------------------- Attributs publics
	string id;
	bool reliable;
	vector<Sensor *> sensors;
	int points;

	//----------------------------------------------------- Méthodes publiques

	//------------------------------------------------- Surcharge d'opérateurs

	//-------------------------------------------- Constructeurs - destructeur
	User(string id);
	// Mode d'emploi :
	//
	// Contrat :
	//

	~User();
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <User>

#endif // USER_H
