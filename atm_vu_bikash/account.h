#if !defined(_ACCOUNT_H)
#define _ACCOUNT_H

//=============================================================================
// APPLICATION: atm simulator
// CLASS:		account.h
// PURPOSE:		Storing customer information
// AUTHOR(S):	Vu Nguyen
//
// 4/28/2020 Created.
//=============================================================================

#include "card.h"

class Account
{
public:
	enum {arrlen = 20};

	Account();
	Account(int accNo, int cardNo, double balance);

	int		getBalance()		const { return m_balance; };
	int		getAccountNumber()	const { return accountNumber; };
	int		getCardNumber()		const { return cardNumber; };
	void	credit(double amount);
	void	debit(double amount);
	void	addCard();
	void	delCard();
	void	updateCard();

private:
	int		numOfCard;
	int		accountNumber;
	int		cardNumber;
	double	m_balance;
	Card*	cards[arrlen];
};

#endif  //_ACCOUNT_H
