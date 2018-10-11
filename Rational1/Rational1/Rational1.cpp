// Rational.cpp : Defines the entry point for the console application.
// Create a Rational class defination
// Rational(numerator, denominator)
//
#include "stdafx.h"
#include "Rational1.h" // double quotes = find file in project folder
#include <iostream> // angle brackets = find file in compiler folder
#include <string>
using namespace std;
//Rational createRational(string ab);

int _tmain(int argc, _TCHAR* argv[])
{


string one;
string two;
cout << "Please enter the first fraction to use (num/denom). ";
cin >> one;
cout << "Please enter the second fraction to use (num/denom). ";
cin >> two;
cout << endl;
Rational num2; // call constructor with zero arguments

Rational num3 = num3.createRational(one);
Rational num4 = num4.createRational(two);
num2 = num3 + num4; // num3 + num4
cout << "Addition: " << num3 << " + " << num4 << " = " << num2 << endl;
cout << "Addition Decimal Answer: " << double(num2) << endl;
cout << endl;
num2 = num3 - num4;
cout << "Subtraction: " << num3 << " - " << num4 << " = " << num2 << endl;
cout << "Subtraction Decimal Answer: " << double(num2) << endl;
cout << endl;
num2 = num3 * num4;
cout << "Multiplication: " << num3 << " * " << num4 << " = " << num2 << endl;
cout << "Multiplication Decimal Answer: " << double(num2) << endl;
cout<<endl;
num2 = num3/ num4;
cout << "Division: " << num3 << " / " << num4 << " = " << num2 << endl;
cout << "Division Decimal Answer: " << double(num2) << endl;
cout<<endl;
return 0;



}

Rational Rational::createRational(string ab)
{

	int const sizeOfAB = ab.size();
	char str[1000];

	for (int i = 0; i<sizeOfAB;i++)
	{
		str[i] = ab[i];	
	}

	char *point;
	string num;
	string den;

	point = strtok (str," /");
	num = point;
	point = strtok(NULL, " /");
	den = point;

	int numer = stoi(num);
	int denom = stoi(den);
	Rational result(numer,denom);
	return result;
}
//MAINCLASS------------------------------------------------------------------------------------------------------------------------------------------------------------