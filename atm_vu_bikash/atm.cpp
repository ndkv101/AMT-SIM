//=============================================================================
// APPLICATION: atm simulator
// CLASS:		atm.cpp
// PURPOSE:
// AUTHOR(S):	Vu Nguyen
//
// 4/28/2020 Created.
//=============================================================================
#include "atm.h"
#include "transaction.h"
#include "balanceinquiry.h"
#include "withdrawal.h"
#include "deposit.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum Menu { BALANCE = 1, WITHDRAWAL, DEPOSIT, EDIT, EXIT};
enum Edit { ADD = 1, DELETE, UPDATE, CANCEL};

ATM::ATM() : userAuthenticated(false), currentAccountNumber(0), currentCardNumber(0), isExited(false), counter(0), lim(3), index(0)
{
	for (int i = 0; i < numOfOperation; i++) operations[i] = NULL;
}
//=============================================================================
void ATM::run()
{
	while (!isExited)
	{
		while (!userAuthenticated)
		{
			authenticateUser();
		}

		performSelection();
		userAuthenticated = false;
		currentAccountNumber = 0;
	}
}
//=============================================================================
void ATM::close()
{
	cout << "-----------------------------------------------------------" << endl;
	cout << "\t\tTHANK YOU FOR BANKING WITH US!" << endl;
	cout << "-----------------------------------------------------------\n\n" << endl;
}
//=============================================================================
void ATM::lock()
{
	cout << "\nYour account is locked and your card is hold.\nPlease contact your bank for assistance.\n" << endl;
}
//=============================================================================
void ATM::authenticateUser()
{
	int accNo;
	int cardNo;
	int pin;
	
	cout << "\n\tPLEASE ENTER ACCOUNT NUMBER:\t\ ";
	cin >> accNo;
	cout << "\n\tPLEASE ENTER CARD NUMBER:\t ";
	cin >> cardNo;
	cout << "\n\tPLEASE ENTER YOU PIN:\t\t ";
	cin >> pin;
	cout << "\n===========================================================" << endl;

	userAuthenticated = bankDatabase.authenticateUser(accNo, cardNo, pin);

	if (userAuthenticated)
	{
		currentAccountNumber = accNo;
	}
	else 
	{
		// Tracking on log in errors
		counter++;
		if (counter < lim) 
		{
			if (lim - counter != 1) {
				cout << "Your information is not correct. You have " << (lim - counter) << " tries remain!" << endl;
				cout << "------------------------------------------------------------" << endl;
			}
			else {
				cout << "Your information is not correct. You have " << (lim - counter) << " try remain!" << endl;
				cout << "------------------------------------------------------------" << endl;
			}
			
		}
		else
		{
			lock();
			userAuthenticated = true;
			isExited = true;
		}
			
	}	
}
//=============================================================================
void ATM::performSelection()
{
	Transaction* transactionPtr;
	Account* accountPtr;

	while (!isExited)
	{
		int selection = displayMenu();

		switch (selection)
		{
			case BALANCE:
				transactionPtr = makeTransaction(selection);
				transactionPtr->run();
				int io;

				if (operations[0])
				{
					cout << "\t\t\tPREVIOUS TRANSACTIONS: " << endl;
					cout << "------------------------------------------------------------" << endl;
					for (int i = 0; i < numOfOperation; i++) {
						if (operations[i] != NULL)
						{
							if (operations[i] > 0)
							{
								cout << "\nTransaction Type: Deposit,\t\tamount: " << operations[i] << endl;
							}
							else 
							{
								cout << "\nTransaction Type: Withdrawal,\t\tamount: " << -operations[i] << endl;
							}
						}
					}
					// Print out balance receipt

					io = confirm();
					if (io == 1) {
						ofstream myfile;
						myfile.open("balance_receipt.txt", ios::app);
						myfile << "------------------------------------------------------------" << endl;
						myfile << "\nAccount No:\t\t\t" << currentAccountNumber << endl;
						myfile << "\nYour balance:\t\t";
						myfile << bankDatabase.getBalance(currentAccountNumber) << endl;
						myfile << "\nPrevious transactions: \n" << endl;
						
						for (int i = 0; i < numOfOperation; i++) {
							if (operations[i] != NULL)
							{
								if (operations[i] > 0)
								{
									myfile << "Transaction Type:\tDeposit,\t\tamount: " << operations[i] << endl;
								}
								else
								{
									myfile << "Transaction Type:\tWithdrawal,\t\tamount: " << -operations[i] << endl;
								}
							}
						}
						myfile << "------------------------------------------------------------" << endl;
						myfile.close();
					}
				}
				
				delete transactionPtr;
				break;
			case WITHDRAWAL:
				transactionPtr = makeTransaction(selection);
				transactionPtr->run();
				if (index < numOfOperation) {
					operations[index] = -transactionPtr->getAmount();
					index++;
				}
				else
				{
					index = numOfOperation - 1;
					for (int i = 0; i < index; i++) {
						operations[i] = operations[i + 1];
					}
					operations[index] = -transactionPtr->getAmount();
				}
				// Print out a withdrawal receipt

				io = confirm();
				if (io == 1) {
					ofstream myfile;
					myfile.open("withdraw_receipt.txt", ios::app);
					myfile << "------------------------------------------------------------" << endl;
					myfile << "\nAccount No:\t\t\t\t\t" << currentAccountNumber << endl;
					myfile << "\nTransaction type:\t\t\tWithdrawal" << endl;
					myfile << "\nAmount:\t\t\t\t\t\t" << transactionPtr->getAmount() << endl;
					myfile << "\n------------------------------------------------------------" << endl;
					myfile.close();
				}
				delete transactionPtr;
				break;
			case DEPOSIT:
				transactionPtr = makeTransaction(selection);
				transactionPtr->run();
				if (index < numOfOperation) {
					operations[index] = transactionPtr->getAmount();
					index++;
				}
				else
				{
					index = numOfOperation -1;
					for (int i = 0; i < index; i++) {
						operations[i] = operations[i + 1];
					}
					operations[index] = transactionPtr->getAmount();
				}
				
				io = confirm();
				if (io == 1) {
					ofstream myfile;
					myfile.open("deposit_receipt.txt", ios::app);
					myfile << "------------------------------------------------------------" << endl;
					myfile << "\nAccount No:\t\t\t\t\t" << currentAccountNumber << endl;
					myfile << "\nTransaction type:\t\t\tDeposit" << endl;
					myfile << "\nAmount:\t\t\t\t\t\t" << transactionPtr->getAmount() << endl;
					myfile << "\n------------------------------------------------------------" << endl;
					myfile.close();
				}

				delete transactionPtr;
				break;
			case EDIT:
				edit(displayEditMenu());
				break;
			case EXIT:
				close();
				isExited = true;
				break;
			default:
				cout << "-------------------------------------------------------------" << endl;
				cout << "You entered an invalid selection. Please try again!" << endl;
				cout << "-------------------------------------------------------------" << endl;
				break;
		}
	}
}
//=============================================================================
int ATM::displayMenu() const
{
	int selection;
	cout << "-------------------------------------------------------------" << endl;
	cout << "\t\t\tMAIN MENU: " << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "\n[1] Check account's balance" << endl;
	cout << "\n[2] Withdraw cash" << endl;
	cout << "\n[3] Deposit money" << endl;
	cout << "\n[4] Edit account" << endl;
	cout << "\n[5] Exit" << endl;
	cout << "\nYour selection: ";

	cin >> selection;

	return selection;
}
//=============================================================================
int ATM::displayEditMenu() const
{
	int selection;

	cout << "\n===========================================================" << endl;
	cout << "\t\t\tEDIT YOUR INFO: " << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "\n[1] Add new card" << endl;
	cout << "\n[2] Delete a card" << endl;
	cout << "\n[3] Update new pin" << endl;
	cout << "\n[4] Cancel" << endl;
	cout << "\nYour selection: ";
	cin >> selection;
	cout << "\n===========================================================" << endl;

	return selection;
}
//=============================================================================
Transaction* ATM::makeTransaction(int type)
{
	Transaction* temp{};
	double a;
	switch (type)
	{
		case BALANCE:
			temp = new BalanceInquiry(currentAccountNumber, bankDatabase);
			break;
		case WITHDRAWAL:
			temp = new Withdrawal(currentAccountNumber, bankDatabase);
			break;
		case DEPOSIT:
			temp = new Deposit(currentAccountNumber, bankDatabase);
			break;
	}

	return temp;
}
//=============================================================================
void ATM::edit(int selection)
{
	Account* myAcc = bankDatabase.getAccount(currentAccountNumber);
	
	switch (selection)
	{
	case ADD:
		myAcc->addCard();
		cout << "------------------------------------------------------------" << endl;
		cout << "Your new card have been added!" << endl;
		cout << "------------------------------------------------------------" << endl;
		break;
	case DELETE:
		myAcc->delCard();
		cout << "------------------------------------------------------------" << endl;
		cout << "Your selected card have been removed" << endl;
		cout << "------------------------------------------------------------" << endl;
		break;
	case UPDATE:
		myAcc->updateCard();
		cout << "------------------------------------------------------------" << endl;
		cout << "Your selected card have been update!" << endl;
		cout << "------------------------------------------------------------" << endl;
		break;
	case CANCEL:
		performSelection();
		break;
	default:
		cout << "\nYou entered an invalid selection. Please try again!" << endl;
		edit(displayEditMenu());
		break;
	}
}
//=============================================================================
int ATM::confirm()
{
	bool confirmation = false;
	int selection;

	while (!confirmation)
	{
		cout << "--------------------------------------------------------------" << endl;
		cout << "Would you like to print out a receipt?" << endl
			<< "\n[1] Yes" << endl
			<< "\n[2] No" << endl;
		cout << "\nYour confirmation: ";
		cin >> selection;
		
		if (selection != 1 && selection != 2)
		{
			cout << "--------------------------------------------------------------" << endl;
			cout << "\nYou entered an invalid confirmation. Please try again!" << endl;
		}
		else
		{
			confirmation = true;
		}
	}

	return selection;

}


