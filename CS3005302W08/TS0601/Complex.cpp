/*****************************************************************//**
 * \file   Complex.cpp
 * \brief  Complex number class implementation
 *
 * \author Stanley Owen
 * \date   2025/4/9
 *********************************************************************/
#include "Complex.h"

 // Default constructor with no parameters
 // Initializes the real and imaginary values to 0
Complex::Complex() : realValue(0), imaginaryValue(0) {
};

/**
 * Constructor with given real part of the complex number
 * Initializes the real value to the given value and the imaginary value to 0
 *
 * \param real Real part of the complex number
 */
Complex::Complex(double real) : realValue(real), imaginaryValue(0) {
};

/**
 * Constructor with given real and imaginary parts of the complex number
 * Initializes the real and imaginary values to the given values
 *
 * \param real Real part of the complex number
 * \param imaginary Imaginary part of the complex number
 */
Complex::Complex(double real, double imaginary) : realValue(real), imaginaryValue(imaginary)
{
}

/**
 * Get the real part of the complex number
 *
 * \return Real part of the complex number
 */
double Complex::real()
{
	return realValue;
}

/**
 * Get the imaginary part of the complex number
 *
 * \return Imaginary part of the complex number
 */
double Complex::imag()
{
	return imaginaryValue;
}

/**
 * Get the norm of the complex number
 * norm = sqrt(real^2 + imaginary^2)
 *
 * \return Norm of the complex number
 */
double Complex::norm()
{
	return std::sqrt(std::pow(realValue, 2) + std::pow(imaginaryValue, 2));
}

/**
 * Get the real part of the complex number
 *
 * \param complex The given complex number
 * \return Real part of the complex number
 */
double real(Complex complex)
{
	return complex.realValue;
}

/**
 * Get the imaginary part of the complex number
 *
 * \param complex The given complex number
 * \return Imaginary part of the complex number
 */
double imag(Complex complex)
{
	return complex.imaginaryValue;
}

/**
 * Get the norm of the complex number
 * norm = sqrt(real^2 + imaginary^2)
 *
 * \param complex The given complex number
 * \return Norm of the complex number
 */
double norm(Complex complex)
{
	return std::sqrt(std::pow(complex.realValue, 2) + std::pow(complex.imaginaryValue, 2));
}

/**
 * Operator overloading for addition of two complex numbers
 *
 * \param complex The complex number to be added
 * \return The result of the addition
 */
Complex Complex::operator+(Complex complex)
{
	Complex result(*this); // Copy the current object

	// Add the real and imaginary parts of the complex numbers
	result.realValue += complex.realValue;
	result.imaginaryValue += complex.imaginaryValue;

	return result;
};

/**
 * Operator overloading for subtraction of two complex numbers
 *
 * \param complex The complex number to be subtracted
 * \return The result of the subtraction
 */
Complex Complex::operator-(Complex complex)
{
	Complex result(*this); // Copy the current object

	// Subtract the real and imaginary parts of the complex numbers
	result.realValue -= complex.realValue;
	result.imaginaryValue -= complex.imaginaryValue;

	return result;
}

/**
 * Operator overloading for multiplication of two complex numbers
 *
 * \param complex The complex number to be multiplied
 * \return The result of the multiplication
 */
Complex Complex::operator*(Complex complex)
{
	// Create a new Complex object to store the result
	Complex result;

	// Complex imaginary multiplication
	// (a + bi)(c + di) = ac + adi + bci + bdi^2
	//					= (ac - bd) + (ad + bc)i
	result.realValue = (this->realValue * complex.realValue - this->imaginaryValue * complex.imaginaryValue);		 // ac - bd
	result.imaginaryValue = (this->realValue * complex.imaginaryValue) + (this->imaginaryValue * complex.realValue); // ad + bc

	return result;
}

/**
 * Operator overloading for division of two complex numbers
 *
 * \param complex The complex number to be divided
 * \return The result of the division
 */
Complex Complex::operator/(Complex complex)
{
	Complex result;

	// Complex imaginary division
	// (a + bi) / (c + di) = (a + bi)(c - di) / (c + di)(c - di)
	//					   = ((ac + bd) + (bc - ad)i) / (c^2 + d^2)
	//					   = (ac + bd) / (c^2 + d^2) + ((bc - ad) / (c^2 + d^2))i
	result.realValue = (this->realValue * complex.realValue + this->imaginaryValue * complex.imaginaryValue);	   // ac + bd
	result.realValue /= std::pow(complex.realValue, 2) + std::pow(complex.imaginaryValue, 2);					   // c^2 + d^2
	result.imaginaryValue = (this->imaginaryValue * complex.realValue - this->realValue * complex.imaginaryValue); // bc - ad
	result.imaginaryValue /= std::pow(complex.realValue, 2) + std::pow(complex.imaginaryValue, 2);				   // c^2 + d^2

	return result;
}

/**
 * Operator overloading for addition of a complex number and a scalar (complex + double)
 *
 * \param scalar The scalar to be added
 * \return The result of the addition
 */
Complex Complex::operator+(double scalar)
{
	Complex result(*this); // Copy the current object

	result.realValue += scalar; // Add the scalar to the real part

	return result;
}

/**
 * Operator overloading for subtraction of a complex number and a scalar (complex - double)
 *
 * \param scalar The scalar to be subtracted
 * \return The result of the subtraction
 */
Complex Complex::operator-(double scalar)
{
	Complex result(*this); // Copy the current object

	result.realValue -= scalar; // Subtract the scalar from the real part

	return result;
}

/**
 * Operator overloading for multiplication of a complex number and a scalar (complex * double)
 *
 * \param scalar The scalar to be multiplied
 * \return The result of the multiplication
 */
Complex Complex::operator*(double scalar)
{
	Complex result(*this); // Copy the current object

	// Multiply the real and imaginary parts by the scalar
	result.realValue *= scalar;
	result.imaginaryValue *= scalar;

	return result;
}

/**
 * Operator overloading for division of a complex number by a scalar (complex / double)
 *
 * \param scalar The scalar to be divided
 * \return The result of the division
 */
Complex Complex::operator/(double scalar)
{
	Complex result(*this); // Copy the current object

	// Divide the real and imaginary parts by the scalar
	result.realValue /= scalar;
	result.imaginaryValue /= scalar;

	return result;
}

/**
 * Friend function for addition of a scalar and a complex number (double + complex)
 *
 * \param scalar The scalar to be added
 * \param complex The complex number to be added
 * \return The result of the addition
 */
Complex operator+(double scalar, Complex complex)
{
	// Reuse the existing operator+ function by reversing the order of the operands
	return complex + scalar;
};

/**
 * Friend function for subtraction of a scalar and a complex number (double - complex)
 *
 * \param scalar The scalar to be subtracted
 * \param complex The complex number to be subtracted
 * \return The result of the subtraction
 */
Complex operator-(double scalar, Complex complex)
{
	// Reuse the existing operator- function by reversing the order of the operands
	Complex result = complex - scalar;

	// Negate the real and imaginary parts of the result to get the correct subtraction
	// (scalar - complex) = -(complex - scalar)
	result.realValue *= -1;
	result.imaginaryValue *= -1;

	return result;
};

/**
 * Friend function for multiplication of a scalar and a complex number (double * complex)
 *
 * \param scalar The scalar to be multiplied
 * \param complex The complex number to be multiplied
 * \return The result of the multiplication
 */
Complex operator*(double scalar, Complex complex)
{
	// Reuse the existing operator* function by reversing the order of the operands
	return complex * scalar;
};

/**
 * Friend function for division of a scalar by a complex number (double / complex)
 *
 * \param scalar The scalar to be divided
 * \param complex The complex number to be divided
 * \return The result of the division
 */
Complex operator/(double scalar, Complex complex)
{
	// Create a new Complex object to store the result
	Complex result;

	// Complex imaginary division
	// a / (c + di) = a(c - di) / (c + di)(c - di)
	//				= (ac - adi) / (c^2 + d^2)
	//				= (ac / (c^2 + d^2)) - (ad / (c^2 + d^2))i
	result.realValue = scalar * complex.realValue;												   // ac
	result.realValue /= std::pow(complex.realValue, 2) + std::pow(complex.imaginaryValue, 2);	   // c^2 + d^2
	result.imaginaryValue = (scalar * complex.imaginaryValue) * -1;								   // -ad
	result.imaginaryValue /= std::pow(complex.realValue, 2) + std::pow(complex.imaginaryValue, 2); // c^2 + d^2

	return result;
};

/**
 * Friend function for comparison of two complex numbers
 *
 * \param complex1 The first complex number
 * \param complex2 The second complex number
 * \return true if the complex numbers are equal, false otherwise
 */
bool operator==(Complex complex1, Complex complex2)
{
	// Compare the real and imaginary parts of the complex numbers
	if (
		complex1.realValue == complex2.realValue &&
		complex1.imaginaryValue == complex2.realValue)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * Friend function for outputting a complex number to a stream
 *
 * \param stream The output stream to write to
 * \param complex The complex number to be output
 * \return The output stream
 */
ostream& operator<<(ostream& stream, const Complex& complex)
{
	// CAUTION: NO ENTER AT THE END OF THE LINE
	stream << complex.realValue << " + " << complex.imaginaryValue << "*i";
	return stream;
};

/**
 * Friend function for inputting a complex number from a stream
 *
 * \param stream The input stream to read from
 * \param complex The complex number to be input
 * \return The input stream
 */
istream& operator>>(istream& stream, Complex& complex)
{
	std::string equations;

	// Read the input for one line and store it in the equations string
	std::getline(std::cin, equations);

	// Find the "=" in the equations and remove chars before "="
	int signIdx = equations.find('=');

	if (signIdx != std::string::npos)
	{
		// Add 1 to include the "=" sign to be removed
		equations = equations.substr(signIdx + 1);
	}

	double real, imaginary;
	std::string sign, remaining;
	std::istringstream stringStream(equations); // Create a string stream and initialize it with the equations string

	// Extract the real, imaginary, sign, and remaining parts from the string stream
	stringStream >> real >> sign >> imaginary >> remaining;

	complex.realValue = real;

	// Check if the imaginary sign is present
	if (remaining == "*i")
	{
		// If the imaginary sign is present, set the imaginary value
		// Check if the sign is "+" or "-" and set the imaginary value accordingly
		// If the sign is "+", set the imaginary value to the extracted imaginary value
		// If the sign is "-", set the imaginary value to the negative of the extracted imaginary value
		complex.imaginaryValue = sign == "+" ? imaginary : -imaginary;
	}

	return stream;
};
