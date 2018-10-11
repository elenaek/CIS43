#include "stdafx.h"
#include "Final.h"


vector<string> getActDb(string fName)
{
	ifstream inFile;
	char buffer[100];
	static int sizeOfDb = 0;
	vector<string> actDb;
	while (! inFile.eof())
	{
		inFile.getline(buffer,100);
		
		sizeOfDb++;
		actDb.resize(sizeOfDb);


	}

}