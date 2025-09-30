/*****************************************************************//**
 * \file   Source.cpp
 * \brief  Convert the given seconds into the hours, minutes, and
 *		   seconds format.
 *
 * \author Stanley Owen
 * \date   2025/2/21
 *********************************************************************/

#include <iostream>

int main() {
	// Use unsigned long long due to the limit of the input approaching 2^64 - 1
	unsigned long long inputTime, hour, minute, second;

	// Loop until no input was found or also known as EOF
	while (std::cin >> inputTime) {
		// Divide the total seconds with 3600 and store it to the hour variable
		hour = inputTime / 3600;

		// From the remaining seconds, divide it again by 60 and store the result
		// of the division to the minute variable
		minute = (inputTime % 3600) / 60;

		// The remaining seconds after being divided by 3600 and 60 respectively
		second = inputTime % 3600 % 60;

		// Print the output of the converted time
		std::cout << hour << " hours " << minute << " minutes and " << second << " seconds\n";
	}

	return 0;
}
