/*****************************************************************//**
 * \file   Source.cpp
 * \brief  Using the set STL to read names from a file and remove
 *		   duplicates
 *
 * \author Stanley Owen
 * \date   2025/5/28
 *********************************************************************/
#include <set>
#include <string>
#include <fstream>
#include <iostream>

int main()
{
	std::string recipientName;			   // Variable to hold each name read from the file
	std::set<std::string> recipients;	   // Set to store names, automatically handles duplicates
	std::ifstream fileContent("name.txt"); // Open the file containing names

	while (std::getline(fileContent, recipientName))
	{
		// IMPORTANT: Set automatically removes duplicate
		recipients.insert(recipientName);
	}

	fileContent.close();

	// Output the unique names to the console
	for (const auto& name : recipients)
	{
		std::cout << name << std::endl;
	}
}
