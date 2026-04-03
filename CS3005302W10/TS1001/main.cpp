/*****************************************************************//**
 * \file   main.cpp
 * \brief  List all combinations of a given number of elements
 *  	   with specified number of choices.
 *
 * \author Stanley Owen
 * \date   2025/4/24
 *********************************************************************/
#include "PrintCombination.h"

#define ELEMENTS_FOR_COMBINATION 5 // i.e., C(5,4)
#define ELEMENTS_FOR_CHOICE 4

int main(void)
{
	// Allocate memory for the array of elements
	int* arrayPtr = new int[ELEMENTS_FOR_COMBINATION];

	// Append the elements to the array
	for (int i = 0; i < ELEMENTS_FOR_COMBINATION; ++i)
	{
		arrayPtr[i] = i + 1;
	}

	// Print all combinations of the specified number of elements
	PrintCombination(arrayPtr, ELEMENTS_FOR_COMBINATION, ELEMENTS_FOR_CHOICE);

	// Deallocate the memory for the array
	if (arrayPtr != NULL)
	{
		delete[] arrayPtr;
	}

	return 0;
}
