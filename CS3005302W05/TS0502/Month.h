/*****************************************************************//**
 * \file   Month.h
 * \brief  The header file of the Month class
 *
 * \author Stanley Owen
 * \date   2025/3/20
 *********************************************************************/
#ifndef Month_H
#define Month_H

#include <iostream>
#include <string>
#include <vector>

class Month
{
public:
	Month();									// Default constructor
	Month(int monthInt);						// Constructor with the month number
	Month(char first, char second, char third); // Constructor with the abbreviation of the month
	~Month();									// Destructor

	void inputInt();  // Input the month number
	void inputStr();  // Input the abbreviation of the month
	void outputInt(); // Output the month number
	void outputStr(); // Output the abbreviation of the month

	static std::vector<std::string> monthAbbreviation;

	Month nextMonth(); // Return the next month

private:
	int month;
};

#endif // Month_H