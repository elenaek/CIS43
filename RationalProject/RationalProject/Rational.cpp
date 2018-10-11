// RationalProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "Rational.h"


int _tmain(int argc, _TCHAR* argv[])
{
double num1 = 1.5;
Rational num2; // call constructor with zero arguments
Rational num3(3,4);
Rational num4(2,3); // the constructor is called num3 = 4/3
cout << "num2 = " << endl; // display the Rational object (variable)
num2 = num3.operator+=(num4); // num3 + num4
cout << "num2 = " << num2 << endl;
num2 = num3 + num4; // num3 + num4
cout << "num2 = " << num2 << endl;
cout << "num2 = " << double(num2) << endl;
	return 0;
}

