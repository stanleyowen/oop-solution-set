/*****************************************************************//**
 * \file   Books.cpp
 * \brief  The implementation of the Books class
 *
 * \author Stanley Owen
 * \date   2025/5/28
 *********************************************************************/
#include "Books.h"
#include <algorithm>

 /**
  * Compares two Book objects by author and then by title in ascending order.
  *
  * \param firstBook The first Book object
  * \param secondBook The second Book object
  * \return True if firstBook is less than secondBook, false otherwise
  */
bool ascendingByAuthorThenTitle(Book firstBook, Book secondBook)
{
	// Compare by author first, then by title
	if (firstBook.author != secondBook.author)
	{
		return firstBook.author < secondBook.author;
	}

	return firstBook.title < secondBook.title;
}

/**
 * Compares two Book objects by title and then by author in ascending order.
 *
 * \param firstBook The first Book object
 * \param secondBook The second Book object
 * \return True if firstBook is less than secondBook, false otherwise
 */
bool ascendingByTitleThenAuthor(Book firstBook, Book secondBook)
{
	// Compare by title first, then by author
	if (firstBook.title != secondBook.title)
	{
		return firstBook.title < secondBook.title;
	}

	return firstBook.author < secondBook.author;
}

/**
 * Compares two integers representing book editions in ascending order.
 *
 * \param firstEdition The first edition
 * \param secondEdition The second edition
 * \return True if firstEdition is less than secondEdition, false otherwise
 */
bool ascendingEdition(int firstEdition, int secondEdition)
{
	return firstEdition < secondEdition;
}

/**
 * Compares two strings representing book titles in ascending order.
 *
 * \param firstTitle The first title
 * \param secondTitle The second title
 * \return True if firstTitle is less than secondTitle, false otherwise
 */
bool ascendingTitle(std::string firstTitle, std::string secondTitle)
{
	return firstTitle < secondTitle;
}

/**
 * Inserts a new book or edition into the collection.
 *
 * \param title The title of the book
 * \param author The author of the book
 * \param edition The edition of the book
 */
void Books::insert(std::string title, std::string author, int edition)
{
	bool isDuplicate = false,		 // If the book with the same edition already exists
		editionDoesNotExist = false; // If the book does not have the same edition

	// IMPORTANT: Use pointer to allow modification in the book editions vector
	for (Book& book : books)
	{
		// Check if the book with the same title and author already exists
		// If the book with the same title and author does not exist, create a new book
		// If the book with the same title and author exists, check if the edition already exists
		// If the edition already exists, consider it a duplicate
		// If the edition does not exist, add it to the book's editions vector
		if (book.title == title && book.author == author)
		{
			auto sameEditionIsFound = std::find(book.editions.begin(), book.editions.end(), edition);

			// Considered duplicate when have the same edition
			if (sameEditionIsFound != book.editions.end())
			{
				isDuplicate = true;
			}
			// If the book does not have the same edition
			// then add the edition to the book's editions vector
			else
			{
				editionDoesNotExist = true;
				book.editions.push_back(edition);
			}

			break;
		}
	}

	if (isDuplicate)
	{
		std::cout << "Datum already exist.\n";
	}
	// If the book is not duplicate and the editionDoesNotExist is false (meaning the book does not exist)
	// then create a new book with the given title, author, and edition
	else if (!editionDoesNotExist)
	{
		Book newBook = Book(title, author, edition);
		books.push_back(newBook);
		std::cout << "Insert " << author << "'s " << title << ", Edition: " << edition << ".\n";
	}
	else
	{
		std::cout << "Insert " << author << "'s " << title << ", Edition: " << edition << ".\n";
	}
};

/**
 * Deletes a book or an edition from the collection.
 *
 * \param title The title of the book
 * \param author The author of the book
 * \param edition The edition of the book to delete
 * \param type The type of deletion: "book" to delete the entire book, "edition" to delete a specific edition
 */
void Books::deletion(std::string title, std::string author, int edition, std::string type)
{
	bool actionDone = false; // Flag to indicate if the action was successful

	// Check if the type is valid
	if (type != "book" && type != "edition")
	{
		return;
	}

	// Iterate through the books to find the book with the given title and author
	for (int idx = 0; idx < books.size(); idx++)
	{
		if (books[idx].title == title && books[idx].author == author)
		{
			// Delete a specific edition
			if (type == "edition")
			{
				// Loop through the editions of the book to find the edition to delete
				for (int editionIdx = 0; editionIdx < books[idx].editions.size(); editionIdx++)
				{
					if (books[idx].editions[editionIdx] == edition)
					{
						actionDone = true; // Flag that the action is done

						// Remove the edition from the book's editions vector
						books[idx].editions.erase(books[idx].editions.begin() + editionIdx);
						std::cout << "Delete " << author << "'s " << title << ", Edition: " << edition << ".\n";

						break;
					}
				}
			}
			// Delete the entire book
			else
			{
				actionDone = true; // Flag that the action is done

				// Remove the book from the books vector
				books.erase(books.begin() + idx);
				std::cout << "Delete " << author << "'s " << title << ".\n";
			}

			break;
		}
	}

	// If the action is not done, it means the book or edition was not found
	// Print an appropriate message based on the type of deletion
	if (!actionDone)
	{
		if (type == "edition")
		{
			std::cout << "Datum doesn't exist.\n";
		}
		else
		{
			std::cout << "Book doesn't exist.\n";
		}
	}
};

/**
 * Finds a book or all books by an author based on the provided title, author, and type.
 *
 * \param title The title of the book to find
 * \param author The author of the book to find
 * \param type The type of search: "book" to find a specific book, "author" to find all books by an author
 */
void Books::find(std::string title, std::string author, std::string type)
{
	bool actionDone = false;		 // Flag to indicate if the action was successful
	std::string foundAuthor;		 // To store the author of the found book
	std::vector<std::string> titles; // To store the titles of books by the found author

	if (type != "book" && type != "author")
	{
		return;
	}

	for (int idx = 0; idx < books.size(); idx++)
	{
		// Check if the book's author matches the provided author
		if (books[idx].author == author)
		{
			// If the type is "book", also check if the book's title matches the provided title
			if (type == "book" && books[idx].title == title)
			{
				actionDone = true; // Flag that the action is done

				std::cout << "Title: " << title << "\tAuthor: " << author << "\tEdition: ";
				std::sort(books[idx].editions.begin(), books[idx].editions.end(), ascendingEdition);

				// Loop through the editions of the book and print them
				for (int editionIdx = 0; editionIdx < books[idx].editions.size(); editionIdx++)
				{
					std::cout << books[idx].editions[editionIdx];

					if (editionIdx == books[idx].editions.size() - 1)
					{
						std::cout << "\n";
					}
					else
					{
						std::cout << ", ";
					}
				}

				break;
			}
			// If the type is "author",store all the titles of the books by the author
			// in order to sort and print them later
			else
			{
				actionDone = true; // Flag that the action is done
				foundAuthor = books[idx].author;
				titles.push_back(books[idx].title);
			}
		}
	}

	// If the action is not done, it means the book or author was not found
	// Print an appropriate message based on the type of search
	if (!actionDone)
	{
		if (type == "book")
		{
			std::cout << "Book doesn't exist.\n";
		}
		else
		{
			std::cout << "No book found.\n";
		}
	}
	// If the find author action is done then sort the titles of the books by the author
	// and print them in ascending order
	else if (type == "author" && actionDone)
	{
		std::cout << foundAuthor << "'s Books: ";
		std::sort(titles.begin(), titles.end(), ascendingTitle);

		for (int idx = 0; idx < titles.size(); idx++)
		{
			std::cout << titles[idx];

			if (idx == titles.size() - 1)
			{
				std::cout << "\n";
			}
			else
			{
				std::cout << ", ";
			}
		}
	}
}

/**
 * Sorts the books based on the specified key (author or title) and prints them.
 *
 * \param key The key to sort by: "Author" to sort by author, "Title" to sort by title
 */
void Books::sort(std::string key)
{
	// If the key is author, sort the books by author and then by title if the authors are the same
	if (key == "Author")
	{
		std::sort(books.begin(), books.end(), ascendingByAuthorThenTitle);
	}
	// If the key is title, sort the books by title and then by author if the titles are the same
	else if (key == "Title")
	{
		std::sort(books.begin(), books.end(), ascendingByTitleThenAuthor);
	}
	// If the key is neither author nor title, return without sorting
	else
	{
		return;
	}

	// Print the sorted books
	for (Book book : books)
	{
		std::cout << "Title: " << book.title << "\tAuthor: " << book.author << "\tEdition: ";
		std::sort(book.editions.begin(), book.editions.end(), ascendingEdition);

		for (int idx = 0; idx < book.editions.size(); idx++)
		{
			std::cout << book.editions[idx];

			if (idx == book.editions.size() - 1)
			{
				std::cout << "\n";
			}
			else
			{
				std::cout << ", ";
			}
		}
	}
}
