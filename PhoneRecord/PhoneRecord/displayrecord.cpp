#include "stdafx.h"
#include "PhoneRecord.h"
#include <iostream>
#include <fstream>
using namespace std;

int displayRecord(char *txtFile, int recordNo)
{
    ifstream input_file (txtFile);
    char buff[80];

    if (!input_file)
    {
        cerr << "Unable to open " << txtFile << endl;
        return -1;
    }

    if (recordNo < 0)
    {
        cout << "Enter a record number: ";
        cin  >> recordNo;
		cin.ignore();		// igonre 'Enter' left over from cin
        input_file.seekg(recordNo * recordSize);
    }
    input_file.seekg(recordNo * recordSize);
    input_file.getline(buff,80);
    input_file.close();
    cout << buff << endl;

    return 0;
}