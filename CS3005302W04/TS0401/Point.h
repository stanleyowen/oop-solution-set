/*****************************************************************//**
 * \file   Point.h
 * \brief  The header file for the Point class
 *
 * \author Stanley Owen
 * \date   2025/3/13
 *********************************************************************/
#ifndef Point_H
#define Point_H

#include <iostream>

using namespace std;

class Point
{
private:
	int vertical;	// x-coordinate
	int horizontal; // y-coordinate

public:
	Point() // Default constructor
	{
		vertical = 0;	// x-coordinate
		horizontal = 0; // y-coordinate
	}

	void Set(int vertical, int horizontal);				  // Set the coordinate position of the point by the given x and y values
	void Move(int x, int y);							  // Move the current point x on the x-axis and y on the y-axis
	void Rotate();										  // Rotate the point 90 degrees clockwise from the current position

	int RetrieveVertical() const { return vertical; }	  // Retrieve the vertical value (x) of the point
	int RetrieveHorizontal() const { return horizontal; } // Retrieve the horizontal value (y) of the point
};

#endif // Point_H