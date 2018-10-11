#include "stdafx.h"
#include "PhoneRecord.h"
#include <iostream>
#include <fstream>
using namespace std;

int addRecord(char *txtFile, int recordNo)
{
	char buff[80];
	char newLine[80];
	cout << "Enter new record. ";
	cin.getline(newLine, 80);
	//cin.ignore();
	ofstream out_file;
	out_file.open(txtFile, ios::app);
	out_file << newLine << endl;
	out_file.close();
	//cin.ignore();
	return 0;
}