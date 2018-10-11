#include "stdafx.h"
#include "Final.h"



int searchActName(string fName)
{
	string nameToFind;
	cout << "Enter a name to search: ";
	cin >> nameToFind;

	ifstream inFile(fName);
	char buffer[100];
	char lBuffer[100];
	transform(nameToFind.begin(), nameToFind.end(), nameToFind.begin(), tolower);
	char const* toFind = nameToFind.c_str(); 


	while(!inFile.eof())
	{
		inFile.getline(buffer,80);

		for (int i = 0; i < 100; i++)
		{
			lBuffer[i] = tolower(buffer[i]);
		}



		if(strstr(lBuffer,toFind) != NULL)
		{
			vector<string> found = parseString(buffer);
			cout << endl << found[1] << "'s " << "Account Number: " << found[0] << endl;
			return 1;
		}
	}


	/*for (int i = 0; i < actNa.size(); i++)
	{
		cout << actNa[i] << endl;
		if (actNa[i] == nameToFind)
		{
			cout << endl << actNa[i] << "'s " << "Account Number: " << actBal[i] << endl;
		}
	}

	return -1;*/


}