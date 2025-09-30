/*****************************************************************//**
 * \file   Source.cpp
 * \brief  Reading a list of numbers and count the occurences of
 *		   each number.
 *
 * \author Stanley Owen
 * \date   2025/3/7
 *********************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

 /**
  * Check if the number is already in the list of occurences.
  *
  * \param number The number to be checked
  * \param listOfOccurences The list of occurences
  * \param indexContainingNumber The index containing the number if found
  * \return true if the number is found, otherwise false
  */
bool checkOccurences(int number, std::vector<std::vector<int> > listOfOccurences, int* indexContainingNumber)
{
	// Loop through the list of occurences
	for (int i = 0; i < listOfOccurences.size(); i++)
	{
		// If the number is found, return true and store the index containing the number
		if (number == listOfOccurences[i][0])
		{
			*indexContainingNumber = i;
			return true;
		}
	}

	// Return false if the number is not found in the list of occurences
	return false;
}

/**
 * Push the input number to the vector and count the occurences.
 *
 * \param number The number to be pushed to the vector
 * \param listOfOccurences The list of occurences
 */
void pushInputToVector(int number, std::vector<std::vector<int> >& listOfOccurences)
{
	// Declare the index containing the number
	int indexContainingNumber = 0;

	if (checkOccurences(number, listOfOccurences, &indexContainingNumber))
	{
		// Increment the occurences of the number based on the index containing the number
		listOfOccurences[indexContainingNumber][1] += 1;
	}
	else
	{
		// Push the number to the list of occurences if the number is not found
		listOfOccurences.push_back({ number, 1 });
	}
}

/**
 * Compare the player score.
 *
 * \param firstPlayer The first player score
 * \param secondPlayer The second player score
 * \return true if the first player score is greater than the second player score, otherwise false
 */
bool comparePlayerScore(std::vector<int>& firstPlayer, std::vector<int>& secondPlayer)
{
	// Compare the first player score with the second player score which is located in the
	// first element of the vector
	return firstPlayer[0] > secondPlayer[0];
}

/**
 * Print the list of occurences in the vector.
 *
 * \param listOfOccurences The list of occurences
 */
void printOccurences(std::vector<std::vector<int> > listOfOccurences)
{
	// Sort the list of occurences in descending order
	std::sort(listOfOccurences.begin(), listOfOccurences.end(), comparePlayerScore);

	std::cout << "N\tcount\n";

	// Loop through the list of occurences and print the number and the occurences respectively
	for (int i = 0; i < listOfOccurences.size(); i++)
	{
		std::cout << listOfOccurences[i][0] << "\t" << listOfOccurences[i][1] << "\n";
	}
}

int main()
{
	// Create a 2D vector to store the number and the occurences
	std::vector<std::vector<int> > listOfOccurences = {};
	// Declare the user input variable
	int userInput;

	// Loop until no input is found or also known as EOF
	while (std::cin >> userInput)
	{
		// Call the pushInputToVector function
		pushInputToVector(userInput, listOfOccurences);
	}

	// Call the printOccurences function
	printOccurences(listOfOccurences);

	return 0;
}