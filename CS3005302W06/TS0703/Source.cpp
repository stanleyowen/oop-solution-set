/*****************************************************************//**
 * \file   Source.cpp
 * \brief  Convert a string of digits into a 7-segment display
 *		   representation
 *
 * \author Stanley Owen
 * \date   2025/3/29
 *********************************************************************/
#include <iostream>
#include <vector>
#include <string>

#define ARR_SIZE 10
#define ARR_SEGMENT_SIZE 3

 // 7-segment display representation of digits 0-9
std::vector<std::vector<std::string>> segments = {
	{" _ ", "| |", "|_|"}, // 0
	{"   ", "  |", "  |"}, // 1
	{" _ ", " _|", "|_ "}, // 2
	{" _ ", " _|", " _|"}, // 3
	{"   ", "|_|", "  |"}, // 4
	{" _ ", "|_ ", " _|"}, // 5
	{" _ ", "|_ ", "|_|"}, // 6
	{" _ ", "  |", "  |"}, // 7
	{" _ ", "|_|", "|_|"}, // 8
	{" _ ", "|_|", " _|"}, // 9
};

int main()
{
	std::string inputNumber;

	// Read input until EOF
	while (std::getline(std::cin, inputNumber))
	{
		std::vector<int> numbers;
		std::vector<std::string> outputSegments(ARR_SEGMENT_SIZE, "");

		// Check if the number is valid
		for (char number : inputNumber)
		{
			// CAUTION: The input number must be a digit otherwise omit it
			if (std::isdigit(number))
			{
				numbers.push_back(number - '0');
			}
		}

		// Add the segments of each digit to the output
		for (int idx = 0; idx < numbers.size(); idx++)
		{
			for (int indexSegment = 0; indexSegment < ARR_SEGMENT_SIZE; indexSegment++)
			{
				outputSegments[indexSegment] += segments[numbers[idx]][indexSegment];
			}
		}

		// CAUTION: Still display 3 blanks if the data is empty
		for (int i = 0; i < ARR_SEGMENT_SIZE; i++)
		{
			std::cout << outputSegments[i] << "\n";
		}
	}

	return 0;
}
