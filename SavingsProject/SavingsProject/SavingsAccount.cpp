#include "StdAfx.h"
#include "SavingsAccount.h"

double SavingsAccount::annualInterestRate;

SavingsAccount::SavingsAccount(void)
{

}


SavingsAccount::~SavingsAccount(void)
{
}

SavingsAccount::SavingsAccount(double a)
{
	savingsBalance = a;
}



void SavingsAccount::calculateMonthlyInterest()
{
	savingsBalance+=savingsBalance*(annualInterestRate/12);
}



double SavingsAccount::getBalance()
{
	return savingsBalance;
}