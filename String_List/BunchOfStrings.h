#pragma once

#include "StringRec.h"
#include <vector>
#include <map>

using namespace std;

class BunchOfStrings
{
public:
	BunchOfStrings( );
	//~BunchOfStrings( );
	string addString( string n );
	string removeString( int id );
	string displayStrings( );
	string WordList();
	int WordCount( );
	string test( int n );
private:
	StringRec & GetWordbyID( int id);
	map<int, int> StringIDIndex;
	vector<StringRec> vStringRec;
	int lastStringIDUsed;
};