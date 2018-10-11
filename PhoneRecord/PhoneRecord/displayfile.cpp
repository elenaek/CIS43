#include "stdafx.h"
#include "PhoneRecord.h"
#include <iostream>
#include <fstream>
using namespace std;

int displayFile(char *txtFile)
{
    ifstream input_file (txtFile);
    char buff[80];


    if (!input_file)
    {
        cerr << "Unable to open " << txtFile << endl;
        return -1;
    }

    while (!input_file.eof())
    {
        input_file.getline(buff,80);
        cout << buff << endl;
    }
	return 0;
}
