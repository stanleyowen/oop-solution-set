/*****************************************************************//**
 * \file   Book.h
 * \brief  The header file for the Book class
 *
 * \author Stanley Owen
 * \date   2025/5/28
 *********************************************************************/
#pragma once

#include <vector>
#include <string>

class Book
{
public:
	std::string title;		   // The title of the book
	std::string author;		   // The author of the book
	std::vector<int> editions; // A vector to store the editions of the book

	// Initializes the Book with an empty title, author, and an edition of 0
	Book();
	// Initializes the Book with a title, author, and an edition
	Book(std::string title, std::string author, int edition);
};