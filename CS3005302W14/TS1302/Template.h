/*****************************************************************//**
 * \file   Template.h
 * \brief  Header file for Absolute Value function
 *
 * \author Stanley Owen
 * \date   2025/5/21
 *********************************************************************/
#pragma once

 /**
  * Function to calculate the absolute value of the difference between two variables
  *
  * \param firstVariable The first variable
  * \param secondVariable The second variable
  * \return The absolute value of the difference
  * \note Return the double type instead of T type since double itself can contain
  * 		 integer. Using T instead of double for char will cause the function to
  * 		 parse the char as strange output.
  */
template <typename Type>
double absoluteValue(Type firstVariable, Type secondVariable)
{
	double difference = static_cast<double>(firstVariable - secondVariable);

	// Return the absolute value of the difference
	if (difference < 0)
	{
		return difference * -1;
	}
	else
	{
		return difference;
	}
}
