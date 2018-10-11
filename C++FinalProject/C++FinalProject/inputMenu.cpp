#include "stdafx.h"
#include "Final.h"

char *menu[] = {
		"1: Search Name",
		"2: Search Account Number",
		"3: Display Database",
		"4: Exit",
	};

int inputMenu()
{
	int inNum;
	int menuSize = sizeof(menu) / sizeof(char*);
	cout <<endl;

	for (int i = 0; i < menuSize; i++)
	{
		cout << menu[i] <<endl;
	}

	cout << endl << "Type in a number corresponding with the action you wish to take. ";
	cin >> inNum;

	return inNum;

}