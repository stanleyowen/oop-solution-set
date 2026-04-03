/*****************************************************************//**
 * \file   PrintCombination.h
 * \brief  Header file for generating and printing combinations
 *		   of elements
 *
 * \author Stanley Owen
 * \date   2025/4/24
 *********************************************************************/
#pragma once

#include <iostream>
#include <vector>

class PrintCombination
{
private:
	int numberOfElements;	   // Total number of elements
	int numberToChoose;		   // Number of elements to choose for the combination
	std::vector<int> elements; // Vector to store the elements

public:
	// Constructor to initialize the class with elements and number of choices
	PrintCombination(int* elements, int numberOfElements, int numberToChoose);

	// Function to generate and print all combinations of the specified number of elements
	friend void combination(const std::vector<int>& elements, std::vector<int>& current, int start, int numberToChoose);
};