#include <string>
using namespace std;

public enum Clearance{
	
	GOUV;
	LAMBDA;
	PROVIDER;
	
}

public class User{
	
	string id;
	boolean reliable;
	Vector<Sensor*> sensors;
	Clearance clearance;
	
	User(uint id);
	~User();
		
}