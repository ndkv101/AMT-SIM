//=============================================================================
// APPLICATION: atm simulator
// CLASS:		balanceinquiry.cpp
// PURPOSE:
// AUTHOR(S):	Vu Nguyen
//
// 4/28/2020 Created.
//=============================================================================

#include "balanceinquiry.h"
#include "bankdatabase.h"
#include <iostream>

using namespace std;

BalanceInquiry::BalanceInquiry(int accountNumber, BankDatabase& db) : Transaction(accountNumber, db)
{

}
//=============================================================================
void BalanceInquiry::run()
{
	BankDatabase& bankDatabase = getDatabase();

	int balance = bankDatabase.getBalance(getAccountNumber());
	cout << "\n===========================================================\n" << endl;
	cout << "Your balance: ";
	cout << balance << endl;
	cout << "\n===========================================================" << endl;
}

