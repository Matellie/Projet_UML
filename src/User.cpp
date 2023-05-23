#include <string>
using namespace std;

#include "User.h"

User(string identifiant, Clearance cl){
	id = identifiant;
	reliable = true;
	clearance = cl;
}

~User(){
	
	//nothing happens here 
	
}
