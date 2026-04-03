/*****************************************************************//**
 * \file   Document.h
 * \brief  The header file for Document class
 *
 * \author Stanley Owen
 * \date   2025/4/30
 *********************************************************************/
#pragma once

#include <iostream>

class Document
{
protected:
	std::string text;

public:
	Document();					// Default constructor
	Document(std::string text); // Constructor with text parameter

	// CAUTION: Need to use const for find function
	std::string getText() const;

	Document operator=(Document document); // Assignment operator
};
