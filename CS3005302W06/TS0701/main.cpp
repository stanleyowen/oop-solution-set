/*****************************************************************//**
 * \file   main.cpp
 * \brief  Compose a new word from the given word and compare it
 *		   with the list of valid words.
 *
 * \author Stanley Owen
 * \date   2025/3/29
 *********************************************************************/
#include "Form.h"

int main()
{
	Form form1;

	form1.SetInputWord("SWIMMING"); // Set the input word to "SWIMMING"
	form1.ProcessInputWord();		// Process the input word to lowercase
	form1.SetFileName("words.txt"); // Set the file name to "words.txt"
	form1.Load_CompareWord();		// Load and compare the words from the file
	form1.PrintFoundWords();		// Print the composed words found in the list

	return 0;
}