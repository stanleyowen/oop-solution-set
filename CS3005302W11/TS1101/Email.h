/*****************************************************************//**
 * \file   Email.h
 * \brief  Header file for Email class using Document inheritance
 *
 * \author Stanley Owen
 * \date   2025/4/30
 *********************************************************************/
#pragma once

#include "Document.h"

class Email : public Document
{
protected:
	std::string sender;
	std::string recipient;
	std::string title;

public:
	// Initialize the Email object with the given body, sender, recipient, and title
	Email(std::string body, std::string sender, std::string recipient, std::string title);

	// CAUTION: Remember to implement accessor and mutator
	void setSender(std::string sender);		  // Set the sender of the email
	void setRecipient(std::string recipient); // Set the recipient of the email
	void setTitle(std::string title);		  // Set the title of the email

	std::string getSender() const;	  // Get the sender of the email
	std::string getRecipient() const; // Get the recipient of the email
	std::string getTitle() const;	  // Get the title of the email

	Email operator=(Email email); // Assignment operator
};
