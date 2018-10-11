#include "stdafx.h"
#include "Final.h"


bool checkFile(string fName)
{

	ifstream check(fName);
	if (! check)
	{
		return false;
	}


	return true;

}