/*****************************************************************//**
 * \file   main.cpp
 * \brief  Throws exceptions for negative deposits and
 *		   insufficient funds
 *
 * \author Stanley Owen
 * \date   2025/5/11
 *********************************************************************/
#include <iostream>
#include "Account.h"

int main()
{
	Account a(100); // create an account with initial balance of 100

	try
	{
		std::cout << "Depositing 50" << std::endl;
		std::cout << "New balance: " << a.deposit(50) << std::endl; // Deposit 50
		std::cout << "Withdraw 25" << std::endl;
		std::cout << "New balance: " << a.withdraw(25) << std::endl; // Withdraw 25
		std::cout << "Withdraw 250" << std::endl;
		std::cout << "New balance: " << a.withdraw(250) << std::endl; // Withdraw 250
	}
	catch (InsufficientFunds)
	{
		// Display error message if insufficient funds
		std::cout << "Not enough money to withdraw that amount." << std::endl;
	}
	catch (NegativeDeposit)
	{
		// Display error message if negative deposit
		std::cout << "You may only deposit a positive amount." << std::endl;
	}

	char wait;

	// Wait for user input before exiting
	std::cout << "Enter a character to exit" << std::endl;
	std::cin >> wait;

	return 0;
}