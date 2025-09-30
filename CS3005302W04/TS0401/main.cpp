/*****************************************************************//**
 * \file   main.cpp
 * \brief  Manipulating the position of a point on the x and y
 *		   coordinate
 *
 * \author Stanley Owen
 * \date   2025/3/13
 *********************************************************************/
#include <iostream>
#include "Point.h" // Include the header file

using namespace std;

int main(void)
{
	// Create a coordinate point object
	Point point;

	// Set the coordinate point to (0, 5)
	point.Set(0, 5);

	// Retrieve the vertical (x) and horizontal (y) values of the point
	cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl;

	// Move the coordinate point by (1, 2)
	point.Move(1, 2);

	// Retrieve the vertical (x) and horizontal (y) values of the point after moving
	cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl;

	// Rotate the point 90 degrees clockwise from the origin for 4 times
	// Retrieve the vertical (x) and horizontal (y) values of the point after rotating
	for (int i = 0; i < 4; i++)
	{
		point.Rotate();
		cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl;
	}

	return 0;
}