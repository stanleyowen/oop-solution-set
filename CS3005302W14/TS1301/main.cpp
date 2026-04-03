/*****************************************************************//**
 * \file   main.cpp
 * \brief  Iterative and Recursive Binary Search
 *
 * \author Stanley Owen
 * \date   2025/5/21
 *********************************************************************/
#include "Template.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int ARRAY_SIZE = 8;
	const int finalIndex = ARRAY_SIZE - 1;

	int count = 0;
	cin >> count;

	// Loop for count times
	for (; count >= 1; count--)
	{
		int i; // Variables for loop index

		// Testcase 1: Test integer
		int a[] = { 1, 2, 3, 4, 10, 25, 29, 100 }; // The original array

		// Display the array
		cout << "\nArray contains:\n";
		for (i = 0; i < ARRAY_SIZE; i++)
		{
			cout << a[i];
			if (i != ARRAY_SIZE - 1)
			{
				cout << " ";
			}
		}
		cout << endl;

		int keyInt, location;
		bool found;

		// Prompt user for input
		cout << "Enter number to be located: ";
		cin >> keyInt;
		cout << endl;

		// Call the iterative binary search function
		cout << "Testing Template Iterative Binary Search\n";
		ItrBinarySearch(a, 0, finalIndex, keyInt, found, location);
		if (found)
		{
			cout << keyInt << " is in index location " << location << endl;
		}
		else
		{
			cout << keyInt << " is not in the array." << endl;
		}

		// Call the recursive binary search function
		cout << "Testing Template Recursive Binary Search\n";
		RecBinarySearch(a, 0, finalIndex, keyInt, found, location);
		if (found)
		{
			cout << keyInt << " is in index location " << location << endl;
		}
		else
		{
			cout << keyInt << " is not in the array." << endl;
		}

		// Testcase 2: Test string
		string b[] = { "aa", "ab", "ah", "bd", "be", "cc", "fe", "zk" };
		string keyString;

		// Display the array
		cout << "\nArray contains:\n";
		for (i = 0; i < ARRAY_SIZE; i++)
		{
			cout << b[i];
			if (i != ARRAY_SIZE - 1)
			{
				cout << " ";
			}
		}
		cout << endl;

		// Prompt user for input
		cout << "Enter number to be located: ";
		cin >> keyString;
		cout << endl;

		// Call the iterative binary search function
		cout << "Testing Template Iterative Binary Search\n";
		ItrBinarySearch(b, 0, finalIndex, keyString, found, location);
		if (found)
		{
			cout << keyString << " is in index location " << location << endl;
		}
		else
		{
			cout << keyString << " is not in the array." << endl;
		}

		// Call the recursive binary search function
		cout << "Testing Template Recursive Binary Search\n";
		RecBinarySearch(b, 0, finalIndex, keyString, found, location);
		if (found)
		{
			cout << keyString << " is in index location " << location << endl;
		}
		else
		{
			cout << keyString << " is not in the array." << endl;
		}

		// Testcase 3: Test double
		double c[] = { 0.3, 5.6, 7.8, 10.9, 123.5, 150.1, 197.1, 2019.2 };
		double keyDouble;

		// Display the array
		cout << "\nArray contains:\n";
		for (i = 0; i < ARRAY_SIZE; i++)
		{
			cout << c[i];
			if (i != ARRAY_SIZE - 1)
			{
				cout << " ";
			}
		}
		cout << endl;

		// Prompt user for input
		cout << "Enter number to be located: ";
		cin >> keyDouble;
		cout << endl;

		// Call the iterative binary search function
		cout << "Testing Template Iterative Binary Search\n";
		ItrBinarySearch(c, 0, finalIndex, keyDouble, found, location);
		if (found)
		{
			cout << keyDouble << " is in index location " << location << endl;
		}
		else
		{
			cout << keyDouble << " is not in the array." << endl;
		}

		// Call the recursive binary search function
		cout << "Testing Template Recursive Binary Search\n";
		RecBinarySearch(c, 0, finalIndex, keyDouble, found, location);
		if (found)
		{
			cout << keyDouble << " is in index location " << location << endl;
		}
		else
		{
			cout << keyDouble << " is not in the array." << endl;
		}
	}

	return 0;
}
