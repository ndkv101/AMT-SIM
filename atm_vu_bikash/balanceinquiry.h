#if !defined(_BALANCEINQUIRY_H)
#define _BALANCEINQUIRY_H

//=============================================================================
// APPLICATION: atm simulator
// CLASS:		balanceinquiry.h
// PURPOSE:		Getting account balance
// AUTHOR(S):	Vu Nguyen
//
// 4/28/2020 Created.
//=============================================================================

#include "transaction.h"

class BalanceInquiry : public Transaction
{
public:

	BalanceInquiry(int accountNumber, BankDatabase& db);
	virtual void run();
};

#endif  //_BALANCEINQUIRY_H
