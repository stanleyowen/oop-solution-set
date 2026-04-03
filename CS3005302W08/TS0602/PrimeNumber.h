/*****************************************************************//**
 * \file   PrimeNumber.h
 * \brief  The header file for the PrimeNumber class
 *
 * \author Stanley Owen
 * \date   2025/4/10
 *********************************************************************/
#pragma once

#include <iostream>

class PrimeNumber
{
private:
	int value; // The value of the prime number

public:
	PrimeNumber();			 // Default constructor
	PrimeNumber(int _value); // Constructor with given value

	int get(); // Get the current value of the prime number

	PrimeNumber& operator++();	 // Prefix increment operator to calculate the next prime number
	PrimeNumber operator++(int); // Postfix increment operator to calculate the next prime number
	PrimeNumber& operator--();	 // Prefix decrement operator to calculate the previous prime number
	PrimeNumber operator--(int); // Postfix decrement operator to calculate the previous prime number
};