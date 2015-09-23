#pragma once
#include "Book.h"
#include "Patron.h"
#include <vector>
#include <map>
using namespace std;

class Library
{
public:
	Library();
	~Library();
	string displayBooks();
	string displayBooksByName();
	string displayBooksByAuthor();
	int bookCount();
	string addBook(string n, string a, string s, int idNumber=0, int chkedOut=0);
	string removeBook(int id);
	string clearBooks() 
	{ 
		lastBookIDUsed = 0; 
		vBook.clear(); 
		return "All books cleared.";
	}

	string addPatron(string n, string pN, string e, int patronID = 0, int hasCheckedOut = 0);
	string removePatron(int patronID);
	string displayPatrons();
	int patronCount();
	string displayPatronsByName();
	string clearPatrons()
	{
		lastPatronIDUsed = 0;
		vPatron.clear();
		return "All Patrons Cleared.";
	}

	string checkOut(int bookID, int patronID);
	string checkIn(int bookID);
	string checkOutReport_1();
	string checkOutReport_2();


private:
	map<int, int> bookIdIndex;
	vector<Book> vBook;
	int lastBookIDUsed = 0;

	map<int, int> patronIdIndex;
	vector<Patron> vPatron;
	int lastPatronIDUsed = 0;
};