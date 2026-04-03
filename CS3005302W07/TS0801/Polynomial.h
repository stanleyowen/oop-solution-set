/*****************************************************************/ /**
* \file   Polynomial.h
* \brief  The header file of the Polynomial class
*
* \author Stanley Owen
* \date   2025/4/6
*********************************************************************/
#pragma once

#include <iostream>
#include <vector>
#include <cmath>

class Polynomial
{
private:
	std::vector<double> coefficients; // Coefficients of the polynomial

public:
	Polynomial();							  // Default constructor
	Polynomial(double *param, int size);	  // Constructor with coefficients and size
	Polynomial(const Polynomial &polynomial); // Copy constructor

	int mySize();								  // Get the size of the polynomial without leading zeros
	double operator[](int degree) const;		  // Get the coefficient of the polynomial with the given degree
	double &operator[](int degree);				  // Assign the coefficient of the polynomial with the given degree
	void operator=(const Polynomial &polynomial); // Assign the coefficients of the polynomial to be copied to the coefficients of the new polynomial

	// Addition Operators
	Polynomial operator+(int constantNum) const;								// Addition operator for polynomial and constant
	Polynomial operator+(const Polynomial &polynomial) const;					// Addition operator for polynomial and polynomial
	friend Polynomial operator+(int constantNum, const Polynomial &polynomial); // Addition operator for constant and polynomial

	// Subtraction Operators
	Polynomial operator-(int constantNum) const;								// Subtraction operator for polynomial and constant
	Polynomial operator-(const Polynomial &polynomial) const;					// Subtraction operator for polynomial and polynomial
	friend Polynomial operator-(int constantNum, const Polynomial &polynomial); // Subtraction operator for constant and polynomial

	// Multiplication Operators
	Polynomial operator*(int constantNum) const;						   // Multiplication operator for polynomial and constant
	Polynomial operator*(const Polynomial &polynomial) const;			   // Multiplication operator for polynomial and polynomial
	friend Polynomial operator*(int scalar, const Polynomial &polynomial); // Multiplication operator for constant and polynomial

	// Evaluate the polynomial with the given variable
	friend double evaluate(const Polynomial &polynomial, const double &variableToBeSubstitute);
};
