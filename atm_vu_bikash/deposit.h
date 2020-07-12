#if !defined(_DEPOSIT_H)
#define _DEPOSIT_H

//=============================================================================
// APPLICATION: atm simulator
// CLASS:		deposit.h
// PURPOSE:		Implement deposit functions
// AUTHOR(S):	Vu Nguyen
//
// 4/28/2020 Created.
//=============================================================================
#include "transaction.h"



class Deposit : public Transaction
{
public:
	Deposit(int accountNo, BankDatabase& db);
	virtual void run();

private:

};

#endif  //_DEPOSIT_H
