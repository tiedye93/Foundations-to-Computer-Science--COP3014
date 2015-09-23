#include "Library.h"
#include "Patron.h"
#include "misc.h"
#include <fstream>
#include <algorithm>
using namespace std;


Library::Library()
{
	ifstream fin("libBooks.txt");
	string inputLine;
	if (fin.fail())
	{
		lastBookIDUsed = 0;
	}
	getline(fin, inputLine);
	lastBookIDUsed = stringToInt(inputLine);
	while (!fin.eof())
	{
		getline(fin, inputLine);
		if ((!fin.eof()) && (inputLine.length() != 0))
		{
			vector<string> token = tokenize(inputLine);
			addBook(token[1], token[2], token[3], stringToInt(token[0]), stringToInt(token[4]));
		}
		else
		{
			break;
		}
	}
	fin.close();
}

Library::~Library()
{
	ofstream fout("libBooks.txt");
	fout << lastBookIDUsed << endl;

	vector<Book>::iterator iter;

	iter = vBook.begin();

	while (iter != vBook.end())
	{
		if (!(*iter).isDeleted)
		{
			fout << (*iter).id << " ";
			fout << (*iter).name << ";";
			fout << (*iter).author << ";";
			fout << (*iter).subject << ";";
			fout << (*iter).checkOutBy << endl;

		}
		iter++;
	}
	fout.close();
}

/*****Book Functions****************************************************************************************************************/

string Library::addBook(string n, string a, string s, int idNumber, int chkedOut)
{
	Book newBook;
	newBook.name = n;
	newBook.author = a;
	newBook.subject = s;
	if (idNumber == 0)
	{
		lastBookIDUsed++;
		newBook.id = lastBookIDUsed;
		newBook.checkOutBy = 0;
	}
	else
	{
		newBook.id = idNumber;
		newBook.checkOutBy = chkedOut;
	}
	newBook.isDeleted = false;

	bookIdIndex[newBook.id] = vBook.size();
	vBook.push_back(newBook);
	return "Book added.";
}

string Library::removeBook(int id)
{

	if (bookIdIndex.find(id) == bookIdIndex.end())
	{
		throw (string)"ERROR: Invalid book ID.";
	}
	if (vBook[bookIdIndex[id]].isDeleted)
	{
		throw (string)"WARNING: This book is already removed.";
	}

	vBook[bookIdIndex[id]].isDeleted = true;
	return vBook[bookIdIndex[id]].name + " is deleted.";
}



string Library::displayBooksByName()
{
	// sort vBooks by Name
	string result;
	sort(vBook.begin(), vBook.end(), compareByName);
	result = displayBooks();
	sort(vBook.begin(), vBook.end());
	return result;
}


string Library::displayBooksByAuthor()
{
	// sort vBooks by Author
	string result;
	sort(vBook.begin(), vBook.end(), compareByAuthor);
	result = displayBooks();
	sort(vBook.begin(), vBook.end());
	return result;
}

int Library::bookCount()
{
	int result = 0;
	vector<Book>::iterator iter;

	iter = vBook.begin();

	while (iter != vBook.end())
	{
		if (!(*iter).isDeleted)
		{
			result++;
		}
		iter++;
	}

	return result;
}


string Library::displayBooks()
{
	string result;
	result += padRight("Id", '.', 10);
	result += padRight("Name", '.', 20);
	result += padRight("Author", '.', 20);
	result += padRight("Subject", '.', 20) + "\n";
	result += padRight("", '-', 70) + "\n";

	vector<Book>::iterator iter;

	iter = vBook.begin();

	while (iter != vBook.end())
	{
		if (!(*iter).isDeleted)
		{
			result += padLeft(intToString((*iter).id), ' ', 8) + "  ";
			result += padRight((*iter).name, ' ', 20);
			result += padRight((*iter).author, ' ', 20);
			result += padRight((*iter).subject, ' ', 20) + "\n";
		}
		iter++;
	}

	return result;
}



/*****Patron Functions****************************************************************************************************************/

string Library::addPatron(string n, string pN, string e, int patronID, int hasCheckedOut)
{
	Patron newPatron;
	newPatron.name = n;
	newPatron.phone_number = pN;
	newPatron.email = e;
	if (patronID == 0)
	{
		lastPatronIDUsed++;
		newPatron.id = lastPatronIDUsed;
		//newPatron.hasCheckedOut = 0;
	}
	else
	{
		newPatron.id = patronID;
		//newPatron.hasCheckedOut = hasCheckedOut;
	}
	newPatron.isRemoved = false;

	patronIdIndex[newPatron.id] = vPatron.size();
	vPatron.push_back(newPatron);
	return "Patron has been added.";
}

string Library::removePatron(int id)
{

	if (patronIdIndex.find(id) == patronIdIndex.end())
	{
		throw (string)"ERROR: Invalid Patron ID.";
	}
	if (vPatron[patronIdIndex[id]].isRemoved)
	{
		throw (string)"WARNING: This patron has already been removed.";
	}

	vPatron[patronIdIndex[id]].isRemoved = true;
	return vPatron[patronIdIndex[id]].name + " has been deleted.";
}

int Library::patronCount()
{
	int result = 0;
	vector<Patron>::iterator iter;

	iter = vPatron.begin();

	while (iter != vPatron.end())
	{
		if (!(*iter).isRemoved)
		{
			result++;
		}
		iter++;
	}

	return result;
}

string Library::displayPatrons()
{
	string result;
	result += padRight("Id", '.', 10);
	result += padRight("Name", '.', 20);
	result += padRight("Phone Number", '.', 20);
	result += padRight("Email", '.', 20) + "\n";
	result += padRight("", '-', 70) + "\n";

	vector<Patron>::iterator iter;

	iter = vPatron.begin();

	while (iter != vPatron.end())
	{
		if (!(*iter).isRemoved)
		{
			result += padLeft(intToString((*iter).id), ' ', 8) + "  ";
			result += padRight((*iter).name, ' ', 20);
			result += padRight((*iter).phone_number, ' ', 20);
			result += padRight((*iter).email, ' ', 20) + "\n";
		}
		iter++;
	}
	return result;
}

string Library::displayPatronsByName()
{
	// sort vBooks by Name
	string result;
	sort(vPatron.begin(), vPatron.end(), compareByPatron);
	result = displayPatrons();
	sort(vPatron.begin(), vPatron.end());
	return result;
}

string Library::checkOut(int bookID, int patronID)
{
	if (bookIdIndex.find(bookID) == bookIdIndex.end())
	{
		throw(string) "ERROR: Invalid book ID.";
	}
	if (vBook[bookIdIndex[bookID]].isDeleted)
	{
		throw (string)"ERROR: This book has already been checked out.";
	}
	if (vPatron[patronIdIndex[patronID]].isRemoved)
	{
		throw (string)"ERROR: This patron has been removed.";
	}
	if (patronIdIndex.find(patronID) == patronIdIndex.end())
	{
		throw (string) "ERROR: Invalid patron ID.";
	} 
	else
	{
		vBook[bookIdIndex[bookID]].checkOutBy = patronID;

		vPatron[patronIdIndex[patronID]].hasCheckedOut.push_back(bookID);

		return vPatron[patronIdIndex[patronID]].name + " has checked out " + vBook[bookIdIndex[bookID]].name;
	}
}

string Library::checkIn(int bookID)
{
	int patronID;

	if (bookIdIndex.find(bookID) == bookIdIndex.end())
	{
		throw(string) "ERROR: Invalid book ID.";
	}
	if (vBook[bookIdIndex[bookID]].checkOutBy == 0)
	{
		throw (string)"ERROR: Book is already checked in.";
	}
	if (vPatron[patronIdIndex[patronID]].isRemoved)
	{
		throw (string)"ERROR: This patron has been removed thus making it impossible for them to return a book.";
	}
	else
	{
		patronID = vBook[bookIdIndex[bookID]].checkOutBy;
		vBook[bookIdIndex[bookID]].checkOutBy = 0;
		vPatron[patronIdIndex[patronID]].hasCheckedOut.clear();

		return vBook[bookIdIndex[bookID]].name + " has been checked in.";
	}
}

string Library::checkOutReport_1()
{
	string result;
	result += "\nCheck Out Report 1:\n";
	result += padRight("Book", '.', 20);
	result += padRight("Patron ID", '.', 20);
	result += padRight("Patron's Name", '.', 20);
	result += padRight("", '.', 10) + "\n";
	result += padRight("", '-', 70) + "\n";

	vector<Book>::iterator iter;

	iter = vBook.begin();
	int patronID;
	
	while (iter != vBook.end())
	{
		if ((*iter).checkOutBy)
		{
			patronID = (*iter).checkOutBy;
			result += padRight((*iter).name, ' ', 20);
			result += padRight(intToString((*iter).checkOutBy), ' ', 20);
			result += padRight(vPatron[patronIdIndex[patronID]].name, ' ', 20) + "\n";
		}
		iter++;
	}


	return result;
}

string Library::checkOutReport_2()
{
	string result;
	int i = 0;
	int bookID;

	result += "\nCheck Out Report 2:\n";
	result += padRight("Patron", '.', 28);
	result += padRight("Book ID", '.', 22);
	result += "\n";
	result += padRight("", '-', 50) + "\n";

	vector<Patron>::iterator iter;

	iter = vPatron.begin();

	while (iter != vPatron.end())
	{
		if (!(*iter).isRemoved)
		{

			//result += (*iter).name + "\n";
			while (i < (*iter).hasCheckedOut.size())
			{
				result += (*iter).name + "\n";
				bookID = (*iter).hasCheckedOut[i];
				result += "\t" +  padRight(vBook[bookIdIndex[bookID]].name, ' ', 20);
				result += padRight(intToString(vBook[bookIdIndex[bookID]].id), ' ', 15);
				result += "\n";
				i++;
			}
			i = 0;
				
		}
		iter++;
	}

	return result;

}

