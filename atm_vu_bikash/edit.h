//=============================================================================
// APPLICATION: atm simulator
// CLASS: edit.h
// PURPOSE:
// AUTHOR(S): 
//
// 4/28/2020 Created.
//=============================================================================

#if !defined(_EDIT_H)
#define _EDIT_H


class Edit
{
public:
	int getAccountNumber();
	int getCardNumber();
	void run();
private:
	int accountNumber;
	int cardNumber;
};

#endif  //_EDIT_H
