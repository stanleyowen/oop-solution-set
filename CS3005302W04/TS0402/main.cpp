/*****************************************************************//**
 * \file   main.cpp
 * \brief  Displaying the reduced form of a fraction
 *
 * \author Stanley Owen
 * \date   2025/3/13
 *********************************************************************/
#include <iostream>
#include "Fraction.h" // Include the header file

using namespace std;

int main()
{
	Fraction f1, f2; // Create two fraction objects

	f1.setNumerator(4);			// Set the numerator of the first fraction to 4
	f1.setDenominator(2);		// Set the denominator of the first fraction to 2
	f1.getDouble();				// Display the result as integer if possible otherwise as a double
	f1.outputReducedFraction(); // Display the reduced form of the first fraction

	f2.setNumerator(29);		// Set the numerator of the second fraction to 29
	f2.setDenominator(13);		// Set the denominator of the second fraction to 13
	f2.getDouble();				// Display the result as integer if possible otherwise as a double
	f2.outputReducedFraction(); // Display the reduced form of the second fraction

	return 0;
}