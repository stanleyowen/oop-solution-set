/*****************************************************************//**
 * \file   Source.cpp
 * \brief  Program to manage a collection of books
 *
 * \author Stanley Owen
 * \date   2025/5/28
 *********************************************************************/
#include "Books.h"
#include <iostream>
#include <string>
#include <sstream>

int main()
{
	Books books;			  // Instance of the Books class to manage the collection
	std::string inputCommand; // Variable to hold user input commands

	while (std::getline(std::cin, inputCommand))
	{
		// IMPORTANT: Avoid showing error when input is enter
		if (inputCommand.empty())
		{
			continue;
		}

		std::string command; // The first word of the command
		std::istringstream stringstream(inputCommand);
		stringstream >> command;

		if (command == "Insert")
		{
			char c; // Used to skip quotation symbol
			int edition;
			std::string title, author;

			stringstream >> c;
			// IMPORTANT: Use '"' instead of "\""
			std::getline(stringstream, title, '"');
			stringstream >> c;
			std::getline(stringstream, author, '"');
			stringstream >> edition;

			// Output an error message if the title, author, or edition is empty
			if (title.empty() || author.empty() || !edition)
			{
				std::cout << "Incomplete Command.\n";
			}
			// Otherwise, insert the book into the collection
			else
			{
				books.insert(title, author, edition);
			}
		}
		else if (command == "Delete")
		{
			char c; // Used to skip quotation symbol
			int edition;
			std::string secondCommand, title, author;

			stringstream >> secondCommand;
			stringstream >> c;
			std::getline(stringstream, title, '"');
			stringstream >> c;
			std::getline(stringstream, author, '"');
			stringstream >> edition;

			// Check if the second command is "Edition" or "Book"
			if (secondCommand == "Edition" && !title.empty() && !author.empty() && edition)
			{
				// If the second command is "Edition", delete the specific edition of the book
				books.deletion(title, author, edition, "edition");
			}
			else if (secondCommand == "Book" && !title.empty() && !author.empty())
			{
				// If the second command is "Book", delete the entire book
				books.deletion(title, author, 0, "book");
			}
			else
			{
				// Output an error message if the command is incomplete
				std::cout << "Incomplete Command.\n";
			}
		}
		else if (command == "Find")
		{
			char c; // Used to skip quotation symbol
			std::string secondCommand, title, author;
			stringstream >> secondCommand;

			// Find a book or an author based on the second command
			if (secondCommand == "Book")
			{
				stringstream >> c;
				std::getline(stringstream, title, '"');
				stringstream >> c;
				std::getline(stringstream, author, '"');

				// Check if both title and author are provided
				// If either is empty, output an error message
				// Otherwise, find the book in the collection
				if (title.empty() || author.empty())
				{
					std::cout << "Incomplete Command.\n";
				}
				else
				{
					books.find(title, author, "book");
				}
			}
			else if (secondCommand == "Author")
			{
				stringstream >> c;
				std::getline(stringstream, author, '"');

				// Check if the author is provided
				// If empty, output an error message
				// Otherwise, find all books by the author in the collection
				if (author.empty())
				{
					std::cout << "Incomplete Command.\n";
				}
				else
				{
					// Pass the empty title since we are looking for all books by the author
					books.find("", author, "author");
				}
			}
			else
			{
				// If the second command is neither "Book" nor "Author", output an error message
				std::cout << "Incomplete Command.\n";
			}
		}
		else if (command == "Sort")
		{
			char c; // Used to skip quotation symbol
			std::string secondCommand, key;
			stringstream >> secondCommand;

			if (secondCommand == "by")
			{
				stringstream >> key;

				// Check if the key is provided
				if (key.empty())
				{
					std::cout << "Incomplete Command.\n";
				}
				else
				{
					// If the key is "Author" or "Title", sort the books accordingly
					books.sort(key);
				}
			}
			else
			{
				// If the second command is not "by", output an error message
				std::cout << "Incomplete Command.\n";
			}
		}
		else
		{
			// If the command is not recognized, output an error message
			std::cout << "Unknown Command.\n";
		}
	}
}
