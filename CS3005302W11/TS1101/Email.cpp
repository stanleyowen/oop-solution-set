/*****************************************************************//**
 * \file   Email.cpp
 * \brief  The implementation file for Email class using Document inheritance
 *
 * \author Stanley Owen
 * \date   2025/4/30
 *********************************************************************/
#include "Email.h"

 /**
  * Constructor to initialize the Email object with the given body, sender, recipient, and title
  *
  * \param body The body of the email
  * \param sender The sender of the email
  * \param recipient The recipient of the email
  * \param title The title of the email
  */
Email::Email(std::string body, std::string sender, std::string recipient, std::string title) :
	Document(body), sender(sender), recipient(recipient), title(title)
{
};

/**
 * Sets the sender of the email
 *
 * \param sender The sender of the email
 */
void Email::setSender(std::string sender)
{
	this->sender = sender;
};

/**
 * Sets the recipient of the email
 *
 * \param recipient The recipient of the email
 */
void Email::setRecipient(std::string recipient)
{
	this->recipient = recipient;
};

/**
 * Sets the title of the email
 *
 * \param title The title of the email
 */
void Email::setTitle(std::string title)
{
	this->title = title;
}

/**
 * Gets the sender of the email
 *
 * \return The sender of the email
 */
std::string Email::getSender() const
{
	return sender;
};

/**
 * Gets the recipient of the email
 *
 * \return The recipient of the email
 */
std::string Email::getRecipient() const
{
	return recipient;
};

/**
 * Gets the title of the email
 *
 * \return The title of the email
 */
std::string Email::getTitle() const
{
	return title;
};

/**
 * Assignment operator overload
 *
 * \param email The Email object to be assigned
 * \return A reference to the current Email object
 */
Email Email::operator=(Email email)
{
	this->text = email.text;
	this->sender = email.sender;
	this->recipient = email.recipient;
	this->title = email.title;

	return *this;
}
