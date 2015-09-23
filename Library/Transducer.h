
#pragma once

#include <string>
#include "Library.h"

using namespace std;




class Transducer
{
public:
	string transduce(string command);
private:
	//Add main functional object here 
	Library library;
};