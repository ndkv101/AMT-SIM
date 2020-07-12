//=============================================================================
// APPLICATION: atm simulator
// CLASS:		bankdatabase.cpp
// PURPOSE:
// AUTHOR(S):	Vu Nguyen 
//
// 4/28/2020 Created.
//=============================================================================

#include "bankdatabase.h"

using namespace std;

BankDatabase::BankDatabase()
{
	// Creating account and card sample for testing in main file
	Account a1(1001, 1234, 5000);
	Card	c1(1001, 1234, 1991);
	
	accounts.push_back(a1);
	cards.push_back(c1);
	
}
//=============================================================================
// Return specific account number
Account* BankDatabase::getAccount(int accNo)
{
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (accounts[i].getAccountNumber() == accNo)
		{
			return &accounts[i];
		}

		return NULL;
	}
}
//=============================================================================
// Return specific card
Card* BankDatabase::getCard(int accNo, int cardNo)
{
	for (size_t i = 0; i < cards.size(); i++)
	{
		if (cards[i].getAccountNumber() == accNo && cards[i].getCardNumber() == cardNo)
		{
			return &cards[i];
		}

		return NULL;
	}
}
//=============================================================================
// Authenticate bank customer
bool BankDatabase::authenticateUser(int accNo, int cardNo, int pin)
{
	Card* const cardPtr = getCard(accNo, cardNo);

	if (cardPtr != NULL) return cardPtr->validatePin(pin);
	else
	{
		return false;
	}
}
//=============================================================================
int BankDatabase::getBalance(int accountNumber)
{
	Account* const accountPtr = getAccount(accountNumber);

	return accountPtr->getBalance();
}
//=============================================================================
void BankDatabase::credit(int accountNumber, double amount)
{
	Account* const accountPtr = getAccount(accountNumber);

	return accountPtr->credit(amount);
}
//=============================================================================
void BankDatabase::debit(int accountNumber, double amount)
{
	Account* const accountPtr = getAccount(accountNumber);

	return accountPtr->debit(amount);
}
