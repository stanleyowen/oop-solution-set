/*****************************************************************/ /**
* \file   main.cpp
* \brief  Store coefficients of a polynomial and implement the
*		   basic operations of polynomial.
*
* \author Stanley Owen
* \date   2025/4/6
*********************************************************************/
#include <iostream>
#include <string>
#include "Polynomial.h"

using namespace std;

int main()
{
	double one[] = {1};
	double quad[] = {3, 2, 1};
	double cubic[] = {1, 2, 0, 3};

	Polynomial empty;		// Empty polynomial
	Polynomial One(one, 1); // One is 1
	Polynomial q(quad, 3);	// q is 3 + 2x + x^2
	Polynomial c(cubic, 4); // c is 1 + 2x + 0x^2 + 3x^3
	Polynomial p = q;		// Copy constructor
	Polynomial r;			// Empty polynomial
	r = q;					// test operator =
	r = c;					// test operator =

	// Print out the polynomial q
	cout << "Polynomial q " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "term with degree " << i << " has coefficient " << q[i] << endl;
	}

	// Print out the polynomial c
	cout << "Polynomial c " << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "term with degree " << i << " has coefficient " << c[i] << endl;
	}

	// Do the substitution of the polynomial
	cout << "value of q(2) is " << evaluate(q, 2) << endl;
	cout << "value of p(2) is " << evaluate(p, 2) << endl;
	cout << "value of r(2) is " << evaluate(r, 2) << endl;
	cout << "value of c(2) is " << evaluate(c, 2) << endl;

	// Addition operation
	r = q + c;
	cout << "value of (q + c)(2) is " << evaluate(r, 2) << endl;

	// Subtraction operation
	r = q - c;
	cout << "value of (q - c)(2) is " << evaluate(r, 2) << endl;

	// Multiplication operation
	r = q * c;
	cout << "size of q*c is " << r.mySize() << endl;

	// Print out the polynomial r
	cout << "Polynomial r (= q*c) " << endl;
	for (int i = 0; i < r.mySize(); i++)
	{
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;
	}

	// Do the substitution of the polynomial
	cout << "value of (q * c)(2) is " << evaluate(r, 2) << endl;

	return 0;
}