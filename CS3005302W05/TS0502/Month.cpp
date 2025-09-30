/*****************************************************************//**
 * \file   Month.cpp
 * \brief  The implementation of the Month class
 *
 * \author Stanley Owen
 * \date   2025/3/20
 *********************************************************************/
#include "Month.h"

 // Initialize the static variable
std::vector<std::string> Month::monthAbbreviation = {
   "Jan", "Feb", "Mar",
   "Apr", "May", "Jun",
   "Jul", "Aug", "Sep",
   "Oct", "Nov", "Dec" };

// Default constructor which sets the month to 1
Month::Month() : month(1)
{
}

// Constructor with the month number
Month::Month(int monthInt) : month(monthInt)
{
	// Upon initialization check if the month is valid or not
	// If the month is not valid set the month to 1
	if (monthInt < 1 || monthInt > 12)
	{
		this->month = 1;
	}
}

// Constructor with the abbreviation of the month
Month::Month(char first, char second, char third)
{
	bool isFound = false;
	std::string combinedString;

	// Combine the abbreviation of the month
	combinedString += first;
	combinedString += second;
	combinedString += third;

	// Compare the abbreviation of the month with the monthAbbreviation vector
	for (int i = 0; i < monthAbbreviation.size(); i++)
	{
		if (combinedString == monthAbbreviation[i])
		{
			// If the abbreviation is found set the month to the index + 1
			this->month = i + 1;
			isFound = true;

			break;
		}
	}

	// If the abbreviation is not found set the month to 1
	if (!isFound) {
		this->month = 1;
	}
}

// Destructor
Month::~Month()
{
}

// Read the month number from the user
void Month::inputInt()
{
	int inputMonth;

	std::cin >> inputMonth;

	// Upon input check if the month is valid or not
	// If the month is not valid set the month to 1
	if (inputMonth < 1 || inputMonth > 12)
	{
		this->month = 1;
	}
	// If the month is valid set the month to the input
	else
	{
		this->month = inputMonth;
	}
}

// Read the abbreviation of the month from the user
void Month::inputStr()
{
	bool isFound = false;
	char first, second, third;
	std::string combinedString;

	std::cin >> first >> second >> third;

	// Combine the abbreviation of the month
	combinedString += first;
	combinedString += second;
	combinedString += third;

	// Compare the abbreviation of the month with the monthAbbreviation vector
	for (int i = 0; i < monthAbbreviation.size(); i++)
	{
		if (combinedString == monthAbbreviation[i])
		{
			// If the abbreviation is found set the month to the index + 1
			this->month = i + 1;
			isFound = true;

			break;
		}
	}

	// If the abbreviation is not found set the month to 1
	if (!isFound)
	{
		this->month = 1;
	}
}

// Output the month number
void Month::outputInt()
{
	std::cout << month;
}

// Output the abbreviation of the month
void Month::outputStr()
{
	std::cout << monthAbbreviation[month - 1];
}

// Return the next month as a Month object
Month Month::nextMonth()
{
	return Month(month + 1);
}
