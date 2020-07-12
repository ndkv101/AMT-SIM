//=============================================================================
//	APPLICATION:	atm_vu_bikash
//	MODULE:			main
//	PURPOSE:
//	AUTHOR(S):		Vu Nguyen
//
//	4/28/2020 13:16:39	Created.
//=============================================================================
#include <iostream>
#include "account.h"
#include "card.h"
#include "bankdatabase.h"
#include "atm.h"
#include "transaction.h"
#include "balanceinquiry.h"
#include "deposit.h"
#include "withdrawal.h"

using namespace std;
//-----------------------------------------------------------------------------
//	THE MAIN ENTRY POINT TO THE PROGRAM.
//
//	input:	argc	The number of arguments of the programme.
//			argv	The vector of arguments of the programme.
//	return:	The code of the reason the process was terminated for.
//			The value defaults to zero.
//-----------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	cout << "\n===========================================================\n" << endl;
	cout << "\t\t\tFINAL PROJECT\t\t\t" << endl;
	cout << "\t\t\t_____________\t\t\t" << endl;
	cout << "\n\t\t\tATM SIMULATOR\t\t\t" << endl;
	cout << "\___________________________________________________________\n" << endl;
	cout << "\t\t\tDemo Account\t\t\t" << endl;
	cout << "\t\t\t_________________\t\t\t" << endl;
	cout << "\t\t\tAccount NO: 1001\t\t\t" << endl;
	cout << "\t\t\tCard NO   : 1234\t\t\t" << endl;
	cout << "\t\t\tPIN:      : 1991\t\t\t" << endl;
	cout << "\n===========================================================" << endl;

	/*
	-We will use a virtual account that we have created in Bank Database
	to test the functions of the ATM.

	-For testing purpose please use this account with details:
		Account Number: 1001
		Card Number:	1234
		PIN:			1991

	-For testing printing receipt function, we also created texts file 
	that you can check in the Source Files folder.
	*/
	
	ATM atm;
	atm.run();
	
	return 0;
}
