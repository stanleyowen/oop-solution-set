/*****************************************************************/ /**
* \file   Polynomial.cpp
* \brief  The implementation file of the Polynomial class
*
* \author Stanley Owen
* \date   2025/4/6
*********************************************************************/
#include "Polynomial.h"

// Default constructor
// Initialize the coefficients of the polynomial to 0
Polynomial::Polynomial() : coefficients(0) {
						   };

/**
 * Initialize the coefficients of the polynomial
 *
 * \param param Given coefficients of the polynomial
 * \param size The size of the coefficients
 */
Polynomial::Polynomial(double *param, int size)
{
	// Resize coefficients before assigning values to avoid out of range
	this->coefficients.resize(size);

	// Assign values to coefficients
	for (int i = 0; i < coefficients.size(); i++)
	{
		this->coefficients[i] = param[i];
	}
}

/**
 * Assign the coefficients of the polynomial to be copied to the coefficients of the new polynomial
 *
 * \param polynomial The polynomial to be copied
 */
Polynomial::Polynomial(const Polynomial &polynomial)
{
	this->coefficients = polynomial.coefficients;
}

/**
 * Get the size of the polynomial
 *
 * \return The size of the polynomial without leading zeros
 */
int Polynomial::mySize()
{
	int size = 0;
	bool isLeadingZero = true;

	// Check the coefficients reversely to check if there are leading zeros
	// As soon as the first non-zero coefficient is found, the leading zero is set to false
	// and the size is increased by 1 for each coefficient
	for (int i = coefficients.size() - 1; i >= 0; i--)
	{
		if (coefficients[i] != 0)
		{
			isLeadingZero = false;
		}

		if (!isLeadingZero)
		{
			size++;
		}
	}

	return size;
}

/**
 * Get the coefficient of the polynomial with the given degree
 *
 * \param degree The degree of the polynomial
 * \return The coefficient of the polynomial with the given degree
 */
double Polynomial::operator[](int degree) const
{
	double coefficient = 0;

	if (degree < 0 || degree > coefficients.size() - 1)
	{
		// Do nothing
	}
	else
	{
		// Return the coefficient of the polynomial with the given degree by accessing the coefficients vector
		coefficient = coefficients[degree];
	}

	return coefficient;
};

/**
 * Assign the coefficient of the polynomial with the given degree
 *
 * \param degree The degree of the polynomial to be assigned
 * \return The memory address of the coefficient of the polynomial with the given degree
 */
double &Polynomial::operator[](int degree)
{
	if (degree < 0)
	{
		// Do nothing
	}
	else if (degree > coefficients.size() - 1)
	{
		// Resize the coefficients vector to the given degree if the degree is
		// greater than the size of the coefficients vector
		coefficients.resize(degree + 1, 0.0);
	}

	return coefficients[degree];
};

/**
 * Assign the coefficients of the polynomial to be copied to the coefficients of the new polynomial
 *
 * \param polynomial The polynomial to be copied
 */
void Polynomial::operator=(const Polynomial &polynomial)
{
	this->coefficients = polynomial.coefficients;
}

/**
 * Addition operator for polynomial and constant
 *
 * \param constantNum The constant number to be added to the polynomial
 * \return The polynomial after adding the constant number
 */
Polynomial Polynomial::operator+(int constantNum) const
{
	Polynomial result(*this); // Copy current polynomial

	if (result.coefficients.size() > 0)
	{
		// Add the constant number to the first coefficient of the polynomial
		result.coefficients[0] += constantNum;
	}
	else
	{
		// If the polynomial is empty, add the constant number to the coefficients vector
		result.coefficients.push_back(constantNum);
	}

	return result;
}

/**
 * Addition operator for polynomial and polynomial
 *
 * \param polynomial The polynomial to be added to the current polynomial
 * \return The polynomial after adding the given polynomial
 */
Polynomial Polynomial::operator+(const Polynomial &polynomial) const
{
	Polynomial result;

	int maxSize = std::max(polynomial.coefficients.size(), this->coefficients.size());

	// Resize the coefficients vector to the maximum size of the two polynomials
	// to avoid out of range
	result.coefficients.resize(maxSize);

	// Loop through the coefficients of the two polynomials and add them
	// If the coefficient of one polynomial is out of range, assign the coefficient
	// of the other polynomial to the result directly
	for (int i = 0; i < maxSize; i++)
	{
		// Given polynomial is out of range
		if (i > polynomial.coefficients.size() - 1)
		{
			result.coefficients[i] = this->coefficients[i];
		}
		// Current polynomial is out of range
		else if (i > this->coefficients.size() - 1)
		{
			result.coefficients[i] = polynomial.coefficients[i];
		}
		else
		{
			result.coefficients[i] = this->coefficients[i] + polynomial.coefficients[i];
		}
	}

	return result;
}

/**
 * Subtraction operator for polynomial and constant
 *
 * \param constantNum The constant number to be subtracted from the polynomial
 * \return The polynomial after subtracting the constant number
 */
Polynomial Polynomial::operator-(int constantNum) const
{
	Polynomial result(*this); // Copy current polynomial

	// Subtract the constant number from the first coefficient of the polynomial
	// If the polynomial is empty, add the constant number to the coefficients vector
	if (result.coefficients.size() > 0)
	{
		result.coefficients[0] -= constantNum;
	}
	else
	{
		// CAUTION: Remember to multiply by -1
		result.coefficients.push_back(constantNum * -1);
	}

	return result;
}

/**
 * Subtraction operator for polynomial and polynomial
 *
 * \param polynomial The polynomial to be subtracted from the current polynomial
 * \return The polynomial after subtracting the given polynomial
 */
Polynomial Polynomial::operator-(const Polynomial &polynomial) const
{
	Polynomial result;

	int maxSize = std::max(polynomial.coefficients.size(), this->coefficients.size());

	// Resize the coefficients vector to the maximum size of the two polynomials
	result.coefficients.resize(maxSize);

	// Loop through the coefficients of the two polynomials and subtract them
	// If the coefficient of one polynomial is out of range, assign the coefficient
	// of the other polynomial to the result directly
	for (int i = 0; i < maxSize; i++)
	{
		// Given polynomial is out of range
		if (i > polynomial.coefficients.size() - 1)
		{
			result.coefficients[i] = this->coefficients[i];
		}
		// Current polynomial is out of range
		else if (i > this->coefficients.size() - 1)
		{
			// CAUTION: Remember to multiply by -1
			result.coefficients[i] = -polynomial.coefficients[i];
		}
		else
		{
			result.coefficients[i] = this->coefficients[i] - polynomial.coefficients[i];
		}
	}

	return result;
}

/**
 * Multiplication operator for polynomial and constant
 *
 * \param constantNum The constant number to be multiplied with the polynomial
 * \return The polynomial after multiplying with the constant number
 */
Polynomial Polynomial::operator*(int constantNum) const
{
	Polynomial result(*this); // Copy current polynomial

	// Multiply the coefficients of the polynomial with the constant number
	// If the polynomial is empty, add 0 to the coefficients vector
	for (int i = 0; i < coefficients.size(); i++)
	{
		result.coefficients[i] *= constantNum;
	}

	return result;
}

/**
 * Multiplication operator for polynomial and polynomial
 *
 * \param polynomial The polynomial to be multiplied with the current polynomial
 * \return The polynomial after multiplying with the given polynomial
 */
Polynomial Polynomial::operator*(const Polynomial &polynomial) const
{
	Polynomial result;

	// Resize the coefficients vector to the size of the sum of the degrees of the two polynomials
	// Note: Reduce the size by 1 since multiplying two polynomials will result in adding the degrees (not the size)
	// x^2 * x^3 = x^(2 + 3) = x^5
	// Add 1 to the size to include the constant term
	result.coefficients.resize((this->coefficients.size() - 1) + (polynomial.coefficients.size() - 1) + 1, 0);

	// Loop through the coefficients of the two polynomials and multiply them
	for (int i = 0; i < polynomial.coefficients.size(); i++)
	{
		for (int j = 0; j < this->coefficients.size(); j++)
		{
			result.coefficients[i + j] += polynomial.coefficients[i] * this->coefficients[j];
		}
	}

	return result;
}

/**
 * Addition operator for constant and polynomial
 *
 * \param constantNum The constant to be added to the polynomial
 * \param polynomial The polynomial to be added to the constant
 * \return The polynomial after adding the constant
 */
Polynomial operator+(int constantNum, const Polynomial &polynomial)
{
	// Reverse the order of the operands
	return polynomial + constantNum;
}

/**
 * Subtraction operator for constant and polynomial
 *
 * \param constantNum The constant to be subtracted from the polynomial
 * \param polynomial The polynomial to be subtracted from the constant
 * \return Result of the subtraction
 */
Polynomial operator-(int constantNum, const Polynomial &polynomial)
{
	// Since constant - polynomial results in a negative polynomial, multiply the result by -1
	// to get the correct result
	return (polynomial - constantNum) * -1;
}

/**
 * Multiplication operator for constant and polynomial
 *
 * \param constantNum The constant to be multiplied with the polynomial
 * \param polynomial The polynomial to be multiplied with the constant
 * \return The polynomial after multiplying with the constant
 */
Polynomial operator*(int constantNum, const Polynomial &polynomial)
{
	// Reverse the order of the operands
	return polynomial * constantNum;
}

/**
 * Evaluate the polynomial with the given variable
 *
 * \param polynomial The polynomial to be evaluated
 * \param variableToBeSubstitute The variable to be substituted into the polynomial
 * \return The value of the polynomial after substituting the variable
 */
double evaluate(const Polynomial &polynomial, const double &variableToBeSubstitute)
{
	double result = 0;
	std::vector<double> coefficients = polynomial.coefficients;

	// Loop through the coefficients of the polynomial and substitute the variable by multiplying
	// it with the coefficient
	for (int pow = 0; pow < coefficients.size(); pow++)
	{
		result += coefficients[pow] * std::pow(variableToBeSubstitute, pow);
	}

	return result;
}