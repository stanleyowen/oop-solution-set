/*****************************************************************//**
 * \file   main.cpp
 * \brief  Template for Absolute Value
 *
 * \author Stanley Owen
 * \date   2025/5/21
 *********************************************************************/
#include "Template.h"
#include <iostream>

using namespace std;

int main()
{
	// Declare variables
	int i1, i2;
	double d1, d2;
	char c1, c2;

	// Assign values to the variables
	i1 = 10;
	i2 = 20;
	// Call the absoluteValue function with integer parameters
	cout << "Absolute value of 10 - 20 is " << absoluteValue(i1, i2) << endl;

	// Assign values to the variables
	d1 = 5.5;
	d2 = 3.1;
	// Call the absoluteValue function with double parameters
	cout << "Absolute value of 5.5 - 3.1 is " << absoluteValue(d1, d2) << endl;

	// Assign values to the variables
	c1 = 'A';
	c2 = 'C';
	// Call the absoluteValue function with char parameters
	cout << "Absolute value of A - C is " << absoluteValue(c1, c2) << endl;

	return 0;
}