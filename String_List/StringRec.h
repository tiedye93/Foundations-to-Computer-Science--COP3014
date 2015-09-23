#pragma once

#include <string>

using namespace std;



class StringRec
{
public:
	bool lessThan(StringRec otherString);  // a.lessThan(b)
	bool operator <(StringRec otherString);// a<b
	friend class BunchOfStrings;
	friend bool compareByAuthor(StringRec &, StringRec &);
	friend bool compareByName(StringRec &, StringRec &);
private:
	string data;
	unsigned int id;
	bool isDeleted;
};
