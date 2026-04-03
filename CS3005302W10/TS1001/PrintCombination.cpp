/*****************************************************************//**
 * \file   PrintCombination.cpp
 * \brief  Implementation of generating and printing combinations
 *		   of elements
 *
 * \author Stanley Owen
 * \date   2025/4/24
 *********************************************************************/
#include "PrintCombination.h"

 /**
  * Generates and prints all combinations of a given number of elements with specified number of choices.
  *
  * \param elements The vector of elements to choose from
  * \param currentPossibleCombination The current combination being generated
  * \param index The starting index for the current combination
  * \param numberToChoose The number of elements to choose for the combination
  */
void combination(const std::vector<int>& elements, std::vector<int>& currentPossibleCombination, int index, int numberToChoose)
{
	// Base case: If the current combination size is equal to the number of choices
	if (currentPossibleCombination.size() == numberToChoose)
	{
		// Print the current combination
		for (int i = 0; i < currentPossibleCombination.size(); i++)
		{
			std::cout << currentPossibleCombination[i];

			// Avoid printing a space after the last element
			if (i != currentPossibleCombination.size() - 1)
			{
				std::cout << " ";
			}
		}

		std::cout << "\n";

		return;
	}

	// Recursive case: Iterate through the elements starting from the current index
	for (int i = index; i < elements.size(); i++)
	{
		// Push the current element into the combination
		currentPossibleCombination.push_back(elements[i]);

		// Recurse with the next element
		combination(elements, currentPossibleCombination, i + 1, numberToChoose);

		// Remove the last element so that it can be replaced with the next element
		currentPossibleCombination.pop_back();
	}
}

/**
 * Constructor to initialize the class with elements and number of choices
 *
 * \param elements The array of elements to choose from
 * \param numberOfElements The total number of elements
 * \param numberToChoose The number of elements to choose for the combination
 */
PrintCombination::PrintCombination(int* elements, int numberOfElements, int numberToChoose) : numberOfElements(numberOfElements), numberToChoose(numberToChoose)
{
	// Push the elements into the vector
	for (int i = 0; i < numberOfElements; i++)
	{
		this->elements.push_back(elements[i]);
	}

	// Initialize a temporary vector to store the current combination
	std::vector<int> currentPossibleCombination;

	// Start the recursive combination generation
	combination(this->elements, currentPossibleCombination, 0, numberToChoose);
}
