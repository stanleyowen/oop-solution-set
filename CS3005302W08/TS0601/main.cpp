/*****************************************************************//**
 * \file   main.cpp
 * \brief  Basic number operations on complex numbers
 *
 * \author Stanley Owen
 * \date   2025/4/9
 *********************************************************************/
#include "Complex.h"

int main()
{
	// x = 0 + 0*i
	// y = 3 + 0*i
	// z = -3.2 + 2.1*i
	Complex x, y(3), z(-3.2, 2.1);

	// Output the complex numbers
	cout << "x =  " << x << "y = " << y << "z = " << z << "\n";

	// x = 3 - 4*i
	// y = 1 - 1*i
	x = Complex(3, -4);
	y = Complex(1, -1);

	cout << "x =  " << x << "\n";
	cout << "testing members and support functions as well as"
		<< " output operator:\n"
		<< "complex number x = " << x << endl
		<< "real part: " << x.real() << endl
		<< "real part from friend real(x): " << real(x) << endl
		<< "imaginary part: " << x.imag() << endl
		<< "imaginary part from friend imag(x) : " << imag(x) << endl
		<< "norm: " << norm(x) << endl
		<< endl;

	// Relational operators
	if (x == y)
		cout << "x = y" << endl
		<< endl;
	else
		cout << "x!=y" << endl
		<< endl;

	// Addition
	z = x + y;
	cout << "z = x + y = " << z << endl;

	// Multiplication
	z = x * y;
	cout << "z = x * y = " << z << endl;

	// Subtraction
	z = x - y;
	cout << "z = x - y = " << z << endl;

	// Division
	z = x / y;
	cout << "z = x / y = " << z << endl << endl;

	double d(2.0);
	cout << "d: " << d << "   x: " << x << endl;

	// complex + double
	z = x + d;
	cout << "x+d: ";
	cout << z << endl;

	// complex - double
	z = x - d;
	cout << "x-d: ";
	cout << z << endl;

	// complex * double
	z = x * d;
	cout << "x*d: ";
	cout << z << endl;

	// complex / double
	z = x / d;
	cout << "x/d: ";
	cout << z << endl;

	// friend double + complex
	z = d + x;
	cout << "d+x: ";
	cout << z << endl;

	// friend double - complex
	z = d - x;
	cout << "d-x: ";
	cout << z << endl;

	// friend double * complex
	z = d * x;
	cout << "d*x: ";
	cout << z << endl;

	// friend double / complex
	z = d / x;
	cout << "d/x: ";
	cout << z << endl;

	// complex / complex
	Complex two(2, 0);
	cout << "two/x: ";
	cout << two / x << endl;

	cout << "\nGetting data from standard input: \n";
	cin >> x >> y;
	cout << "data read is: x = " << x << " y = " << y << endl
		<< endl;

	return 0;
}