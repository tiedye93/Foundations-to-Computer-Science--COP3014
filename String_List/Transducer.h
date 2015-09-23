
#pragma once

#include <string>
#include "BunchOfStrings.h"

using namespace std;




class Transducer
{
public:
	string transduce(string command);
private:
	//Add main functional object here 
	BunchOfStrings BunchOfStrings;
};