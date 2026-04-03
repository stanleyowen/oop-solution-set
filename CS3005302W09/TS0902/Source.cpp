/*****************************************************************//**
 * \file   Source.cpp
 * \brief  Perform user and password validation using namespaces.
 *
 * \author Stanley Owen
 * \date   2025/4/17
 *********************************************************************/
#include <iostream>

#include "User.h"
#include "Password.h"

using namespace std;		  // Use the standard namespace to avoid prefixing std::
using namespace Authenticate; // Use the Authenticate namespace to avoid prefixing Authenticate::

int main()
{
	inputUserName(); // Ask the user to input their username
	inputPassword(); // Ask the user to input their password

	// Output the username and password entered by the user
	cout << "Your username is " << getUserName() << " and your password is: " << getPassword() << endl;

	return 0;
}
