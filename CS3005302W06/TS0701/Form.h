/*****************************************************************//**
 * \file   Form.h
 * \brief  The header file of the Form class
 *
 * \author Stanley Owen
 * \date   2025/3/29
 *********************************************************************/
#ifndef Form_H
#define Form_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Form
{
private:
	std::string inputWord;					   // Given word
	std::string transformedWord;			   // Transformed word in lowercase
	std::string fileName;					   // File name to read
	std::vector<std::string> wordsFound;	   // Found words
	static std::vector<std::string> wordLists; // List of words from the file

public:
	void SetInputWord(std::string inputWord); // Set input word
	void ProcessInputWord();				  // Process input word to lowercase
	void SetFileName(std::string fileName);	  // Set file name
	void Load_CompareWord();				  // Load and compare words from the file
	void PrintFoundWords();					  // Print found words
};

#endif // Form_H