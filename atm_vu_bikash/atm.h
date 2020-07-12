#if !defined(_ATM_H)
#define _ATM_H

//=============================================================================
// APPLICATION: atm simulator
// CLASS:		atm.h
// PURPOSE:		The environment to implement other functions of the ATM
// AUTHOR(S):	Vu Nguyen
//
// 4/28/2020 Created.
//=============================================================================
#include "bankdatabase.h"

class Transaction;
using namespace std;

class ATM
{
public:
	enum {numOfOperation = 5};

	ATM();

	void			run();
	void			close();
	void			lock();
	void			authenticateUser();
	void			performSelection();
	int				displayMenu() const;
	int				displayEditMenu() const;
	void			edit(int selection);
	int				confirm();
	Transaction*	makeTransaction(int type);

private:
	int				index;
	double			operations[numOfOperation];
	int				counter;
	int				lim;
	bool			isExited;
	int				currentAccountNumber;
	int				currentCardNumber;
	bool			userAuthenticated;
	BankDatabase	bankDatabase;
};

#endif  //_ATM_H
