/*****************************************************************//**
 * \file   main.cpp
 * \brief  Test the Document, Email, and File classes
 *
 * \author Stanley Owen
 * \date   2025/4/30
 *********************************************************************/
#include "Document.h"
#include "Email.h"
#include "File.h"

#include <iostream>
#include <string>

using namespace std;

/*
 * Checks if the Document object contains a specific keyword in its text
 * \param docObject The Document object to check for the keyword
 * \param keyword The keyword to search for in the Document object
 * \return True if the keyword is found, false otherwise
 */
bool ContainsKeyword(const Document& docObject, string keyword)
{
	if (docObject.getText().find(keyword) != string::npos)
		return true;
	return false;
}

int main()
{
	// Create several test objects
	Email email1("Body about programming in C++",
		"Larry", "Curly", "Programming");
	Email email2("Body about running marathons",
		"Speedy", "Gonzales", "races");
	File file1("Contents about some C++ file", "file.txt");
	File file2("Contents about marathon races", "run.txt");

	// Check if the objects contain the keyword "C++"
	cout << "Which contains C++?" << endl;

	if (ContainsKeyword(email1, "C++"))
	{
		cout << " Email1" << endl;
	}

	if (ContainsKeyword(email2, "C++"))
	{
		cout << " Email2" << endl;
	}

	if (ContainsKeyword(file1, "C++"))
	{
		cout << " File1" << endl;
	}

	if (ContainsKeyword(file2, "C++"))
	{
		cout << " File2" << endl;
	}

	// Test our assignment operator
	file2 = file1;
	file2.setPathname("c:");

	cout << "After assignment file2=file1 and file2.setPathname(\"c:\"): " << endl;
	cout << "File1's path = " << file1.getPathname() << endl;
	cout << "File2's path = " << file2.getPathname() << endl;

	email2 = email1;

	cout << "After assignment file2=file1: " << endl;
	cout << "Email2's path = " << email2.getText() << " " << email2.getSender() << " " << email2.getRecipient() << " " << email2.getTitle() << endl;

	return 0;
}
