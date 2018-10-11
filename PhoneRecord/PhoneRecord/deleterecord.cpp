#include "stdafx.h"
#include "PhoneRecord.h"
#include <iostream>
#include <fstream>
using namespace std;

int deleteRecord(char *txtFile, int recordNo)
{
    if (recordNo < 0)
    {
        cout << "Enter a record number: ";
        cin  >> recordNo;
    }

    ifstream input_file (txtFile, ios::in | ios::binary);
    ofstream output_file("tempFile.txt",  ios::out | ios::binary | ios::ate);
	ofstream backup_file("phony.bak", ios::out | ios::binary | ios::ate);
    char buff[80];

    if (!input_file)
    {
        cerr << "Unable to open " << txtFile << endl;
        return -1;
    }
    if (!output_file)
    {
        cerr << "Unable to open temp_file" << endl;
        return -1;
    }

    int fileRecordNo = 0;
    input_file.read(buff, recordSize);

    while (!input_file.eof())
    {
		backup_file.write(buff, recordSize);
        if (recordNo != fileRecordNo)
            output_file.write(buff, recordSize);
        fileRecordNo++;
        input_file.read(buff, recordSize);
    }

	input_file.close();
    output_file.close();
	remove(txtFile);
	rename("tempFile.txt", txtFile);
	

    return 0;
}
