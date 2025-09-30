/*****************************************************************//**
 * \file   ComputeSQRT.cpp
 * \brief  Calculating the square root of the inputNumber using
 *		   the Babylonian algorithm.
 *
 * \author Stanley Owen
 * \date   2025/2/21
 *********************************************************************/

#include <iostream>
#include <iomanip>

int main() {
	double inputNumber;

	// Loop until no input is found or also known as EOF
	while (std::cin >> inputNumber) {

		// Declare all the necessary variables 
		double initialGuess = 0,
			previousGuess = 0,
			r = 0;

		// Babylonian algortihm
		initialGuess = inputNumber / 2;			// Step 1: Make an initial guess
		r = inputNumber / initialGuess;			// Step 2: Compute r
		initialGuess = (initialGuess + r) / 2;	// Step 3: Update the initial guess

		// Loop the second and the third step of the Babylonian algorithm until
		// the difference between the initial (current) guess and previous guess is
		// smaller than 0.01
		while (abs(previousGuess - initialGuess) >= 0.01) {
			// Store the initialGuess value to the previousGuess before further updating the
			// initialGuess value
			previousGuess = initialGuess;

			// Calculate the second and third step of Babylonian algorithm calculation
			r = inputNumber / initialGuess;
			initialGuess = (initialGuess + r) / 2;
		}

		// Print the result to the terminal with 2 decimal places
		std::cout << std::setprecision(2) << std::fixed << previousGuess << "\n";
	}

	return 0;
}
