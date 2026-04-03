/*****************************************************************//**
 * \file   Password.cpp
 * \brief  Implementation of password authentication
 *
 * \author Stanley Owen
 * \date   2025/4/17
 *********************************************************************/
#include "Password.h"

namespace
{
	std::string password;

	/**
	 * Validates if the password is valid by checking if it contains at least 8 characters
	 * with at least one non-letter character
	 *
	 * \return True if the password is valid, false otherwise
	 */
	bool isValid()
	{
		bool containsNonLetter = false;

		// Checks if the password has any non-letter characters
		for (int i = 0; i < password.length(); i++)
		{
			if (!std::isalpha(password[i]))
			{
				containsNonLetter = true; // Set the flag to true if a non-letter character is found
				break;					  // Exit the loop early if a non-letter character is found
			}
		}

		// Checks if the password has at least 8 characters and at least one non-letter character
		if (password.length() > 7 && containsNonLetter)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
}

namespace Authenticate
{
	// Asks the user to input their password until a valid one is provided
	void inputPassword()
	{
		do
		{
			std::cout << "Enter your password (at least 8 characters " << "and at least one non-letter)" << std::endl;
			std::cin >> password;
		} while (!isValid());
	}

	/**
	 * Returns the password entered by the user
	 *
	 * \return The password entered by the user
	 */
	std::string getPassword()
	{
		return password;
	}
}
