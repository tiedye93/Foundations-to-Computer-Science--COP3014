#include "Transducer.h"
#include <vector>
#include "misc.h"

using namespace std;


//ADD This is a string.

string Transducer::transduce(string command)
{
	string result;
	vector<string> token = tokenize(command);
	if((token[0]=="HELP")||(token[0]=="H"))
	{
		result="Commands:\n";
		result+="-------------------\n";
		result += "\tADDSTRING (AS) <string>\n";
		result += "\tREMOVESTRING (RS) <string ID>\n";
		result += "\tWORDCOUNT (WC)\n";
		result += "\tWORDLIST (WL)\n";
		result+="\tSHOWSTRINGS (SS)\n";
		result+="\tTEST (T) <number of strings to add>\n";
		result+="\tHELP (H)\n";
		result+="\tQUIT (Q)\n";
	}
	
	else if ((token[0] == "ADDSTRING") || (token[0] == "AS"))
	{
		result = BunchOfStrings.addString(token[1]);
	}
	
	else if ((token[0] == "REMOVESTRING") || (token[0] == "RS"))
	{
		result = BunchOfStrings.removeString(stringToInt(token[1]));
	}
	
	else if ((token[0] == "WORDCOUNT") || (token[0] == "WC"))
	{
		result="There are "+intToString(BunchOfStrings.WordCount())+" words in the program.";
	}
	
	else if((token[0]=="SHOWSTRINGS")||(token[0]=="SS"))
	{
		result=BunchOfStrings.displayStrings();
	}

	else if ((token[0] == "WORDLIST") || (token[0] == "WL"))
	{
		result= (BunchOfStrings.WordList());
	}

	else if((token[0]=="QUIT")||(token[0]=="Q"))
	{
		result="YAY! You're done! Goodbye!";
	}

	else if(( token[ 0 ] == "TEST") || ( token[ 0 ] == "T"))
	{
		result = BunchOfStrings.test(stringToInt( token[ 1 ] ));
	}
	else
	{
		result="Unrecognized Command!!!";
	}
	return result;
}