#include <string>
using namespace std;

#include "Sensor.h"

Sensor(string id, double latitude, double longitude){
	id = identifiant;
	position = new Position(latitude, longitude);
}

~Sensor(){
	delete Position;
}