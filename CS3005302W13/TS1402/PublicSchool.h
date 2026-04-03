/*****************************************************************//**
 * \file   PublicSchool.h
 * \brief  Header file for the PublicSchool class
 *
 * \author Stanley Owen
 * \date   2025/5/11
 *********************************************************************/
#pragma once
#include "School.h"

class PublicSchool : public School
{
private:
	float growingRate; // Growth rate of the school

public:
	// Default constructor
	PublicSchool();
	// Initializes the PublicSchool with a name, number of students, and a growing rate
	PublicSchool(std::string schoolName, long long studentAmount);

	void apply_growth();				  // The growth rate of the students each year
	void dropouts(float amount) override; // Subtracts a specified number of students from the school

	// Prints the PublicSchool object to the output stream
	friend std::ostream& operator<<(std::ostream& stream, const PublicSchool& school);
};
