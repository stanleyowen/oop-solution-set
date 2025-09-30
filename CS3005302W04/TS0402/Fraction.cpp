/*****************************************************************//**
 * \file   Fraction.cpp
 * \brief  The implementation of the Fraction class
 *
 * \author Stanley Owen
 * \date   2025/3/13
 *********************************************************************/
#include "Fraction.h"

 /**
  * Set the numerator of the fraction
  *
  * \param nu The numerator of the fraction
  */
void Fraction::setNumerator(int nu)
{
	this->numerator = nu;
}

/**
 * Set the denominator of the fraction
 *
 * \param de The denominator of the fraction
 */
void Fraction::setDenominator(int de)
{
	this->denominator = de;
}

// Display the result as integer if possible otherwise as a double
void Fraction::getDouble()
{
	// Get the division result in decimal form
	double divisionResult = (double)numerator / denominator;
	// Get the integer part of the division result
	int roundDownResult = std::floor(divisionResult);

	// Check if the division result is a decimal by checking if the difference between
	// the division result and the integer part is greater than 0
	if (divisionResult - roundDownResult > 0)
	{
		// Requires 6 decimal places
		std::cout << std::setprecision(6) << std::fixed << divisionResult;
	}
	// If the division result does not have a decimal part then print the result as an integer
	else
	{
		std::cout << roundDownResult;
	}

	std::cout << "\n";
}

// Display the reduced form of the fraction
void Fraction::outputReducedFraction()
{
	int smallestNumber = numerator < denominator ? numerator : denominator,
		gcd = 1; // // Initialize the greatest common divisor to 1
	// Get the division result in decimal form
	double divisionResult = (double)numerator / denominator;
	// Get the integer part of the division result
	int roundDownResult = std::floor(divisionResult);
	bool isDecimal = false;

	// Check if the division result is a decimal by checking if the difference between
	// the division result and the integer part is greater than 0
	if (divisionResult - roundDownResult > 0)
	{
		isDecimal = true;
	}

	// If the result is in decimal form, then loop until the smallest number is smaller
	// than or equal to 1
	while (smallestNumber > 1 && isDecimal)
	{
		// If the smallest number is a factor of both numbers, assign the smallest number to
		// the greatest common divisor and break the loop
		if (numerator % smallestNumber == 0 && denominator % smallestNumber == 0)
		{
			gcd = smallestNumber;
			break;
		}

		smallestNumber--;
	}

	// If the result is in decimal form, print the reduced fraction
	if (isDecimal)
	{
		std::cout << numerator / gcd << "/" << denominator / gcd << "\n";
	}
	// Otherwise, print the fraction as an integer
	else
	{
		std::cout << roundDownResult << "\n";
	}
}