// PhoneRecord.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PhoneRecord.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    int recordNumber = -1;   // -1 = not found or multiple records

    while (true)
    {
        switch ( menu() )
        {
        case 0:
            exit(0);
        case 1:
            displayFile(fileName);
            break;
        case 2:
            displayRecord(fileName, recordNumber);
            break;
        case 3: // find record
            recordNumber = findRecord(fileName);
            if (recordNumber == -1) cout << "Not found" << endl;
            break;
        case 4:
            updateRecord(fileName, recordNumber);
            break;
        case 5:
			addRecord(fileName, recordNumber);
            break;
        case 6:
            deleteRecord(fileName, recordNumber);
            break;
        }
    }

	return 0;
}



