/*****************************************************************//**
 * \file   Password.h
 * \brief  Header file for password authentication
 *
 * \author Stanley Owen
 * \date   2025/4/17
 *********************************************************************/
#pragma once

#include <iostream>

namespace Authenticate
{
	void inputPassword();	   // Asks the user to input their password
	std::string getPassword(); // Returns the password entered by the user
}
