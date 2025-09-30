/*****************************************************************//**
 * \file   HotDogStand.h
 * \brief  The header file of the HotDogStand class
 *
 * \author Stanley Owen
 * \date   2025/3/20
 *********************************************************************/
#ifndef HotDogStand_H
#define HotDogStand_H

#include <iostream>
#include <cstring>

class HotDogStand
{
public:
	HotDogStand();							 // Default constructor
	HotDogStand(const char* id);			 // Constructor with id
	HotDogStand(const char* id, int amount); // Constructor with id and amount
	~HotDogStand();							 // Destructor

	void justSold(); // Increase the hotDogSellAmount by 1
	void print();	 // Print the standId and hotDogSellAmount

	int thisStandSoldAmount() const // Return the each stand's sell amount
	{
		return hotDogSellAmount;
	};
	static int allStandSoldAmount(); // Return the total sell amount of all stands

private:
	char* standId;
	int hotDogSellAmount;
	static int totalSellAmount;
};

#endif // HotDogStand_H
