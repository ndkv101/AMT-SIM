//=============================================================================
// APPLICATION: atm simulator
// CLASS:		card.cpp
// PURPOSE:
// AUTHOR(S):	Vu Nguyen
//
// 4/28/2020 Created.
//=============================================================================

#include "card.h"

using namespace std;

Card::Card()
{
}
//=============================================================================
Card::Card(int accNo, int cardNo, int pin) : accountNumber(accNo), cardNumber(cardNo), m_pin(pin)
{
}
//=============================================================================
bool Card::validatePin(int pin) const
{
	if (pin == m_pin)
	{
		return true;
	}
	else
	{
		return false;
	}
}

