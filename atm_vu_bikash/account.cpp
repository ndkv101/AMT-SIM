//=============================================================================
// APPLICATION: atm simulator
// CLASS:		account.cpp
// PURPOSE:
// AUTHOR(S):	Vu Nguyen
//
// 4/28/2020 Created.
//=============================================================================

#include "account.h"
#include <string>
#include <iostream>

using namespace std;
enum {arrlen = 20};

Account::Account()
{
	numOfCard = 1;
}
//=============================================================================
Account::Account(int accNo, int cardNo, double balance) : accountNumber(accNo), cardNumber(cardNo), m_balance(balance)
{

}
//=============================================================================
void Account::credit(double amount)
{
	m_balance += amount;
}
//=============================================================================
void Account::debit(double amount)
{
	m_balance -= amount;
}
//=============================================================================
void Account::addCard()
{
	int accNo, cardNo, pin;
	cout << "\nENTER ACOUNT NUMBER: ";
	cin >> accNo;
	cout << "\nCREATE CARD NUMBER: ";
	cin >> cardNo;
	cout << "\nCREATE PIN: ";
	cin >> pin;

	Card* c = new Card(accNo, cardNo, pin);
	cards[cardNo] = c;
	numOfCard++;
}
//=============================================================================
void Account::delCard()
{
	int cardNo;

	cout << "\ENTER THE NUMBER OF CARD YOU WANT TO REMOVE: ";
	cin >> cardNo;
	for (int i = cardNo; i < cardNo; i++)
	{
		cards[i] = cards[i + 1];
	}
	numOfCard - 1;
}
//=============================================================================
void Account::updateCard()
{
	int accNo, cardNo, pin;
	
	cout << "\ENTER THE ACCOUNT NUMBER: ";
	cin >> accNo;
	cout << "\ENTER THE CARD NUMBER YOU WANT TO UPDATE: ";
	cin >> cardNo;
	cout << "NEW PIN: ";
	cin >> pin;
	Card* c = new Card(accNo, cardNo, pin);
	cards[accNo] = c;
}

