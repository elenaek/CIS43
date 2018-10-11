#include "stdafx.h"
#include "Final.h"




void displayDatabase(string fName)
{
	ifstream inFile(fName);
	char buffer[100];


	while(!inFile.eof())
	{
		inFile.getline(buffer,100);
		cout << buffer << endl;
	}
}