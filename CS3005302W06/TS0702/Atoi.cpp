/*****************************************************************/ /**
* \file   Atoi.cpp
* \brief  The implementation file of the Atoi class
*
* \author Stanley Owen
* \date   2025/3/29
*********************************************************************/
#include "Atoi.h"

// Default constructor
// Initializes the string to be converted to an empty string.
Atoi::Atoi() : beTrans("")
{
}

/**
 * Sets the input string to be converted.
 *
 * \param inputString The string to be converted.
 */
Atoi::Atoi(std::string inputString) : beTrans(inputString)
{
}

/**
 * Set a new string.
 *
 * \param inputString The new string to be converted.
 */
void Atoi::SetString(std::string inputString)
{
	this->beTrans = inputString;
}

/**
 * Gets the string.
 *
 * \return The string to be converted.
 */
const std::string Atoi::GetString()
{
	return beTrans;
}

/**
 * Gets the length of the string.
 *
 * \return The length of the string.
 */
int Atoi::Length()
{
	// Omits the leading '-' sign for negative numbers.
	if (beTrans[0] == '-')
	{
		return beTrans.length() - 1;
	}
	else
	{
		return beTrans.length();
	}
}

/**
 * Checks if the string is a valid number.
 *
 * \return true if the string contains only digits and a leading '-'. Otherwise, returns false.
 */
bool Atoi::IsDigital()
{
	bool isDigit = true;

	// Check if the characters in the string are digits or a leading '-'.
	// Otherwise, set isDigit to false.
	for (int i = 0; i < beTrans.length(); i++)
	{
		if (beTrans[i] >= '0' && beTrans[i] <= '9' || beTrans[0] == '-')
		{
		}
		else
		{
			isDigit = false;
			break;
		}
	}

	return isDigit;
}

/**
 * Converts the string to an integer.
 *
 * \return The converted integer value.
 */
int Atoi::StringToInteger()
{
	int result = 0;
	bool isLeadingZero = true;

	// Check if the string is a valid number.
	if (IsDigital())
	{
		// Iterate through each character in the string.
		// If the character is not a leading zero or '-', convert it to an integer.
		// If the character is a leading zero, skip it.
		for (int i = 0; i < beTrans.length(); i++)
		{
			if (beTrans[i] != '-' && beTrans[i] != '0')
			{
				isLeadingZero = false;
			}

			if (!isLeadingZero)
			{
				result *= 10;
				result += beTrans[i] - '0';
			}
		}

		// If the character is '-', multiply the result by -1.
		if (beTrans[0] == '-')
		{
			result *= -1;
		}
	}

	return result;
}
