/*************************************************************************
                           Data  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Analyse> (fichier Analyse.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include "Measurement.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Analyse.h"
#include "CsvReader.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

int Analyse::GetAirQualityFromConcentration(Concentration const&concentration)
// Algorithme:
//
{
  int ans = 0;

  ans = max(ans, GetIndexGas(concentration.o3, OzoneLevels));
  ans = max(ans, GetIndexGas(concentration.so2, SulfurLevels));
  ans = max(ans, GetIndexGas(concentration.no2, NitrogenLevels));
  ans = max(ans, GetIndexGas(concentration.pm10, ParticleLevels));

  return ans;
}

int Analyse::AirQualityAverage(Position center, double r, time_t begin, time_t end)
// Algorithme:
//
{
  Concentration average;
  unsigned int count = 0;

  for(auto sensor : data->sensors){
    if(center.distanceTo(sensor.second->position)){
      auto endIterator = sensor.second->measurements.upper_bound(begin);
      for(auto measure = sensor.second->measurements.lower_bound(begin);
          measure != endIterator;
          measure++){
        count++;
        average += measure->second->concentration;
      }
    }
  }

  if(count == 0){
    throw(runtime_error("Il faut avoir au moins un capteur dans la zone étudiée"));
  }

  average /= count;

  return GetAirQualityFromConcentration(average);
}

vector<string> Analyse::SensorSimilarity(Measurement refMeasure)
// Algorithm:
//
{
  vector<pair<float, string>> scores;
  for(auto sensor : data->sensors){
    auto it = sensor.second->measurements.find(refMeasure.timestamp);
    // If the measurement was found
    if(it != sensor.second->measurements.end()){
      Measurement& measure = *(it->second);
      Concentration delta = measure.concentration - refMeasure.concentration;
      float myScore = delta.GetLengthSquared();
      scores.push_back({myScore, measure.sensor->id});
    }
  }

  sort(scores.begin(), scores.end());
  vector<string> ranking;
  for(auto score : scores){
    ranking.push_back(score.second);
  }

  return ranking;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Analyse::Analyse ( )
// Algorithme :
//
{
  // Valeurs utilisées par l'indice Atmo
  OzoneLevels = {29, 54, 79, 104, 129, 149, 179, 209, 239};
  SulfurLevels = {39, 79, 119, 159, 199, 249, 299, 399, 499};
  NitrogenLevels = {29, 54, 84, 109, 134, 164, 199, 274, 399};
  ParticleLevels = {6, 13, 20, 27, 34, 41, 49, 64, 79};
  
  data = CsvReader::readCsv();
#ifdef MAP
    cout << "Appel au constructeur de <Data>" << endl;
#endif
} //----- Fin de Data


Analyse::~Analyse ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Data>" << endl;
#endif
} //----- Fin de ~Data


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

int Analyse::GetIndexGas(double val, vector<int>& levels){
  int n = levels.size();
  if(val < levels[0])
    return 1;
  for(int i = 1; i < n; i++){
    if(val <= levels[i])
      return i+1;
  }
  return n;
}