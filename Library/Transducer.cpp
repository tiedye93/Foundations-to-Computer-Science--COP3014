#include "Transducer.h"
#include <vector>
#include "misc.h"
using namespace std;


//ADD This is a string.

string Transducer::transduce(string command)
{
	try
	{
		string result;
		vector<string> token = tokenize(command);
		if ((token[0] == "HELP") || (token[0] == "H"))
		{
			if (token.size() != 1) throw (string)"ERROR: Wrong number of parameters for this command.";
			result += "Book Commands:\n";
			result += "-------------------\n";
			result += "\tADDBOOK(AB) <title>;<author>;<subject>\n";
			result += "\tREMOVEBOOK(RB) <bookID>\n";
			result += "\tBOOKCOUNT(BC)\n";
			result += "\tCLEARBOOKS(CB)\n";
			result += "\tDISPLAYBOOKS(DB)\n";
			result += "\tDISPLAYBOOKSBYNAME(DBN)\n";
			result += "\tDISPLAYBOOKSBYAUTHOR(DBA)\n";
			result += "\tADDRANDBOOKS(ARB) <count>\n\n";
			result += "Patron Commands:\n";
			result += "-------------------\n";
			result += "\tADDPATRON(AP) <Name>;<Phone Number>;<email>\n";
			result += "\tREMOVEPATRON(RP) <PatronID>\n";
			result += "\tPATRONCOUNT(PC)\n";
			result += "\tCLEARPATRONS (CP) \n";
			result += "\tDISPLAYPATRONSBYNAME (DPN)\n";
			result += "\tADDRANDPATRONS (ARP)<Count>\n";
			result += "General Commands:\n";
			result += "-------------------\n";
			result += "\tCHECKOUT (CO) <bookID>; <PatronID>\n";
			result += "\tCHECKIN (CI) <bookID>\n";
			result += "\tCHECKOUTREPORT1 (COR1)\n";
			result += "\tCHECKOUTREPORT2 (COR2)\n";
			result += "\tHELP(H)\n";
			result += "\tQUIT(Q)\n";
		}

		/*****Book Commands*******************************************************************************/

		else if ((token[0] == "ADDBOOK") || (token[0] == "AB"))
		{
			if (token.size() != 4) throw (string)"ERROR: Wrong number of parameters for this command.";
			result = library.addBook(token[1], token[2], token[3]);
		}
		else if ((token[0] == "ADDRANDBOOKS") || (token[0] == "ARB"))
		{
			if (token.size() != 2) throw (string)"ERROR: Wrong number of parameters for this command.";
			for (int i = 0; i < stringToInt(token[1]); i++)
			{
				library.addBook(randString(rand() % 5 + 12) , randNumberString(rand() % 5 + 11) , randString(rand() % 5 + 13) );
			}
			result = token[1] + " random books have been added.";
		}
		else if ((token[0] == "REMOVEBOOK") || (token[0] == "RB"))
		{
			if (token.size() != 2) throw (string)"ERROR: Wrong number of parameters for this command.";
			result = library.removeBook(stringToInt(token[1]));
		}
		else if ((token[0] == "BOOKCOUNT") || (token[0] == "BC"))
		{
			if (token.size() != 1) throw (string)"ERROR: Wrong number of parameters for this command.";
			result = "There are " + intToString(library.bookCount()) + " books in the library.";
		}
		else if ((token[0] == "DISPLAYBOOKS") || (token[0] == "DB"))
		{
			if (token.size() != 1) throw (string)"ERROR: Wrong number of parameters for this command.";
			result = library.displayBooks();
		}
		else if ((token[0] == "CLEARBOOKS") || (token[0] == "CB"))
		{
			if (token.size() != 1) throw (string)"ERROR: Wrong number of parameters for this command.";
			result = library.clearBooks();
		}
		else if ((token[0] == "DISPLAYBOOKSBYNAME") || (token[0] == "DBN"))
		{
			if (token.size() != 1) throw (string)"ERROR: Wrong number of parameters for this command.";
			result = library.displayBooksByName();
		}
		else if ((token[0] == "DISPLAYBOOKSBYAUTHOR") || (token[0] == "DBA"))
		{
			if (token.size() != 1) throw (string)"ERROR: Wrong number of parameters for this command.";
			result = library.displayBooksByAuthor();
		}

		/*****Patron Commands****************************************************************************************************************/

		else if ((token[0] == "ADDPATRON") || (token[0] == "AP"))
		{
			if (token.size() != 4) throw (string)"ERROR: Wrong number of parameters for this command.";
			result = library.addPatron(token[1], token[2], token[3]);
		}
		else if ((token[0] == "ADDRANDPATRONS") || (token[0] == "ARP"))
		{
			if (token.size() != 2) throw (string)"ERROR: Wrong number of parameters for this command.";
			for (int i = 0; i < stringToInt(token[1]); i++)
			{
				library.addPatron(randString(rand() % 5 + 12) , randString(rand() % 5 + 11) , randString(rand() % 5 + 13) );
			}
			result = token[1] + " random Patrons have been added.";
		}
		else if ((token[0] == "REMOVEPATRON") || (token[0] == "RP"))
		{
			if (token.size() != 2) throw (string)"ERROR: Wrong number of parameters for this command.";
			result = library.removePatron(stringToInt(token[1]));
		}
		else if ((token[0] == "PATRONCOUNT") || (token[0] == "PC"))
		{
			if (token.size() != 1) throw (string)"ERROR: Wrong number of parameters for this command.";
			result = "There are " + intToString(library.patronCount()) + " patrons that belong to this library.";
		}
		else if ((token[0] == "DISPLAYPATRONS") || (token[0] == "DP"))
		{
			if (token.size() != 1) throw (string)"ERROR: Wrong number of parameters for this command.";
			result = library.displayPatrons();
		}
		else if ((token[0] == "CLEARPATRONS") || (token[0] == "CP"))
		{
			if (token.size() != 1) throw (string)"ERROR: Wrong number of parameters for this command.";
			result = library.clearPatrons();
		}
		else if ((token[0] == "DISPLAYPATRONSBYNAME") || (token[0] == "DPN"))
		{
			if (token.size() != 1) throw (string)"ERROR: Wrong number of parameters for this command.";
			result = library.displayPatronsByName();
		}
		
		/*****General Commands***********************************************************************************************************/

		else if ((token[0] == "CHECKOUT") || (token[0] == "CO"))
		{
			if (token.size() != 3) throw (string)"ERROR: Wrong number of parameters for this command.";
			result = library.checkOut(stringToInt(token[1]), stringToInt(token[2]));
		}
		else if ((token[0] == "CHECKIN") || (token[0] == "CI"))
		{
			if (token.size() != 2) throw (string)"ERROR: Wrong number of parameters for this command.";
			result = library.checkIn(stringToInt(token[1]));
		}
		else if ((token[0] == "CHECKOUTREPORT1") || (token[0] == "COR1"))
		{
			if (token.size() != 1) throw (string)"ERROR: Wrong number of parameters for this command.";
			result = library.checkOutReport_1();
		}
		else if ((token[0] == "CHECKOUTREPORT2") || (token[0] == "COR2"))
		{
			if (token.size() != 1) throw (string)"ERROR: Wrong number of parameters for this command.";
			result = library.checkOutReport_2();
		}
		else if ((token[0] == "QUIT") || (token[0] == "Q"))
		{
			if (token.size() != 1) throw (string)"ERROR: Wrong number of parameters for this command.";
			result = "Goodbye.";
		}
		else
		{
			 throw (string)"ERROR: Unrecognized Command.";
		}
		return result;
	}
	catch (string s)
	{
		if (s == "FATAL ERROR") exit(999);
		return s;
	}
	catch (...)
	{
		return "Something went wrong but I don't know what!";
	}
}



