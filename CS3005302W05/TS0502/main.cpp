/*****************************************************************//**
 * \file   main.cpp
 * \brief  Validate and display the month name based on the given
 *		   month number or abbreviation
 *
 * \author Stanley Owen
 * \date   2025/3/20
 *********************************************************************/
#include "Month.h" // Include the header file

using namespace std;

int main(void)
{
	// Create Month objects
	Month month1, month2(12), month3('M', 'a', 'r'), month4, month5, month6;

	month4 = month2.nextMonth(); // Get the next month of month2
	month5.inputInt();			 // Input the month number
	month6.inputStr();			 // Input the abbreviation of the month

	cout << "Month1 = ";
	month1.outputInt();
	cout << ' ';
	month1.outputStr();
	cout << endl;

	cout << "Month2 = ";
	month2.outputInt();
	cout << ' ';
	month2.outputStr();
	cout << endl;

	cout << "Month3 = ";
	month3.outputInt();
	cout << ' ';
	month3.outputStr();
	cout << endl;

	cout << "Month4 = ";
	month4.outputInt();
	cout << ' ';
	month4.outputStr();
	cout << endl;

	cout << "Month5 = ";
	month5.outputInt();
	cout << ' ';
	month5.outputStr();
	cout << endl;

	cout << "Month6 = ";
	month6.outputInt();
	cout << ' ';
	month6.outputStr();
	cout << endl;

	return 0;
}