//=============================================================================
// APPLICATION: atm simulator
// CLASS:		transaction.cpp
// PURPOSE:
// AUTHOR(S):	Vu Nguyen
//
// 4/28/2020 Created.
//=============================================================================
#include "bankdatabase.h"
#include "transaction.h"

using namespace std;

Transaction::Transaction(int accountNo, BankDatabase& db) : accountNumber(accountNo), bankDatabase(db)
{

}

