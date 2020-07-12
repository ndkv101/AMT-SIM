#if !defined(_CARD_H)
#define _CARD_H

//=============================================================================
// APPLICATION: atm simulator
// CLASS:		card.h
// PURPOSE:		Storing customer's cards information
// AUTHOR(S):	Vu Nguyen
//
// 4/28/2020 Created.
//=============================================================================

class Card
{
public:

	Card();
	Card(int accNo, int cardNo, int pin);

	int		getAccountNumber()	const { return accountNumber; };
	int		getCardNumber()		const { return cardNumber; };
	int		getPin()			const { return m_pin; };
	bool	validatePin(int pin) const;
	
private:

	int		accountNumber;
	int		cardNumber;
	int		m_pin;
};

#endif  //_CARD_H
