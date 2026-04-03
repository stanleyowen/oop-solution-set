/*****************************************************************//**
 * \file   File.h
 * \brief  Header file for File class using Document inheritance
 *
 * \author Stanley Owen
 * \date   2025/4/30
 *********************************************************************/
#pragma once

#include "Document.h"

class File : public Document
{
protected:
	std::string path;

public:
	// Constructor with description and path parameters
	File(std::string description, std::string path);

	void setPathname(std::string path); // Set the path of the file
	std::string getPathname() const;	// Get the path of the file

	File operator=(File file); // Assignment operator
};
