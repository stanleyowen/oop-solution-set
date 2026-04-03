/*****************************************************************//**
 * \file   School.h
 * \brief  Header file for the School class
 *
 * \author Stanley Owen
 * \date   2025/5/11
 *********************************************************************/
#pragma once
#include <string>
#include <sstream>

class School
{
protected:
	std::string schoolName;			 // Name of the school
	long long studentAmount;		 // Current number of students
	long long studentAmountNextYear; // Number of students next year

public:
	// Default constructor
	School();
	// Initializes the School with a name, current number of students, and next year's number of students
	School(std::string schoolName, long long studentAmount);

	void admissions(float amount); // Add students to the school
	// IMPORTANT: Ensure this is virtual to allow derived classes to override it
	virtual void dropouts(float amount);		   // Remove students from the school
	void transfer(float amount, School& toSchool); // Transfer students to another school

	// Print the school information
	friend std::ostream& operator<<(std::ostream& stream, const School& school);
};

// IMPORTANT: Include the derived classes here to include them in the compilation
#include "PrivateSchool.h"
#include "PublicSchool.h"
