/*****************************************************************//**
 * \file   Document.cpp
 * \brief  Header file for Document class
 *
 * \author Stanley Owen
 * \date   2025/4/30
 *********************************************************************/
#include "Document.h"

 // Default constructor
 // Initializes the text to an empty string
Document::Document() : text("") {
};

/**
 * Initializes the Document object with the given text
 *
 * \param text The text to be stored in the Document object
 */
Document::Document(std::string text) : text(text) {
};

/**
 * Gets the text stored in the Document object
 *
 * \return The text stored in the Document object
 */
std::string Document::getText() const
{
	return this->text;
}

/**
 * Assignment operator overload
 *
 * \param document The Document object to be assigned
 * \return A reference to the current Document object
 */
Document Document::operator=(Document document)
{
	this->text = document.text;

	return *this;
}
