/*****************************************************************//**
 * \file   main.cpp
 * \brief  Counting the number of hot dogs sold by each stand and
 *		   the total number of hot dogs sold
 *
 * \author Stanley Owen
 * \date   2025/3/20
 *********************************************************************/
#include <iostream>
#include "HotDogStand.h" // Include the header file

using namespace std;

int main()
{
	HotDogStand stand1("Stand1", 0);   // Create a HotDogStand object with id Stand1 and amount 0
	HotDogStand stand2("Stand2", 100); // Create a HotDogStand object with id Stand2 and amount 100
	HotDogStand stand3("Stand3");	   // Create a HotDogStand object with id Stand3 and amount 0

	stand1.justSold(); // Increase the sell amount of Stand1 by 1
	stand2.justSold(); // Increase the sell amount of Stand2 by 1
	stand3.justSold(); // Increase the sell amount of Stand3 by 1
	stand1.print();	   // Print the standId and hotDogSellAmount of Stand1
	stand2.print();	   // Print the standId and hotDogSellAmount of Stand2
	stand3.print();	   // Print the standId and hotDogSellAmount of Stand3

	// Print the total sell amount of all stands
	std::cout << "Total Sold : " << HotDogStand::allStandSoldAmount() << std::endl;

	return 0;
}