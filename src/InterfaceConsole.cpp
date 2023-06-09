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
#include <time.h>

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

InterfaceConsole::InterfaceConsole(const char *nomDossier)
	: analyse(nomDossier)
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
	string s;
	while (choice < 0 || choice > max)
	{
		cout << endl
			 << invite << endl;
		cin >> choice;
		getline(cin, s);
	}
	return choice;
}

void InterfaceConsole::mainMenu()
{
	bool exit = false;
	while (!exit)
	{
		switch (readChoice("Menu Air Watcher\n1: se connecter\n0: quitter", 1))
		{
		case 1:
			connectUser();
			actionMenu();
			break;

		case 0:
			exit = true;
			break;
		}
	}
}

void InterfaceConsole::actionMenu()
{
	bool exit = false;
	int max = 3;
	string s;
	string menu = "Menu des actions\n1: Obtenir la qualité de l'air moyenne dans une zone circulaire\n2: Obtenir la similarité des capteurs par rapport à un capteur";
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
	menu += "\n0: Quitter";
	while (!exit)
	{
		switch (readChoice(menu, max))
		{
		case 1:
			analyseQualiteZone();
			break;

		case 2:
			analyseComparaisonCapteur();
			break;

		case 3:
			if (clearance == InterfaceConsole::Clearance::LAMBDA)
			{
				cout << "cette fonctionnalite n'est pas implémentée" << endl;
			}
			else
			{
				cout << "cette fonctionnalite n'est pas implémentée" << endl;
			}
			break;

		case 4:
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
	switch (readChoice("Quel est votre rôle ?\n1: gouvernement\n2: provider\n3: lambda", 3))
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
		clearance = InterfaceConsole::Clearance::LAMBDA;
		break;
	}
	// cout << "enter your id:" << endl;
	// cin >> UserId;
}

void InterfaceConsole::analyseComparaisonCapteur()
{
	string id, s;
	cout << "Quel est l'ID du capteur que vous voulez analyser?" << endl;
	cin >> id;
	getline(cin, s);
	auto itSensor = analyse.data->sensors.find(id);
	if (itSensor == analyse.data->sensors.end())
	{
		cout << "Capteur non trouvé. Essayez à nouveau." << endl;
		return;
	}

	Sensor *sensor = itSensor->second;

	cout << "Donnez la date de la mesure de référence (YYYY-MM-dd hh:mm:ss)" << endl;
	string dateString;
	struct tm tm;
	time_t timestamp;

	getline(cin, dateString);
	strptime(dateString.c_str(), "%Y-%m-%d %H:%M:%S", &tm);
	timestamp = mktime(&tm);

	auto itMeasure = sensor->measurements.find(timestamp);
	if (itMeasure == sensor->measurements.end())
	{
		cout << "Aucune mesure prise à l'instant donné" << endl;
		return;
	}

  clock_t t = clock();
	vector<string> result = analyse.SensorSimilarity(itMeasure->second);
  float d = ((double) (clock() - t)) / CLOCKS_PER_SEC;
  printf("Execution time = %.3fs\n\n", d);
	for (auto s : result)
		cout << *(analyse.data->sensors[s]->measurements[timestamp]) << endl;
}

void InterfaceConsole::analyseQualiteZone()
{
	string s;
	double lat, lon, rayon;
	cout << "coordonnées du centre de la zone" << endl;
	cout << "latitude: " << endl;
	cin >> lat;
	getline(cin, s);
	cout << "longitude: " << endl;
	cin >> lon;
	getline(cin, s);
	cout << "rayon: " << endl;
	cin >> rayon;
	getline(cin, s);

	string debutString;
	struct tm tm_debut;
	time_t debut;
	char d[50];
	cout << "date de début (YYYY-MM-dd hh:mm:ss):" << endl;
	getline(cin, debutString);
	strptime(debutString.c_str(), "%Y-%m-%d %H:%M:%S", &tm_debut);
	debut = mktime(&tm_debut);
	strftime(d, 50, "%d/%m/%Y à %H:%M:%S", &tm_debut);

	string finString;
	struct tm tm_fin;
	time_t fin;
	char f[50];
	cout << "date de fin (YYYY-MM-dd hh:mm:ss):" << endl;
	getline(cin, finString);
	strptime(finString.c_str(), "%Y-%m-%d %H:%M:%S", &tm_fin);
	fin = mktime(&tm_fin);
	strftime(f, 50, "%d/%m/%Y à %H:%M:%S", &tm_fin);

	cout << "analyse de la qualite de l'air moyenne dans un rayon de " << rayon << " autour de (" << lat << ';' << lon << ") entre le " << d << " et le " << f << endl;
	int result = analyse.AirQualityAverage(Position(lat, lon), rayon, debut, fin);
	if (result == -1)
	{
		cout << "l'analyse a échoué, il n'y a pas de mesures correspondant a votre recherche" << endl;
	}
	else
	{
		cout << "qualite de l'air moyenne: " << result << endl;
	}
}