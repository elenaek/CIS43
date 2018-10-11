#include "stdafx.h"
#include "PhoneRecord.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

int findRecord(char *txtFile)
{
    ifstream input_file (txtFile);
    char buff[80];
    char searchString[80];
    int  recordNo = -1; // -1 = not found, -2 = multiple matches
    int  foundRecNo = -1;

    if (!input_file)
    {
        cerr << "Unable to open " << txtFile << endl;
        return -1;
    }

    cout << "Enter a search string: ";
    cin.getline(searchString,80);   // read from keyboard

    while (!input_file.eof())
    {
        input_file.getline(buff,80);
        recordNo++;     // keep track of the record number
        if ( strstr(buff, searchString) != NULL)
        {
            cout << setw(3) << recordNo << ": " << buff << endl;
            if (foundRecNo == -1)
                foundRecNo = recordNo;
            else 
                foundRecNo = -2;
        }
    }
    input_file.close();
	return foundRecNo;
}
