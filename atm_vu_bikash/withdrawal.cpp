//=============================================================================
// APPLICATION: atm simulator
// CLASS:		withdrawal.cpp
// PURPOSE:
// AUTHOR(S):	Vu Nguyen
//
// 4/28/2020 Created.
//=============================================================================
#include "bankdatabase.h"
#include "withdrawal.h"
#include <iostream>

using namespace std;

Withdrawal::Withdrawal(int accountNo, BankDatabase& db) : Transaction(accountNo, db)
{
}
//=============================================================================
void Withdrawal::run()
{
	BankDatabase& bankDatabase = getDatabase();
	int balance = bankDatabase.getBalance(getAccountNumber());
	double a;
	cout << "-------------------------------------------------------------" << endl;
	cout << "Enter the amount you want to withdraw (Euro): ";
	cin >> a;
	setAmount(a);

	if (a > balance)
	{
		do
		{
			cout << "\nNot enough money in account." << endl;
			cout << "\nPlease enter another amount: ";
			cin >> a;
		} while (a > balance);
	}
	cout << "-------------------------------------------------------------" << endl;
	bankDatabase.debit(getAccountNumber(), a);
	cout << "\nTransaction Type:\tWithdrawal" << endl;
	cout << "\nAmount:\t\t\t" << a << endl;
	cout << "\nBalance:\t\t" << bankDatabase.getBalance(getAccountNumber()) << endl;
	cout << "-------------------------------------------------------------" << endl;
}
	

