/*****************************************************************//**
 * \file   Fraction.h
 * \brief  The header file for the Fraction class
 *
 * \author Stanley Owen
 * \date   2025/3/13
 *********************************************************************/
#ifndef Fraction_H
#define Fraction_H

#include <iostream>
#include <iomanip>

using namespace std;

class Fraction
{
private:
	int numerator;	 // The numerator of the fraction
	int denominator; // The denominator of the fraction

public:
	void setNumerator(int nu);	  // Set the numerator of the fraction
	void setDenominator(int de);  // Set the denominator of the fraction
	void getDouble();			  // Display the result as integer if possible otherwise as a double
	void outputReducedFraction(); // Display the reduced form of the fraction
};

#endif // Fraction_H