/*****************************************************************//**
 * \file   Books.h
 * \brief  The header file for the Books class
 *
 * \author Stanley Owen
 * \date   2025/5/28
 *********************************************************************/
#pragma once
#include "Book.h"
#include <iostream>
#include <vector>

class Books
{
private:
	std::vector<Book> books; // A vector to store the books

public:
	// Inserts a new book with the given title, author, and edition into the books vector.
	void insert(std::string title, std::string author, int edition);
	// Deletes a book or a specific edition of a book based on the provided title, author, edition, and type.
	void deletion(std::string title, std::string author, int edition, std::string type);
	// Finds a book or all books by an author based on the provided title, author, and type.
	void find(std::string title, std::string author, std::string type);
	// Sorts the books based on the specified key (author or title) and prints them.
	void sort(std::string key);
};
