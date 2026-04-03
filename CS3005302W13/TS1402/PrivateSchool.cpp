/*****************************************************************//**
 * \file   PrivateSchool.cpp
 * \brief  Implementation of the PrivateSchool class
 *
 * \author Stanley Owen
 * \date   2025/5/11
 *********************************************************************/
#include "PrivateSchool.h"

 // Default constructor
PrivateSchool::PrivateSchool() : School(), dropoutWaveCount(0) {
};

/**
 * Initializes the PrivateSchool with a name, number of students, and dropout wave count
 *
 * \param schoolName The name of the school
 * \param studentAmount The number of students in the school
 */
PrivateSchool::PrivateSchool(std::string schoolName, long long studentAmount)
	: School(schoolName, studentAmount), dropoutWaveCount(0)
{
};

/**
 * Subtracts a specified number of students from the school. If the wave count is greater than 1,
 * the number of students next year is also reduced by 100.
 *
 * \param amount The number of students to drop out
 */
void PrivateSchool::dropouts(float amount)
{
	// Check if the amount is valid
	if (amount > 0 && amount <= studentAmount)
	{
		dropoutWaveCount++;		 // Increment the dropout wave count
		studentAmount -= amount; // Subtract the number of students who dropped out

		// Subtract 100 from the number of students next year if the dropout wave count is greater than 1
		if (dropoutWaveCount > 1)
		{
			studentAmountNextYear -= 100;
		}
	}
};

/**
 * Prints the PrivateSchool object to the output stream
 *
 * \param stream The output stream to print to
 * \param school The PrivateSchool object to print
 * \return The output stream
 */
std::ostream& operator<<(std::ostream& stream, const PrivateSchool& school)
{
	stream << static_cast<const School&>(school); // Call the base class operator<<
	return stream;
}