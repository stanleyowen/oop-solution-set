/*****************************************************************//**
 * \file   PrivateSchool.h
 * \brief  Header file for the PrivateSchool class
 *
 * \author Stanley Owen
 * \date   2025/5/11
 *********************************************************************/
#pragma once
#include "School.h"

class PrivateSchool : public School
{
private:
	int dropoutWaveCount; // Number of dropout waves

public:
	// Default constructor
	PrivateSchool();
	// Initializes the PrivateSchool with a name and number of students
	PrivateSchool(std::string schoolName, long long studentAmount);

	// Subtracts a specified number of students from the school
	void dropouts(float amount) override;

	// Prints the PrivateSchool object to the output stream
	friend std::ostream& operator<<(std::ostream& stream, const PrivateSchool& school);
};