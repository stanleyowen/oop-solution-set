/*****************************************************************//**
 * \file   Template.h
 * \brief  The header file for Iterative and Recursive Binary Search
 *
 * \author Stanley Owen
 * \date   2025/5/21
 *********************************************************************/
#pragma once
#include <algorithm>

 /**
  * Binary search using iteration method
  *
  * \param arrData The array to be searched
  * \param low The starting index
  * \param high The ending index
  * \param keywords The value to search for
  * \param isFound Flag indicating if the value was found
  * \param keywordsIdx The index of the found value
  */
template <typename Type>
void ItrBinarySearch(const Type arrData[], int low, int high, Type keywords, bool& isFound, int& keywordsIdx)
{
	// Check if the low index is always less than or equal to the high index
	while (low <= high)
	{
		// Calculate the mid index
		int mid = low + (high - low) / 2;

		// Check if the middle element is equal to the keywords
		if (arrData[mid] == keywords)
		{
			isFound = true;
			keywordsIdx = mid;
			break;
		}

		// If the middle element is greater than the keywords, search in the left half
		if (arrData[mid] > keywords)
		{
			isFound = false;
			high = mid - 1;
		}
		// If the middle element is less than the keywords, search in the right half
		else
		{
			isFound = false;
			low = mid + 1;
		}
	}
}

/**
 * Binary search using recursion method
 *
 * \param arrData The array to be searched
 * \param low The starting index
 * \param high The ending index
 * \param keywords The value to search for
 * \param isFound Flag indicating if the value was found
 * \param keywordsIdx The index of the found value
 */
template <typename Type>
void RecBinarySearch(const Type arrData[], int low, int high, Type keywords, bool& isFound, int& keywordsIdx)
{
	// Base case: if low index is greater than high index, the value is not found
	if (low > high)
	{
		isFound = false;
		return;
	}

	int mid = low + (high - low) / 2;

	// Base case: if the middle element is equal to the keywords, set isFound to true
	if (arrData[mid] == keywords)
	{
		isFound = true;
		keywordsIdx = mid;
		return;
	}

	// If the middle element is greater than the keywords, search in the left half
	if (arrData[mid] > keywords)
	{
		isFound = false;
		RecBinarySearch(arrData, low, mid - 1, keywords, isFound, keywordsIdx);
	}
	// If the middle element is less than the keywords, search in the right half
	else
	{
		isFound = false;
		RecBinarySearch(arrData, mid + 1, high, keywords, isFound, keywordsIdx);
	}
}
