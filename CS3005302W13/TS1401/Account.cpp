/*****************************************************************//**
 * \file   Account.cpp
 * \brief  Implementation of the Account class
 *
 * \author Stanley Owen
 * \date   2025/5/11
 *********************************************************************/
#include "Account.h"

 // Default constructor
 // Initializes balance to 0
Account::Account()
{
	balance = 0;
}

/**
 * Initializes the account with an initial deposit
 *
 * \param initialDeposit The initial deposit amount
 */
Account::Account(double initialDeposit)
{
	balance = initialDeposit;
}

/**
 * Gets the current balance of the account
 *
 * \return The current balance of the account
 */
double Account::getBalance()
{
	return balance;
}

/**
 * Deposits a specified amount into the account
 *
 * \param amount The amount to deposit
 * \return The new balance of the account or throws an exception
 */
double Account::deposit(double amount)
{
	// Check if the deposit amount is positive
	if (amount > 0)
	{
		balance += amount;
	}
	else
	{
		throw NegativeDeposit();
	}

	return balance;
}

/**
 * Withdraws a specified amount from the account
 *
 * \param amount The amount to withdraw
 * \return The new balance of the account or throws an exception
 */
double Account::withdraw(double amount)
{
	// Check if the withdrawal amount is valid and sufficient
	if ((amount > balance) || (amount < 0))
	{
		throw InsufficientFunds();
	}
	else
	{
		balance -= amount;
	}

	return balance;
}
