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
#include <ostream>
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "InterfaceConsole.h"
#include "Analyse.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void InterfaceConsole::Start()
// Algorithme :
//
{
	mainMenu();
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

InterfaceConsole::InterfaceConsole()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <InterfaceConsole>" << endl;
#endif
} //----- Fin de InterfaceConsole

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
int InterfaceConsole::readChoice(string invite, int max)
{
	int choice = -1;
	while (choice < 0 || choice > max)
	{
		cout << invite << endl;
		cin >> choice;
	}
	return choice;
}

void InterfaceConsole::mainMenu()
{
	bool exit = false;
  switch (readChoice("Menu Air Watcher\n1:se connecter\n0: quitter", 1))
  {
  case 1:
    connectUser();
    break;

  case 0:
    exit = true;
    break;
  }

  if(exit)
    return;

  actionMenu();
}

void InterfaceConsole::actionMenu()
{
	bool exit = false;
	int max = 3;
  string s;
	string menu = "1: Obtenir la qualité de l'air moyenne dans une zone circulaire\n2: Obtenir la similarité des capteurs par rapport à un capteur";
	if (clearance == InterfaceConsole::Clearance::LAMBDA)
	{
		menu += "\n3: Consulter son nombre de points";
	}
	else
	{
		menu += "\n3: Obtenir l'impact d'un purificateur";
		if (clearance == InterfaceConsole::Clearance::GOUV)
		{
			menu += "\n4: Assurer qu'un capteur n'est pas défectueux";
			max = 4;
		}
	}
	while (!exit)
	{
		switch (readChoice(menu, max))
		{
		case 1:
			// TODO Qualite dans une zone
			break;

		case 2:
			analyseComparaisonCapteur();
			break;

		case 3:
			if (clearance == InterfaceConsole::Clearance::LAMBDA)
			{
				// TODO consulter points
			}
			else
			{
				// TODO impact purificateur
				cout << "cette fonctionnalite n'est pas implémentée" << endl;
			}
			break;

		case 4:
			// TODO verifier capteur
			cout << "cette fonctionnalite n'est pas implémentée" << endl;
			break;

		case 0:
			exit = true;
			break;
		}
	}
}

void InterfaceConsole::connectUser()
{
	switch (readChoice("what is your clearance ?\n1: gouvernement\n2: provider\n3: lambda", 3))
	{
	case 1:
		clearance = InterfaceConsole::Clearance::GOUV;
		break;

	case 2:
		clearance = InterfaceConsole::Clearance::PROVIDER;
		break;

	case 3:
		clearance = InterfaceConsole::Clearance::LAMBDA;
		break;

	default:
		break;
	}
	cout << "enter your id:" << endl;
	cin >> UserId;
}

void InterfaceConsole::analyseComparaisonCapteur(){
  string id, s;
  cout << "Quel est l'ID du capteur que vous voulez analyser?" << endl;
  cin >> id;
  getline(cin, s);
  auto itSensor = analyse.data->sensors.find(id);
  if(itSensor == analyse.data->sensors.end()){
    cout << "Capteur non trouvé. Essayez à nouveau." << endl;
    return;
  }

  Sensor* sensor = itSensor->second;

  cout << "Donnez la date de la mesure de référence (YYYY-MM-dd hh:mm:ss)" << endl;
  string dateString;
  struct tm tm;
  time_t timestamp;

  getline(cin, dateString);
  strptime(dateString.c_str(), "%Y-%m-%d %H:%M:%S", &tm);
  timestamp = mktime(&tm);

  auto itMeasure = sensor->measurements.find(timestamp);
  if(itMeasure == sensor->measurements.end()){
    cout << "Aucune mesure prise à l'instant donné" << endl;
    return;
  }

  vector<string> result = analyse.SensorSimilarity(itMeasure->second);
  for(auto s : result)
    cout << *(analyse.data->sensors[s]->measurements[timestamp]) << endl;
}