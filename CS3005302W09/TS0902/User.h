/*****************************************************************//**
 * \file   User.h
 * \brief  Header file for user authentication
 *
 * \author Stanley Owen
 * \date   2025/4/17
 *********************************************************************/
#pragma once

#include <iostream>

namespace Authenticate
{
	void inputUserName();	   // Asks the user to input their username
	std::string getUserName(); // Returns the username entered by the user
}
