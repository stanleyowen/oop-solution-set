/*****************************************************************//**
 * \file   Source.cpp
 * \brief  Reverses the words in a given vocabulary and finds
 *		   the longest
 *
 * \author Stanley Owen
 * \date   2025/4/17
 *********************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

 /**
  * Reverses the given word
  *
  * \param word The word to be reversed
  * \return The reversed word
  */
std::string reverseWord(std::string word)
{
	std::string reversedWord;

	// Read the word from the end to the beginning and append it to the reversedWord
	for (int i = word.length() - 1; i >= 0; i--)
	{
		reversedWord += word[i];
	}

	return reversedWord;
}

int main()
{
	std::string vocabulary;
	std::vector<std::string> vocabularies;
	int maxLength = 0;				  // The current maximum length of the reversed words
	std::string longestReversedWords; // The longest reversed words

	// Read the vocabularies from the input until EOF
	while (std::cin >> vocabulary)
	{
		std::string vocabularyInLowerCase;

		// Convert the vocabulary to lower case
		for (int i = 0; i < vocabulary.length(); i++)
		{
			vocabularyInLowerCase += std::tolower(vocabulary[i]);
		}

		vocabularies.push_back(vocabularyInLowerCase);
	}

	// Loop through the vocabularies and check if the reversed word exists in the vocabularies
	for (int i = 0; i < vocabularies.size(); i++)
	{
		// Create a temp vector avoiding the vector to be modified
		std::vector<std::string> tempVocabularies = vocabularies;
		std::string reversedWords = reverseWord(vocabularies[i]);

		// IMPORTANT: Sort the temp vector before binary search
		std::sort(tempVocabularies.begin(), tempVocabularies.end());
		// IMPORTANT: Erase the element itself from the temp vector to avoid finding itself FOR PALINDROME CASE
		tempVocabularies.erase(tempVocabularies.begin() + i);

		// Use binary search to check if the reversed word exists in the vocabularies
		bool isFound = std::binary_search(tempVocabularies.begin(), tempVocabularies.end(), reversedWords);

		if (isFound && vocabularies[i].length() > maxLength)
		{
			maxLength = vocabularies[i].length();
			// IMPORTANT: Store the current vocabulary (NOT the reversed word)
			longestReversedWords = vocabularies[i];
		}
	}

	// Print the longest reversed words
	if (longestReversedWords.length() > 0)
	{
		std::cout << longestReversedWords << "\n";
	}
}
