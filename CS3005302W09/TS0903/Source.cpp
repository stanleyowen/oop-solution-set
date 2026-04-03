/*****************************************************************//**
 * \file   Source.cpp
 * \brief  Translation matching program
 *
 * \author Stanley Owen
 * \date   2025/4/17
 *********************************************************************/
#include <iostream>
#include <string>
#include <vector>

 /**
  * Finds all possible translations for a given character based on the provided translations.
  *
  * \param letterToBeTranslated The character to be translated.
  * \param translations The translations to use for finding possible translations.
  * \param result The vector to store the found translations.
  */
void findPossibleTranslations(char letterToBeTranslated, const std::vector<std::pair<char, char>>& translations, std::vector<char>& result)
{
	// IMPORTANT: Break the recursion if the letter exists to avoid infinite recursion
	if (find(result.begin(), result.end(), letterToBeTranslated) != result.end())
	{
		return;
	}

	// Add the letterToBeTranslated to the result vector
	result.push_back(letterToBeTranslated);

	// Iterate through the translations to find possible translations for the letterToBeTranslated
	for (const std::pair<char, char>& translation : translations)
	{
		// If the translation pair matches the letterToBeTranslated, find its translations recursively
		if (translation.first == letterToBeTranslated)
		{
			findPossibleTranslations(translation.second, translations, result);
		}
	}
}

/**
 * Compares two words to see if they match based on the given translations.
 *
 * \param firstWord The first word to compare.
 * \param secondWord The second word to compare.
 * \param translations The translations to use for comparison.
 * \return True if the words match, false otherwise.
 */
bool wordsMatch(const std::string& firstWord, const std::string& secondWord, const std::vector<std::pair<char, char>>& translations)
{
	// Check if the lengths of the words are equal
	if (firstWord.length() != secondWord.length())
	{
		return false;
	}

	// Iterate through each character of the words and check for translations for each character
	for (size_t i = 0; i < firstWord.length(); ++i)
	{
		char firstLetterToBeTranslated = firstWord[i],
			secondLetterToBeTranslated = secondWord[i];
		std::vector<char> possibleTranslations;

		// Find translations for the first letter
		findPossibleTranslations(firstLetterToBeTranslated, translations, possibleTranslations);

		// Check if the second letter can be translated to any of the possible translations of the first letter
		if (find(possibleTranslations.begin(), possibleTranslations.end(), secondLetterToBeTranslated) == possibleTranslations.end())
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int numberOfTranslations, pairCount;

	// Read number of translations and pairs until both are zero or EOF
	while (std::cin >> numberOfTranslations >> pairCount && (numberOfTranslations != 0 && pairCount != 0))
	{
		char a, b; // Translation characters from a to b
		std::vector<std::pair<char, char>> translations;

		// Read number of translations and their pairs then store them in a vector
		for (int i = 0; i < numberOfTranslations; ++i)
		{
			std::cin >> a >> b;
			translations.emplace_back(a, b);
		}

		// Read number of pairs and check if they match
		for (int i = 0; i < pairCount; ++i)
		{
			std::string firstWord, secondWord;
			std::cin >> firstWord >> secondWord;

			// Check if the words match using the translations
			if (wordsMatch(firstWord, secondWord, translations))
			{
				std::cout << "yes\n";
			}
			else
			{
				std::cout << "no\n";
			}
		}
	}

	return 0;
}