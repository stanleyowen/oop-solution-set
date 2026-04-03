/*****************************************************************//**
 * \file   Account.h
 * \brief  Header file for the Account class
 *
 * \author Stanley Owen
 * \date   2025/5/11
 *********************************************************************/
#pragma once

 // Exception classes for insufficient funds
class InsufficientFunds
{
};

// Exception class for negative deposits
class NegativeDeposit
{
};

class Account
{
private:
	double balance; // Current balance of the account

public:
	Account();						// Default constructor
	Account(double initialDeposit); // Constructor with initial deposit

	double getBalance();			// Returns the current balance
	double deposit(double amount);	// Returns balance after deposit or throws exception
	double withdraw(double amount); // Returns balance after withdrawal or throws exception
};