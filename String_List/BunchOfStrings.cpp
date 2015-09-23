#include "BunchOfStrings.h"
#include "misc.h"
#include <algorithm>
#include <fstream>

using namespace std;


BunchOfStrings::BunchOfStrings()
{
	lastStringIDUsed=0;
}


string BunchOfStrings::addString(string n)
{
	StringRec newString;
	newString.data=n;
	newString.isDeleted = false;
	lastStringIDUsed++;
	newString.id=lastStringIDUsed;
	StringIDIndex[newString.id] = vStringRec.size();
	vStringRec.push_back(newString);
	return "String added.";
}

string BunchOfStrings::removeString(int id)
{
	vector<StringRec>:: iterator iter;

	iter = vStringRec.begin();
	while(iter!= vStringRec.end())
	{
		if((*iter).id == id)
		{
			vStringRec.erase(iter);
			return "String Removed.";
		}
		iter++;
	}

	return "ID not Found.";
}

int BunchOfStrings:: WordCount( )
{
	int count = 0;

	for( int i = 0; i!= vStringRec.size( ); i++)
		{

			count += tokenizeWithBlanks( vStringRec[ i ].data ).size( );
		}

	return count;
}



string BunchOfStrings::displayStrings()
{
	string result;
	result+=padRight(".",'.',7);
	result+=padRight("ID",'.',70)+ "\n";
	result+=padRight("",'-',77)+"\n";

	vector<StringRec>::iterator iter;

	iter = vStringRec.begin();

	while(iter!=vStringRec.end())
	{
		if (!(*iter).isDeleted)
		{
			result += padLeft(intToString((*iter).id), ' ', 8) + "  ";
			result += padRight( (*iter).data, ' ',20) +"\n";
		}
		iter++;
	}

	return result;
}

string BunchOfStrings:: WordList( )
{
	string wList = " ";
	vector <string> allWords;
	vector <string> vWords;

	for( unsigned int i = 0; i < vStringRec.size( ); i++)
	{
		vWords = tokenizeWithBlanks( vStringRec[ i ].data );

		for( unsigned int i = 0; i < vWords.size( ); i++)
		{
			allWords.push_back( vWords[ i ] );
		}

	}
	
	sort( allWords.begin( ),allWords.end( ) );

	for( unsigned int i = 0; i < allWords.size( ); i++)
	{
		wList +=allWords[ i ] + "\n";
	}

	return wList;
}


string BunchOfStrings:: test( int n )
{
	for( int i = 0; i < n; i++)
	{
		string s = randString( rand( )%50+20);
		
		for( int j = 0; j < 3; j++)
		{ 
			s [rand( )% s.length( )] = ' ';
		}
		
		addString( s );
	}
	
	return "Strings Added.";
}