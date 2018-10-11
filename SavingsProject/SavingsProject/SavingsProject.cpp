// SavingsProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SavingsAccount.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	SavingsAccount saver1(2000.00);
	SavingsAccount saver2(3000.00);
	saver1.modifyInterestRate(0.3);
	
	saver1.calculateMonthlyInterest();
	saver2.calculateMonthlyInterest();

	cout <<"Saver 1: " << saver1.getBalance() << endl;
	cout <<"Saver 2: " << saver2.getBalance() << endl;
	cout <<endl;
	saver1.modifyInterestRate(0.4);

	saver1.calculateMonthlyInterest();
	saver2.calculateMonthlyInterest();

	cout <<"Saver 1: " << saver1.getBalance() << endl;
	cout <<"Saver 2: " << saver2.getBalance() << endl;

	return 0;
}

