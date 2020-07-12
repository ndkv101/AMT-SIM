#if !defined(_WITHDRAWAL_H)
#define _WITHDRAWAL_H

//=============================================================================
// APPLICATION: atm simulator
// CLASS:		withdrawal.h
// PURPOSE:		Implement withdrawal functions
// AUTHOR(S):	Vu Nguyen
//
// 4/28/2020 Created.
//=============================================================================

#include "transaction.h"

class Withdrawal : public Transaction
{
public:

	Withdrawal(int accountNo, BankDatabase& db);
	virtual void run();
	
private:

};

#endif  //_WITHDRAWAL_H
