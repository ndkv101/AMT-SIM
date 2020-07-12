//=============================================================================
// APPLICATION: atm simulator
// CLASS:		deposit.cpp
// PURPOSE:
// AUTHOR(S):	Vu Nguyen
//
// 4/28/2020 Created.
//=============================================================================
#include "bankdatabase.h"
#include "deposit.h"
#include <iostream>

using namespace std;

Deposit::Deposit(int accountNo, BankDatabase& db) : Transaction(accountNo, db)
{
}
//=============================================================================
void Deposit::run()
{
	BankDatabase& bankDatabase = getDatabase();

	double a;

	cout << "-------------------------------------------------------------" << endl;
	cout << "Enter the amount you want to deposit (Euro): ";
	cin >> a;
	setAmount(a);

	cout << "-------------------------------------------------------------" << endl;
	bankDatabase.credit(getAccountNumber(),a);
	cout << "\nTransaction Type:\tDeposit" << endl;
	cout << "\nAmount:\t\t\t" << a << endl;
	cout << "\nBalance:\t\t" << bankDatabase.getBalance(getAccountNumber()) << endl;
	cout << "-------------------------------------------------------------" << endl;
}
