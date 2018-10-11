#include "stdafx.h"
#include "Final.h"


using namespace std;

vector<string> parseString(string str)
{
	vector<string> s(3);
	char cStr[300];
	for (int x = 0; x < 300;x++)
	{
		cStr[x] = ' ';
	}

	int const sizeOfStr = str.size();

	for (int i = 0; i< sizeOfStr;i++)
	{
		cStr[i] = str[i];
	}

	char *pointer;

	pointer = strtok(cStr, " \t");
	s[0] = pointer;
	pointer = strtok(NULL, " \t");
	s[1] = pointer;
	pointer = strtok(NULL, " \t");	
	s[2] = pointer;
	return s;
}