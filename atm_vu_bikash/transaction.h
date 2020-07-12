#if !defined(_TRANSACTION_H)
#define _TRANSACTION_H

//=============================================================================
// APPLICATION:	atm simulator
// CLASS:		transaction.h
// PURPOSE:		Common class to hold all the inheritance methods of transaction
// AUTHOR(S):	Vu Nguyen
//
// 4/28/2020 Created.
//=============================================================================
#include "bankdatabase.h"


class Transaction
{
public:

	Transaction(int accountNo, BankDatabase& db);
	virtual ~Transaction() {};

	int				getAccountNumber()	const { return accountNumber; };
	BankDatabase&	getDatabase()		const { return bankDatabase; };
	
	virtual void	run() = 0;
	double			getAmount() const { return amount; };
	void			setAmount(double a) { amount = a; };

private:

	int				accountNumber;
	double			amount;
	BankDatabase&	bankDatabase;
	
};

#endif  //_TRANSACTION_H
