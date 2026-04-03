/*****************************************************************//**
 * \file   Source.cpp
 * \brief  Find all valid words in a grid of letters from a
 *		   given dictionary
 *
 * \author Stanley Owen
 * \date   2025/4/24
 *********************************************************************/
#include <iostream>
#include <vector>
#include <fstream>

#define GRID_SIZE 4

std::vector<std::vector<char>> gridLetters(GRID_SIZE, std::vector<char>(GRID_SIZE, 0));
std::vector<std::vector<bool>> isVisited(GRID_SIZE, std::vector<bool>(GRID_SIZE, false));

/**
 * Check if the word is valid in the grid
 *
 * \param col The column index of the grid
 * \param row The row index of the grid
 * \param word The word to check
 * \param index The current index of the word being checked
 * \return True if the word is valid, false otherwise
 */
bool isValidWord(int col, int row, std::string word, int index)
{
	// If the index is the last character of the word, the valid word is found
	if (index == word.length())
	{
		return true;
	}

	if (
		col < 0 || col >= GRID_SIZE || row < 0 || row >= GRID_SIZE || // Out of bounds
		isVisited[col][row] ||										  // Already been visited
		gridLetters[col][row] != word[index]						  // Current letter does not match
		)
	{
		return false;
	}

	// Mark the current cell as visited
	isVisited[col][row] = true;

	// Check all 8 possible directions (up, down, left, right, and diagonals)
	// If any of the adjacent cells match the next character in the word
	// Recursively check the next character in the word
	if (
		isValidWord(col - 1, row, word, index + 1) ||	  // Up
		isValidWord(col + 1, row, word, index + 1) ||	  // Down
		isValidWord(col, row - 1, word, index + 1) ||	  // Left
		isValidWord(col, row + 1, word, index + 1) ||	  // Right
		isValidWord(col - 1, row - 1, word, index + 1) || // Up-Left
		isValidWord(col - 1, row + 1, word, index + 1) || // Up-Right
		isValidWord(col + 1, row - 1, word, index + 1) || // Down-Left
		isValidWord(col + 1, row + 1, word, index + 1))	  // Down-Right
	{
		// Mark the current cell as unvisited before returning to allow other paths to use it
		isVisited[col][row] = false;

		return true;
	}

	// If no adjacent cells match, reset the visited status
	isVisited[col][row] = false;

	// Return false if no valid path is found
	return false;
}

int main()
{
	std::string word;
	std::vector<std::string> words;
	std::vector<std::string> validWords;
	std::ifstream inputFile("words.txt");

	// Read words from the file into the vector
	while (inputFile >> word)
	{
		words.push_back(word);
	}

	while (true)
	{
		// Reset the grid letters and valid words for every new grid
		validWords.clear();

		// Read the grid letters from the input
		for (int col = 0; col < GRID_SIZE; col++)
		{
			for (int row = 0; row < GRID_SIZE; row++)
			{
				char letter;

				// Check if the input exists to detect EOF
				if (!(std::cin >> letter))
				{
					return 0;
				}

				// Assign the input to the corresponding position in vector
				gridLetters[col][row] = letter;
			}
		}

		// Loop through the dictionary words to check for valid words
		for (std::string word : words)
		{
			// Only check words with length larger than or equal to 3
			if (word.length() >= 3)
			{
				// Loop through the grid to find the starting position
				for (int col = 0; col < GRID_SIZE; col++)
				{
					for (int row = 0; row < GRID_SIZE; row++)
					{
						// Check if the first letter of the word matches the grid letter
						if (isValidWord(col, row, word, 0))
						{
							validWords.push_back(word);
							goto found; // Break out of the loop if a valid word is found
						}
					}
				}
			}

		found:; // Label to break out of the loop
		}

		// Output all the valid words
		for (std::string word : validWords)
		{
			std::cout << word << "\n";
		}

		std::cout << "\n";
	}

	return 0;
}