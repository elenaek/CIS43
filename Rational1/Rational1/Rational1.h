#ifndef RATIONAL_H // if this compiler macro is not defined
#define RATIONAL_H // then define it so this file will not be processed again
#include <iostream>
#include <string>
using namespace std;
class Rational
{
private: // can't be seen by any other file - hide class data
int denominator; // hidden data for denominator
int numerator; // hidden data for numerator
void setRational (int n, int d) // helper function
{
numerator = n;
denominator = d;
if ( denominator<0 ) // if denominator is neg, multiply num and denom by -1
{
numerator = -numerator; // fix sign of numerator +/-
denominator = -denominator; // denominator always +
}
}



int GCD(int v1, int v2)
{
if (v2==0) return v1;
else return GCD (v2, v1%v2);
}



public: // can be seen by other files
// declare a constructor - called when an object is created
// a constructor is the same name as the class and has no return value
Rational createRational(string ab);



Rational (int n=0, int d=1) // constructor with default parameters
{
setRational(n,d); // set numerator and denominator, fix the sign
}



void display() 
{
cout << numerator << '/' << denominator;
}



void operator+= (Rational v2)
{
int n = numerator * v2.denominator + denominator * v2.numerator;
int d = denominator * v2.denominator;
numerator = n;
denominator = d;
}



Rational operator+(Rational v2)
{
int newDenom = denominator * v2.denominator;
int newNumerator = numerator*v2.denominator + v2.numerator * denominator;
int gcd = GCD(newNumerator, newDenom);
if (newDenom != 0)
{
newNumerator /= gcd;
newDenom /= gcd;
}
return Rational(newNumerator, newDenom); // creates temporary object
}

Rational operator-(Rational v2)
{
	int newDenom = denominator * v2.denominator;
	int newNumerator = numerator*v2.denominator - v2.numerator * denominator;
	int gcd = GCD(newNumerator, newDenom);
	if (newDenom !=0)
	{
		newNumerator /= gcd;
		newDenom /= gcd;
	}
	return Rational(newNumerator,newDenom);
}

Rational operator*(Rational v2)
{
	int newDenom = denominator * v2.denominator;
	int newNumerator = numerator*v2.numerator;
	return Rational(newNumerator,newDenom);
}

Rational operator/(Rational v2)
{
	int newDenom = denominator * v2.numerator;
	int newNumerator = numerator*v2.denominator;
	return Rational(newNumerator,newDenom);
}


operator double() const // convert Rational to double
{
return double(numerator) / double(denominator);
}


friend ostream &operator<< (ostream &out, Rational const &r)
{ 
out << r.numerator << '/' << r.denominator; 
return out; 
}
};
#endif

//HEADER------------------------------------------------------------------------------------------------------------------------------------------------------------------------