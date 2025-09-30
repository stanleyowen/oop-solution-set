/*****************************************************************//**
 * \file   Source.cpp
 * \brief  Perform addition, subtraction, and multiplication of
 *		   large integers represented as strings.
 *
 * \author Stanley Owen
 * \date   2025/3/29
 *********************************************************************/
#include <iostream>
#include <string>
#include <vector>

 /**
  * Reverse a string and store the result in rInput.
  *
  * \param input The string to be reversed.
  * \param rInput The reversed string.
  */
void reverse(std::string input, std::string& rInput)
{
	// Access the string from the end to the beginning and store it in rInput
	for (int i = input.length() - 1; i >= 0; i--)
	{
		rInput += input[i];
	}
}

/**
 * Remove leading zeros from a string.
 *
 * \param input The string from which leading zeros will be removed.
 * \return The string without leading zeros.
 */
std::string removeLeadingZero(std::string input)
{
	std::string result = input;
	std::vector<int> indexToBeRemoved = {};

	// List the indexes of leading zeros
	for (int i = 0; i < input.length(); i++)
	{
		// IMPORTANT: Do not remove the last zero
		if (result[i] == '0' && i != input.length() - 1)
		{
			indexToBeRemoved.push_back(i);
		}
		else if (result[i] != '0')
		{
			break;
		}
	}

	// Remove the leading zeros
	result.erase(0, indexToBeRemoved.size());

	return result;
}

/**
 * Calculate the sum of two large integers represented as strings.
 *
 * \param firstNumber The first large integer as a string.
 * \param secondNumber The second large integer as a string.
 * \return The sum of the two large integers as a string.
 */
std::string calculateSum(std::string firstNumber, std::string secondNumber)
{
	std::string rFirst, rSecond, rFinal, finalResult;

	// Reverse the input numbers and store them in rFirst and rSecond
	reverse(firstNumber, rFirst);
	reverse(secondNumber, rSecond);

	// Store the longer and shorter numbers
	std::string longest = rFirst.length() > rSecond.length() ? rFirst : rSecond,
		shortest = longest == rFirst ? rSecond : rFirst;
	int diffLength = longest.length() - shortest.length();
	int carry = 0;

	for (int i = 0; i < shortest.length(); i++)
	{
		int first = rFirst[i] - '0',
			second = rSecond[i] - '0',
			// Add the digits and from the previous carry
			result = first + second + carry;

		// Reset carry to 0
		carry = 0;

		// Check if the result is greater than 9
		// If so, set carry to 1 and reduce the result to a single digit
		if (result > 9)
		{
			carry = 1;
			result %= 10;
		}

		// Append the result to rFinal
		rFinal += std::to_string(result);
	}

	// If the lengths are different, add the remaining digits of the longer number
	if (diffLength > 0)
	{
		for (int i = 0; i < diffLength; i++)
		{
			// Get the remaining digit from the longer number and add the carry if exists
			int number = longest[shortest.length() + i] - '0',
				result = number + carry;

			// Reset carry to 0
			carry = 0;

			// Check if the result is greater than 9
			// If so, set carry to 1 and reduce the result to a single digit
			if (result > 9)
			{
				carry = 1;
				result %= 10;
			}

			// Append the result to rFinal
			rFinal += std::to_string(result);
		}
	}

	// If there is still a carry, append it most back (reverse)
	if (carry == 1)
	{
		rFinal += "1";
	}

	// Reverse the final result to get the correct order
	reverse(rFinal, finalResult);

	return finalResult;
}

/**
 * Calculate the difference between two large integers represented as strings.
 *
 * \param firstNumber The first large integer as a string.
 * \param secondNumber The second large integer as a string.
 * \return The difference between the two large integers as a string.
 */
std::string calculateDifference(std::string firstNumber, std::string secondNumber)
{
	std::string rFirst, rSecond,
		rFinal, finalResult,
		longest, shortest;

	// Reverse the input numbers and store them in rFirst and rSecond
	reverse(firstNumber, rFirst);
	reverse(secondNumber, rSecond);

	// If the numbers are equal, result is 0
	if (rFirst == rSecond)
	{
		return "0";
	}

	// If the lengths are equal, compare digits and set longest and shortest
	if (rFirst.length() == rSecond.length())
	{
		for (int i = 0; i <= rFirst.length(); i++)
		{
			int tempA = rFirst[i] - '0',
				tempB = rSecond[i] - '0',
				tempDiff = tempA - tempB;

			// Skip if the difference is the same
			if (tempDiff != 0)
			{
				// If the difference is positive, tempA > tempB
				if (tempDiff > 0)
				{
					longest = rFirst;
					shortest = rSecond;
				}
				// Else tempA < tempB
				else
				{
					longest = rSecond;
					shortest = rFirst;
				}
			}
		}
	}
	// If the lengths are different, set longest and shortest based on length
	else if (rFirst.length() >= rSecond.length())
	{
		longest = rFirst;
		shortest = rSecond;
	}
	else
	{
		longest = rSecond;
		shortest = rFirst;
	}

	// Check if the longest number is the first number, if not, set isNegative to true
	bool isNegative = longest != rFirst;
	int diffLength = longest.length() - shortest.length(),
		carry = 0;

	for (int i = 0; i < shortest.length(); i++)
	{
		int first = longest[i] - '0',
			second = shortest[i] - '0',
			// Subtract the digits and from the previous carry
			result = first - second - carry;

		// Reset carry to 0
		carry = 0;

		// Check if the result is negative
		// If so, set carry to 1 and add 10 to the result
		if (result < 0)
		{
			carry = 1;
			result += 10;
		}

		// Append the result to rFinal
		rFinal += std::to_string(result);
	}

	// If the lengths are different, add the remaining digits of the longer number
	// and subtract the carry if exists
	if (diffLength > 0)
	{
		for (int i = 0; i < diffLength; i++)
		{
			// Get the remaining digit from the longer number and subtract the carry if exists
			int number = longest[shortest.length() + i] - '0',
				result = number - carry;

			// Reset carry to 0
			carry = 0;

			// Check if the result is negative
			// If so, set carry to 1 and add 10 to the result
			if (result < 0)
			{
				carry = 1;
				result += 10;
			}

			// Append the result to rFinal
			rFinal += std::to_string(result);
		}
	}

	reverse(rFinal, finalResult);						 // Reverse the final result to get the correct order
	finalResult = removeLeadingZero(finalResult);		 // Remove leading zeros
	finalResult = (isNegative ? "-" : "") + finalResult; // Add negative sign if needed

	return finalResult;
}

/**
 * Calculate the product of two large integers represented as strings.
 *
 * \param firstNumber The first large integer as a string.
 * \param secondNumber The second large integer as a string.
 * \return The product of the two large integers as a string.
 */
std::string calculateProduct(std::string firstNumber, std::string secondNumber)
{
	std::string rFirst, rSecond, longest, shortest;
	std::vector<std::string> singleProductResult; // Store the each single product result

	// Reverse the input numbers and store them in rFirst and rSecond
	reverse(firstNumber, rFirst);
	reverse(secondNumber, rSecond);

	// Set the longest and shortest numbers based on length
	if (rFirst.length() >= rSecond.length())
	{
		longest = rFirst;
		shortest = rSecond;
	}
	else
	{
		longest = rSecond;
		shortest = rFirst;
	}

	int carry = 0;

	for (int i = 0; i < shortest.length(); i++)
	{
		std::string rResult, result;

		for (int j = 0; j < longest.length(); j++)
		{
			// Multiply the digits and add the carry
			int tempResult = (shortest[i] - '0') * (longest[j] - '0') + carry;

			carry = 0; // Reset carry to 0

			// If not the last digit, check if the result is greater than 9
			// If so, set carry to 1 and reduce the result to a single digit
			// Else, append directly to rResult
			if (j != longest.length() - 1)
			{
				if (tempResult > 9)
				{
					carry = std::floor(tempResult / 10);
					tempResult %= 10;
				}

				rResult += std::to_string(tempResult);
			}
			else
			{
				// Since the last digit of multiplication may consist more than 1 digit
				// Reverse the result and store it in rResult to get the correct order
				std::string lastResult = std::to_string(tempResult),
					rLastResult;

				reverse(lastResult, rLastResult);
				rResult += rLastResult;
			}
		}

		// Reverese the result to get the correct order
		reverse(rResult, result);

		// Push the result to the singleProductResult vector
		singleProductResult.push_back(result);
	}

	// Concept:
	// Example: 123 * 456
	// 1. 123 * 6 = 738
	// 2. 123 * 5 = 6150
	// 3. 123 * 4 = 49200
	// 4. 738 + 6150 + 49200 = 56088
	// 5. The final result is 56088
	for (int i = 0; i < singleProductResult.size(); i++)
	{
		std::string zerosToBeAdded;

		for (int j = 0; j < i; j++)
		{
			zerosToBeAdded += '0';
		}

		singleProductResult[i] += zerosToBeAdded;
	}

	std::string finalResult = "0";

	// Add all the single product results to get the final result
	for (std::string productRes : singleProductResult)
	{
		finalResult = calculateSum(finalResult, productRes);
	}

	// Remove leading zeros from the final result
	finalResult = removeLeadingZero(finalResult);

	return finalResult;
}

int main()
{
	std::string firstNumber, secondNumber,
		sumResult, diffResult, productResult;

	// Read input until EOF
	while (std::cin >> firstNumber >> secondNumber)
	{
		// Calculate the sum, difference, and product of the two numbers
		sumResult = calculateSum(firstNumber, secondNumber);
		diffResult = calculateDifference(firstNumber, secondNumber);
		productResult = calculateProduct(firstNumber, secondNumber);

		// Print the results
		std::cout << sumResult << "\n";
		std::cout << diffResult << "\n";
		std::cout << productResult << "\n";
	}
}
