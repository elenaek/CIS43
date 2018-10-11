#include "stdafx.h"
#include "PhoneRecord.h"
#include <iostream>
#include <fstream>
using namespace std;

int updateRecord(char *txtFile, int recordNo)
{
    ifstream input_file (txtFile, ios::in | ios::binary);
    char buff[80];
    char newRecord[80];

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
    // display the record to be updated
    input_file.seekg(recordNo * recordSize);
    input_file.getline(buff,80);
    input_file.close();
    cout << buff << endl;

    // read the new record from the keyboard
    cin.getline(newRecord, 80);
    while ( strlen(newRecord) != recordSize-2)
    {
        cout << "Incorrect record size" << endl;
        cout << buff << endl;
        cin.getline(newRecord, 80);
    }
    // append CR and LF on the end of the record
    newRecord[41] = 0x0D;   // CR
    newRecord[42] = 0x0A;   // LF
    newRecord[43] = 0x00;   // end-of-string

    // write the updated record back to the disk
    ofstream output_file;
    output_file.open(txtFile, ios::out | ios::in | ios::binary | ios::ate);
    if (!output_file)
    {
        cerr << "Unable to open for writing" << txtFile << endl;
        return -1;
    }
    // find the record on the disk
    output_file.seekp(recordNo * recordSize);
    output_file.write(newRecord, recordSize);
    output_file.close();    // close the file
    return 0;
}
