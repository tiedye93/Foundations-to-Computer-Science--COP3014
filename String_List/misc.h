#pragma once

#include <string>
#include <vector>

using namespace std;


vector<string> tokenize(string com);
vector<string> tokenizeWithBlanks(string com);

void stringToLower(string & s);
void stringToUpper(string & s);

string padLeft(string s, char fill,  unsigned int size);
string padRight(string s,char fill,  unsigned int size);

string intToString(int x);
int stringToInt(string s);

string doubleToString(double d);
double stringToDouble(string s);



string stripLeadingBlanks(string s);
string stripTrailingBlanks(string s);

string intToDollarString(int x);
int dollarStringToInt(string s);

string randString(int numOfChars);
string randNumberString(int numOfChars);
int randInt(int lower,int upper);
