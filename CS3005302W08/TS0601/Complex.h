/*****************************************************************/ /**
* \file   Complex.h
* \brief  Complex number class header file
*
* \author Stanley Owen
* \date   2025/4/10
*********************************************************************/
#pragma once

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Complex
{
public:
	double realValue, imaginaryValue; // Real and imaginary values of the complex number

	Complex();								// Default constructor
	Complex(double real);					// Constructor with given real part of the complex number
	Complex(double real, double imaginary); // Constructor with given real and imaginary parts of the complex number

	// Get the real part of the complex number
	double real();
	friend double real(Complex complex);

	// Get the imaginary part of the complex number
	double imag();
	friend double imag(Complex complex);

	// Get the norm of the complex number
	double norm();
	friend double norm(Complex complex);

	Complex operator+(Complex complex); // Complex + Complex
	Complex operator-(Complex complex); // Complex - Complex
	Complex operator*(Complex complex); // Complex * Complex
	Complex operator/(Complex complex); // Complex / Complex

	Complex operator+(double scalar); // Complex + double
	Complex operator-(double scalar); // Complex - double
	Complex operator*(double scalar); // Complex * double
	Complex operator/(double scalar); // Complex / double

	friend Complex operator+(double scalar, Complex complex); // double + Complex
	friend Complex operator-(double scalar, Complex complex); // double - Complex
	friend Complex operator*(double scalar, Complex complex); // double * Complex
	friend Complex operator/(double scalar, Complex complex); // double / Complex

	friend bool operator==(Complex complex1, Complex complex2);			 // Compare two complex numbers
	friend ostream &operator<<(ostream &stream, const Complex &complex); // Output operator for complex numbers
	friend istream &operator>>(istream &stream, Complex &complex);		 // Input operator for complex numbers
};
