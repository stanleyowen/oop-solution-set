/*****************************************************************//**
 * \file   Point.cpp
 * \brief  The implementation of the Point class
 *
 * \author Stanley Owen
 * \date   2025/3/13
 *********************************************************************/
#include "Point.h"

 /**
  * Set the coordinate position of the point by the given x and y values
  *
  * \param vertical The vertical value of the point (x)
  * \param horizontal The horizontal value of the point (y)
  */
void Point::Set(int vertical, int horizontal)
{
	this->vertical = vertical;
	this->horizontal = horizontal;
}

/**
 * Move the current point x on the x-axis and y on the y-axis
 *
 * \param x The value to move the point on the x-axis
 * \param y The value to move the point on the y-axis
 */
void Point::Move(int x, int y)
{
	this->vertical += x;
	this->horizontal += y;
}

// Rotate the point 90 degrees clockwise from the origin
void Point::Rotate()
{
	// Swap the x and y values of the point
	// The new x value will be the old y value
	// The new y value will be the negative of the old x value
	int temp = horizontal;

	this->horizontal = -vertical;
	this->vertical = temp;
}
