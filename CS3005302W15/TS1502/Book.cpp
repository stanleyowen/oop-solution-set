/*****************************************************************//**
 * \file   Book.cpp
 * \brief  The implementation of the Book class
 *
 * \author Stanley Owen
 * \date   2025/5/28
 *********************************************************************/
#include "Book.h"

 // Default constructor
 // Initializes the Book with an empty title, author, and an edition of 0
Book::Book() : title(""), author("")
{
	editions.push_back(0);
};

/**
 * Initializes the Book with a title, author, and an edition.
 *
 * \param title The title of the book
 * \param author The author of the book
 * \param edition The edition of the book
 */
Book::Book(std::string title, std::string author, int edition) : title(title), author(author)
{
	this->editions.push_back(edition);
};