#if !defined(_BANKDATABASE_H)
#define _BANKDATABASE_H

//=============================================================================
// APPLICATION: atm simulator
// CLASS:		bankdatabase.h
// PURPOSE:		Getting customer information via bank data base
// AUTHOR(S):	Vu Nguyen
//
// 4/28/2020 Created.
//=============================================================================
#include "account.h"
#include "card.h"
#include <vector>

using namespace std;

class BankDatabase
{
public:

	BankDatabase();

	bool		authenticateUser(int accNo, int cardNo, int pin);
	int			getBalance(int accNo);
	void		credit(int accNo, double amount);
	void		debit(int accNo, double amount);
	Card*		getCard(int accNo, int cardNo);
	Account*	getAccount(int accNo);

private:

	vector<Account> accounts;
	vector<Card>	cards;
};

#endif  //_BANKDATABASE_H
