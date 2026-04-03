/*****************************************************************//**
 * \file   File.cpp
 * \brief  Implementation of File class using Document inheritance
 *
 * \author Stanley Owen
 * \date   2025/4/30
 *********************************************************************/
#include "File.h"

 /**
  * Initializes the File object with the given description and path
  *
  * \param description The description of the file
  * \param path The path of the file
  */
File::File(std::string description, std::string path) : Document(description), path(path)
{
}

/**
 * Sets the path of the file
 *
 * \param path The path of the file
 */
void File::setPathname(std::string path)
{
	this->path = path;
}

/**
 * Gets the path of the file
 *
 * \return The path of the file
 */
std::string File::getPathname() const
{
	return path;
}

/**
 * Assignment operator overload
 *
 * \param file The File object to be assigned
 * \return A reference to the current File object
 */
File File::operator=(File file)
{
	this->text = file.text;
	this->path = file.path;

	return *this;
}
