#pragma once
#ifndef SavingsAccount_H
#define SavingsAccount_H
class SavingsAccount
{

private:
	static double annualInterestRate;
	double savingsBalance;
public:
	SavingsAccount(void);
	~SavingsAccount(void);
	SavingsAccount(double a);
	void calculateMonthlyInterest();
	static void modifyInterestRate(double a)
	{
		annualInterestRate = a;
	};
	double getBalance();

};

#endif