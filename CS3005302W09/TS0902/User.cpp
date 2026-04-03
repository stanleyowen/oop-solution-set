/*****************************************************************//**
 * \file   User.cpp
 * \brief  Implementation of user authentication
 *
 * \author Stanley Owen
 * \date   2025/4/17
 *********************************************************************/
#include "User.h"

namespace
{
	std::string username;

	/**
	 * Validates if the username is valid by checking if it contains only 8 letters
	 *
	 * \return True if the username is valid, false otherwise
	 */
	bool isValid()
	{
		// Checks if the username has any non-letter characters
		for (int i = 0; i < username.length(); i++)
		{
			if (!std::isalpha(username[i]))
			{
				return false;
			}
		}

		// Checks if the username has exactly 8 letters
		if (username.length() == 8)
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
	// Asks the user to input their username until a valid one is provided
	void inputUserName()
	{
		do
		{
			std::cout << "Enter your username (8 letters only)" << std::endl;
			std::cin >> username;
		} while (!isValid());
	}

	/**
	 * Returns the username entered by the user
	 *
	 * \return The username entered by the user
	 */
	std::string getUserName()
	{
		return username;
	}
}
