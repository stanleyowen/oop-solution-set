/*****************************************************************//**
 * \file   School.cpp
 * \brief  The implementation of the School class
 *
 * \author Stanley Owen
 * \date   2025/5/11
 *********************************************************************/
#include "School.h"

 // Default constructor
 // Initializes the School with an empty name, 0 students, and 0 students next year
School::School() : schoolName(""), studentAmount(0), studentAmountNextYear(0) {
};

/**
 *  Initializes the School with a name, current number of students, and next year's number of students
 *
 * \param schoolName The name of the school
 * \param studentAmount The current number of students in the school
 */
School::School(std::string schoolName, long long studentAmount)
	: schoolName(schoolName)
	, studentAmount(studentAmount)
	, studentAmountNextYear(studentAmount) {
};

/**
 * Adds a specified number of students to the school
 *
 * \param amount The number of students to add
 */
void School::admissions(float amount)
{
	if (amount > 0)
	{
		studentAmount += amount;
	}
}

/**
 * Subtracts a specified number of students from the school
 *
 * \param amount The number of students to drop out
 */
void School::dropouts(float amount)
{
	// Check if the amount is valid
	if (amount > 0 && amount <= studentAmount)
	{
		studentAmount -= amount;
	}
}

/**
 * Transfers a specified number of students from this school to another school
 *
 * \param amount The number of students to transfer
 * \param toSchool The school to transfer students to
 */
void School::transfer(float amount, School& toSchool)
{
	// Check if the amount is valid
	if (amount > 0 && amount <= studentAmount)
	{
		dropouts(amount);			 // Subtract the number of students who transferred out
		toSchool.admissions(amount); // Add the number of students who transferred in
	}
}

/**
 * Prints the School object to the output stream
 *
 * \param stream The output stream to print to
 * \param school The School object to print
 * \return The output stream
 */
std::ostream& operator<<(std::ostream& stream, const School& school)
{
	// Print the school name, current number of students, and next year's number of students
	stream << school.schoolName << "\t" << school.studentAmount << "\t" << school.studentAmountNextYear;
	return stream;
};
