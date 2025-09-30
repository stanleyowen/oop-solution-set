/*****************************************************************//**
 * \file   Source.cpp
 * \brief  Parse the input string and output it in the form of n x n
 *		   square from top to down, left to right
 *
 * \author Stanley Owen
 * \date   2025/2/25
 *********************************************************************/

#include <iostream>
#include <math.h>

int main() {
	std::string inputString;

	// Loop until no input is found or also known as EOF
	while (std::cin >> inputString) {
		// Declares all necessary variables
		int stringLength = inputString.length(),
			squareWidth = ceil(sqrt(stringLength));

		// Concept:
		// Input string		: H a v e A N i c e D a  y (Assume no space)
		// Index position	: 0 1 2 3 4 5 6 7 8 9 10 11
		// 
		// 4 x 4 Matrix (index matrix implying the index in the string if exists):
		// 0 4 8  12  <- row
		// 1 5 9  13
		// 2 6 10 14
		// 3 7 11 15
		// ^
		// |
		// col
		for (int row = 0; row < squareWidth; row++) {
			for (int col = row; col < stringLength; col += squareWidth) {
				std::cout << inputString[col];
			}
			std::cout << "\n";
		}
	}

	return 0;
}
