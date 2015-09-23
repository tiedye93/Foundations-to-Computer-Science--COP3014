// ***********************************************************************
//
// (c) Copyright 2011 Dr. Thomas Fernandez
//
//  All rights reserved.
//
//  thomas@cse.fau.edu
//
// ***********************************************************************

#include "misc.h"
#include "stdio.h"
#include "stdlib.h"
#include <sstream>
using namespace std;



vector<string> tokenize(string com)
{
	istringstream is(com);
	vector<string> vs;
	string s;
	while(!is.eof())
	{
		if(vs.size()==0)
		{
			getline(is,s,' ');
		}
		else
		{
			getline(is,s,';');
		}
		vs.push_back(s);
	}
	return vs;
}




void stringToLower(string & s)
{
	for(unsigned int i=0;i<s.length();i++)
	{
		s[i]=tolower(s[i]);
	}
}

void stringToUpper(string & s)
{
	for(unsigned int i=0;i<s.length();i++)
	{
		s[i]=toupper(s[i]);
	}
}


string padLeft(string s,char fill, unsigned int size)
{
	while(s.length()<size)
	{
		s= fill + s;
	}
	return s;
}

string padRight(string s,char fill,  unsigned int size)
{
	while(s.length()<size)
	{
		s= s + fill;
	}
	return s;
}

//All of the following would work fine.
//The first two give warnings. Try them out and read the warnings.
//
//itoa(x,temp,10);
//_itoa(x,temp,10);
//_itoa_s(x,temp,255,10);
//
//The last one is "safe" because it's guaranteed to not go beyond 255 characters.
//In this case it can't happen but it would be safe even if temp was very small array as long as the third parameter was also appropriately small.
string intToString(int x)
{
	string result;
	char temp[256];
	//itoa(x,temp,10);
	//_itoa(x,temp,10);
	_itoa_s(x,temp,255,10);
	result=temp;
	return result;
}

string doubleToString(double d)
{
	ostringstream os;
	os<<d;
	return os.str();
}

double stringToDouble(string s)
{
	return atof(s.c_str());
}




int stringToInt(string s)
{
	return atoi(s.c_str());
}

int dollarStringToInt(string s)
{
	//string s1 = s.substr(0,s.length()-3);
	//string s2 = s.substr(s.length()-2);
	//string s3 = s1 + s2;
	//return stringToInt(s3);

	// better way
	string s1 = s.erase(s.length()-3,1);
	return stringToInt(s1);

}




string intToDollarString(int x)
{
	string result=intToString(x);
	result=padLeft(result,'0',3);
	result.insert(result.length()-2,".");
	return result;
}


//'A' is a char literal for the ascii value of a Capital A. (It's really just a one byte integer.)
//
//Adding a random value between 0 and 25 to the ascii value of A gives you the ascii value of a letter between A and Z.
//
//Play with it.
//
//cout<<(char)('A'+2)<<endl;
//
//prints a C on the screen.

string randString(int numOfChars)
{
	string result;
	for(int i=0;i<numOfChars;i++)
	{
		result+='A'+rand()%26;
	}
	return result;
}


string randNumberString(int numOfChars)
{
	string result;
	for(int i=0;i<numOfChars;i++)
	{
		result+='0'+rand()%10;
	}
	return result;
}

//int randInt(int lower,int upper)
//{
//	if(upper-lower<RAND_MAX)
//	{
//		return (rand()%(upper-lower))+lower;
//	}
//	else
//	{
//		int r=rand()*RAND_MAX+rand();
//		return (r % (upper-lower))+lower;
//	}
//}

int randInt(int lower,int upper)
{
	if(upper-lower<RAND_MAX)
	{
		int range = upper-lower; 
		int r = rand();  
		r= r % range;
		r= r+ lower;
		return r;
	}
	else
	{
		int r=rand()*RAND_MAX+rand();
		return (r % (upper-lower))+lower;
	}
}


string stripTrailingBlanks(string s)
{
	while((s.size()>0)&&(s[s.size()-1]==' '))
	{
		s=s.substr(0,s.size()-1);
	}
	return s;
}

string stripLeadingBlanks(string s)
{
	while((s.size()>0)&&(s[0]==' '))
	{
		s=s.substr(1);
	}	
	return s;
}
