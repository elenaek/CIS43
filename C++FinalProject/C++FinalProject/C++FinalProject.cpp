// C++FinalProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Final.h"



int _tmain(int argc, _TCHAR* argv[])
{
	bool fileValid = false;
			

	while (fileValid == false)
	{
		cout << "Enter the file name and extension. ";
		cin >> fName;

			if (checkFile(fName))
			{
				fileValid = true;
			}
			else
			{
				cout << "You must enter a valid file. " <<endl;
			}
	}


	while (fileValid == true)
	{
		switch (inputMenu())
		{
		case 1:

			if(searchActName(fName) == -1)
			{
				cout << "Name was not found in the database. " <<endl;
			}
			break;

		case 2:


			if(searchActNo(fName) == -1)
			{
				cout << "Account number was not found in the database. " <<endl;
			}
			break;

		case 3:
			displayDatabase(fName);
			break;

		case 4:
			exit(0);
		}


	}
	
	

	return 0;
}




