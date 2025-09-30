/*****************************************************************//**
 * \file   HotDogStand.cpp
 * \brief  The implementation of the HotDogStand class
 *
 * \author Stanley Owen
 * \date   2025/3/20
 *********************************************************************/
#include "HotDogStand.h"

 // Initialize the static variable
int HotDogStand::totalSellAmount = 0;

/**
 * Set the default value if the constructor is called wihout the amount parameter
 *
 * \param id The id of the hot dog stand
 */
HotDogStand::HotDogStand(const char* id) : hotDogSellAmount(0)
{
	// Resize the standId size to the length of the id + 1
	standId = new char[strlen(id) + 1];
	// Copy the id to the standId
	memcpy(standId, id, strlen(id) + 1);
}

/**
 * Set the value of the stand id and amount of the constructor by the given
 * parameter
 *
 * \param id The id of the hot dog stand
 * \param amount The amount of hot dogs sold
 */
HotDogStand::HotDogStand(const char* id, int amount) : hotDogSellAmount(amount)
{
	// Resize the standId size to the length of the id + 1
	standId = new char[strlen(id) + 1];
	// Copy the id to the standId
	memcpy(standId, id, strlen(id) + 1);

	// Add the amount to the totalSellAmount
	this->totalSellAmount += amount;
}

// Destructor
HotDogStand::~HotDogStand()
{
}

// Increase the hot dog sales amount by 1
void HotDogStand::justSold()
{
	this->hotDogSellAmount++;
	this->totalSellAmount++;
}

// Print the stand id and the amount of the hot dog sales of the current stand
void HotDogStand::print()
{
	std::cout << standId << " " << hotDogSellAmount << "\n";
}

// Print all the hot dog sales amount of all stands
int HotDogStand::allStandSoldAmount()
{
	return totalSellAmount;
}
