#include "stdafx.h"
#include "PhoneRecord.h"
#include <iostream>
using namespace std;

char *menuList[] =  {
    "0 = Exit",
    "1 = Display File",
    "2 = Display Record",
    "3 = Find Record",
    "4 = Update Record", 
    "5 = Add Record",
    "6 = Delete Record"
};

int menu()
{ 
    int menuCount = sizeof(menuList) / sizeof(char*);

    cout << endl;

    for (int i=0; i<menuCount; i++)
        cout << menuList[i] << endl;
    
    int Selection;
    cout << "? ";
    cin  >> Selection;
	cin.ignore();		// igonre 'Enter' left over from menu()
    return Selection;
}