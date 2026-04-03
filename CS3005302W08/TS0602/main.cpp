/*****************************************************************//**
 * \file   main.cpp
 * \brief  Calculates the current, next, or previous of a prime
 *		   number
 *
 * \author Stanley Owen
 * \date   2025/4/10
 *********************************************************************/
#include "PrimeNumber.h"
#include <iostream>

using namespace std;

int main()
{
	PrimeNumber p1(2), p2(13); // Set 2 and 13 as prime numbers to p1 and p2 respectively
	PrimeNumber a = p1--;	   // a is old p1, p1 is now the previous prime number
	PrimeNumber b = p2++;	   // b is old p2, p2 is now the next prime number

	cout << a.get() << endl;  // Print the previous prime number
	cout << p1.get() << endl; // Print the current prime number
	cout << b.get() << endl;  // Print the next prime number
	cout << p2.get() << endl; // Print the current prime number

	return 0;
}
