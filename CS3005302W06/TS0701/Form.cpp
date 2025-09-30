/*****************************************************************//**
 * \file   Form.cpp
 * \brief  The implementation file of the Form class
 *
 * \author Stanley Owen
 * \date   2025/3/29
 *********************************************************************/
#include "Form.h"

 // Initialize the static member variable wordLists
std::vector<std::string> Form::wordLists = {};

/**
 * Sets the input word to be processed.
 *
 * \param inputWord The word to be processed.
 */
void Form::SetInputWord(std::string inputWord)
{
	this->inputWord = inputWord;
}

// Transforms the input word to lowercase.
void Form::ProcessInputWord()
{
	for (char character : inputWord)
	{
		this->transformedWord += std::tolower(character);
	}
}

/**
 * Sets the file name to be used for loading words.
 *
 * \param fileName The name of the file containing words.
 */
void Form::SetFileName(std::string fileName)
{
	this->fileName = fileName;
}

// Loads the words from the file and compares them with the transformed word.
void Form::Load_CompareWord()
{
	std::fstream fileContent;
	std::string word;

	fileContent.open(fileName); // Open the file for reading

	// Read the words from the file and store them in wordLists
	while (fileContent >> word)
	{
		this->wordLists.push_back(word);
	}

	// Compare the transformed word with the words in wordLists
	// If a word can be formed using the letters of the transformed word, add it to wordsFound
	for (std::string word : wordLists)
	{
		std::string characterFound,
			tempInput = transformedWord;

		// Iterate through each character of the word and check if it can be formed using the letters of transformedWord
		// If a character is found, replace it with ' ' in tempInput to avoid duplicate matches
		// If a character is not found, break the loop and move to the next word
		// If all characters are found, add the word to wordsFound
		for (int wordIdx = 0; wordIdx < word.size(); wordIdx++)
		{
			bool isFound = false;

			// Check if the character is found in tempInput
			for (int inputIdx = 0; inputIdx < tempInput.size(); inputIdx++)
			{
				if (word[wordIdx] == tempInput[inputIdx])
				{
					// If found, add the character to characterFound and replace it with ' ' in tempInput to avoid duplicate matches
					characterFound += tempInput[inputIdx];
					tempInput[inputIdx] = ' ';
					isFound = true;

					break;
				}
			}

			// If isFound is false, it means the character is not found in tempInput
			if (!isFound)
			{
				// Empty characterFound and break the loop
				characterFound = "";
				break;
			}
		}

		// If characterFound is not empty, add it to wordsFound
		if (characterFound.length() > 0)
		{
			wordsFound.push_back(characterFound);
		}
	}
}

// Prints the found words to the console.
void Form::PrintFoundWords()
{
	for (std::string word : wordsFound)
	{
		std::cout << word << "\n";
	}
}
