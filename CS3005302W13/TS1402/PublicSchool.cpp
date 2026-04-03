/*****************************************************************//**
 * \file   PublicSchool.cpp
 * \brief  The implementation of the PublicSchool class
 *
 * \author Stanley Owen
 * \date   2025/5/11
 *********************************************************************/
#include "PublicSchool.h"

 // Default constructor
 // Initializes the PublicSchool with a name and number of students and sets the growing rate to 0.05
PublicSchool::PublicSchool() : School(), growingRate(0.05)
{
};

/**
 * Initializes the PublicSchool with a name, number of students, and a growing rate
 *
 * \param schoolName The name of the school
 * \param studentAmount The number of students in the school
 */
PublicSchool::PublicSchool(std::string schoolName, long long studentAmount)
	: School(schoolName, studentAmount), growingRate(0.05)
{
};

// The growth rate of the students each year
void PublicSchool::apply_growth()
{
	studentAmountNextYear += growingRate * studentAmountNextYear;
}

/**
 * Substracts a specified number of students from the school. If the number of students is greater than 100,
 * the number of students next year is also reduced 5% of the number of students next year.
 *
 * \param amount The number of students to drop out
 */
void PublicSchool::dropouts(float amount)
{
	// Check if the amount is valid
	if (amount > 0 && amount <= studentAmount)
	{
		studentAmount -= amount; // Subtract the number of students who dropped out

		if (amount > 100)
		{
			// Subtract 5% from the number of students next year if the amount is greater than 100
			studentAmountNextYear -= growingRate * studentAmountNextYear;
		}
	}
}

/**
 * Prints the PublicSchool object to the output stream
 *
 * \param stream The output stream to print to
 * \param school The PublicSchool object to print
 * \return The output stream
 */
std::ostream& operator<<(std::ostream& stream, const PublicSchool& school)
{
	stream << static_cast<const School&>(school); // Call the base class operator<<
	return stream;
}
