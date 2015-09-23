#pragma once
#include <string>
#include <vector>
using namespace std;

class Patron
{
public:
	bool lessThan(Patron otherPatron);
	bool operator <(Patron otherPatron);
	friend class Library;
	friend bool compareByPatron(Patron &, Patron &);
private:
	string name;
	string phone_number;
	string email; 
	unsigned int id;
	bool isRemoved; 
	vector<int> hasCheckedOut;
};