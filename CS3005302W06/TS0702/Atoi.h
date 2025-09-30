/*****************************************************************//**
 * \file   Atoi.h
 * \brief  The header file of the Atoi class
 *
 * \author Stanley Owen
 * \date   2025/3/29
 *********************************************************************/
#include <string>
#include <iostream>

using namespace std;

class Atoi
{
private:
	string beTrans; // The string to be converted

public:
	Atoi();			// Default constructor
	Atoi(string s); // Constructor with a string parameter

	void SetString(string s); // Set a new string to be converted
	const string GetString(); // Get the string
	int Length();			  // Get the length of the string
	bool IsDigital();		  // Check if the string is a valid number
	int StringToInteger();	  // Convert the string to an integer
};