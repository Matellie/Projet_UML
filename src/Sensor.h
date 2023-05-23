#include <string>
using namespace std;

public class Sensor{

	string id; 
	User* user;
	Position position;	
	Vector <Measurement*> measurements;
	
	Sensor(string id, double latitude, double longitude);
	~Sensor();

}