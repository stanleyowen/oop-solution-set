/*****************************************************************//**
 * \file   main.cpp
 * \brief  The school class and its derived classes
 *
 * \author Stanley Owen
 * \date   2025/5/11
 *********************************************************************/
#include "School.h"
#include <string>
#include <iostream>

int main()
{
	// Initialize 3 schools with different types
	School ntust("NTUST", 12500);
	PublicSchool ntut("NTUT", 85000);
	PrivateSchool fjcu("FJCU", 25000);

	// Print the initial state of the schools
	std::cout << ntust << std::endl;
	std::cout << ntut << std::endl;
	std::cout << fjcu << std::endl;

	// Test all methods on School
	ntust.admissions(200);
	std::cout << ntust << std::endl;

	ntust.dropouts(200);
	std::cout << ntust << std::endl;

	ntust.dropouts(100000);
	std::cout << ntust << std::endl;

	// Test all methods on PrivateSchool
	fjcu.admissions(1000);
	std::cout << fjcu << std::endl;

	fjcu.dropouts(50);
	std::cout << fjcu << std::endl;

	fjcu.dropouts(1000);
	std::cout << fjcu << std::endl;

	// Test all methods on PublicSchool
	ntut.admissions(1000);
	std::cout << ntut << std::endl;

	ntut.apply_growth();
	std::cout << ntut << std::endl;

	ntut.dropouts(1000);
	std::cout << ntut << std::endl;

	// Transfer method
	std::cout << ntut << std::endl;
	ntut.transfer(1000, ntust);

	std::cout << ntut << std::endl;
	std::cout << ntust << std::endl;

	fjcu.transfer(30000, ntust);
	std::cout << fjcu << std::endl;
	std::cout << ntust << std::endl;

	return 0;
}