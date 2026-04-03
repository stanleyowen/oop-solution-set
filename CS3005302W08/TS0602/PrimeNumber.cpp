/*****************************************************************//**
 * \file   PrimeNumber.cpp
 * \brief  The implementation of the PrimeNumber class
 *
 * \author Stanley Owen
 * \date   2025/4/10
 *********************************************************************/
#include "PrimeNumber.h"

 // Default constructor
 // Initialize the prime number to 1
PrimeNumber::PrimeNumber() : value(1) {
};

/**
 * Initializes the prime number to the given value
 *
 * \param _value The value to initialize the prime number to
 */
PrimeNumber::PrimeNumber(int _value) : value(_value) {
};

/**
 * Gets the current value of the prime number
 *
 * \return The current value of the prime number
 */
int PrimeNumber::get()
{
	return value;
}

/**
 * Overloads the ++ operator to calculate the next prime number (similar to the prefix operator)
 *
 * \return The new value of the prime number after incrementing
 */
PrimeNumber& PrimeNumber::operator++()
{
	int temp = value; // Store the current value of the prime number

	// If the current value is 1, set the next prime number to 2
	if (value == 1)
	{
		temp = 2;
	}
	// If the current value is 2, set the next prime number to 3
	else if (value == 2)
	{
		temp = 3;
	}
	else
	{
		while (true)
		{
			bool isPrime = true;

			// Make the number odd if it is even
			temp += (temp % 2 == 0 ? 1 : 2);

			// Check if the number is prime by dividing it by all odd numbers up to half of the number
			for (int i = 3; i <= temp / 2; i += 2)
			{
				if (temp % i == 0)
				{
					isPrime = false; // Set isPrime to false if the number is divisible by i
					break;			 // Break the loop
				}
			}

			// If the loop completes without finding a divisor, the number is prime
			// Break the loop to avoid infinite loop
			if (isPrime)
			{
				break;
			}
		}
	}

	// Set the current value of the prime number to the next prime number
	this->value = temp;

	return *this;
};

/**
 * Overloads the ++ operator to calculate the next prime number (similar to the postfix operator)
 *
 * \return The old value of the prime number before incrementing to the next prime number
 */
PrimeNumber PrimeNumber::operator++(int)
{
	PrimeNumber old(*this); // Copy the current value of the prime number

	++(*this); // Increment the prime number to the next prime number

	return old; // Return the old value
};

/**
 * Overloads the -- operator to calculate the previous prime number (similar to the prefix operator)
 *
 * \return The new value of the prime number after decrementing
 */
PrimeNumber& PrimeNumber::operator--()
{
	int temp = value; // Store the current value of the prime number

	// If the current value is 1, set the previous prime number to 2
	if (value == 2)
	{
		temp = 1;
	}
	// If the current value is 3, set the previous prime number to 2
	else if (value == 3)
	{
		temp = 2;
	}
	else
	{
		while (true)
		{
			bool isPrime = true;

			// Make the number odd if it is even
			temp -= (temp % 2 == 0 ? 1 : 2);

			// Check if the number is prime by dividing it by all odd numbers up to half of the number
			for (int i = 3; i <= temp / 2; i += 2)
			{
				if (temp % i == 0)
				{
					isPrime = false; // Set isPrime to false if the number is divisible by i
					break;			 // Break the loop
				}
			}

			// If the loop completes without finding a divisor, the number is prime
			// Break the loop to avoid infinite loop
			if (isPrime)
			{
				break;
			}
		}
	}

	// Set the current value of the prime number to the previous prime number
	this->value = temp;

	return *this;
};

/**
 * Overloads the -- operator to calculate the previous prime number (similar to the postfix operator)
 *
 * \return The old value of the prime number before decrementing to the previous prime number
 */
PrimeNumber PrimeNumber::operator--(int)
{
	PrimeNumber old(*this); // Copy the current value of the prime number

	--(*this); // Decrement the prime number to the previous prime number

	return old; // Return the old value
};