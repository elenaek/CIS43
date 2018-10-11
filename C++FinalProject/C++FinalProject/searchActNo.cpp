#include "stdafx.h"
#include "Final.h"



int searchActNo(string fName)
{
	string numToFind;
	cout << "Enter your Account No: ";
	cin >> numToFind;

	ifstream inFile(fName);
	char buffer[100];
	char const* toFind = numToFind.c_str(); 


	while(!inFile.eof())
	{
		inFile.getline(buffer,100);

		if(strstr(buffer,toFind) != NULL)
		{
			vector<string> found = parseString(buffer);
			cout << endl << "Account Name: " << found[1] << " " << endl << "Account Balance: $" << found[2] << endl;
			return 1;
		}

	}


	
	return -1;
}