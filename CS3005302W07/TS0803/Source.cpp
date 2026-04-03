/*****************************************************************//**
 * \file   Source.cpp
 * \brief  Writing and reading from memory
 *
 * \author Stanley Owen
 * \date   2025/4/6
 *********************************************************************/
#include <iostream>
#include <vector>
#include <string>

 /**
  * Write to memory at the specified position with the given type and value.
  *
  * \param position The position in memory to write to.
  * \param type The type of data to write (char, short, int, String).
  * \param value The value to write to memory.
  * \param memory The memory vector to write to.
  */
void setMemory(unsigned int position, std::string type, std::string value, std::vector<unsigned char>& memory)
{
	bool isOverflow = false;

	// Determine the size of the data type and check for overflow
	if (type == "char")
	{
		if (position + 1 > memory.size())
		{
			isOverflow = true;
		}
		else
		{
			// IMPORTANT: Always convert char to int so that it can be previewed appropriately when reading from memory
			int res = std::stoi(value);

			// Convert the value to an unsigned char and write to memory
			memory[position] = static_cast<unsigned char>(res);
		}
	}
	else if (type == "short")
	{
		// CAUTION: If overflow, still write to memory until the end of the memory
		if (position + 2 > memory.size())
		{
			isOverflow = true;
		}

		// Convert the input from string to int and then to short
		short targetValue = static_cast<short>(std::stoi(value));
		// Take the minimum size of the short and the remaining memory size (if overflow)
		int size = std::min(sizeof(targetValue), memory.size() - position);

		// Copy the value to memory
		memcpy(&memory[position], &targetValue, size);
	}
	else if (type == "int")
	{
		// CAUTION: If overflow, still write to memory until the end of the memory
		if (position + 4 > memory.size())
		{
			isOverflow = true;
		}

		// IMPORTANT: Convert the input from string to unsigned long first to avoid TLE
		unsigned int targetValue = static_cast<unsigned int>(std::stoul(value));
		// Take the minimum size of the int and the remaining memory size (if overflow)
		int size = std::min(sizeof(targetValue), memory.size() - position);

		// Copy the value to memory
		memcpy(&memory[position], &targetValue, size);
	}
	else if (type == "String")
	{
		std::string temp;

		// IMPORTANT: Omit the space in the string
		// Loop through the string and only add non-space characters to the temp string
		for (int i = 0; i < value.length(); i++)
		{
			if (temp[i] != ' ')
			{
				temp += value[i];
			}
		}

		int length = temp.length();
		// Take the minimum size of the string and the remaining memory size (if overflow)
		int size = std::min(length, (int)memory.size() - (int)position);

		// CAUTION: If overflow, still write to memory until the end of the memory
		// If the length of the string is greater than the remaining memory size, set isOverflow to true
		if (memory.size() - position < temp.length())
		{
			isOverflow = true;
		}

		// Copy the string to memory
		memcpy(&memory[position], temp.c_str(), size);

		// IMPORTANT: If the string does not overflow, add a null terminator at the end of the string
		if (!isOverflow)
		{
			memory[position + length] = '\0';
		}
	}

	// Ouput warning message if overflow occurs
	if (isOverflow)
	{
		std::cout << "Violation Access.\n";
	}
}

/**
 * Read from memory at the specified position with the given type.
 *
 * \param position The position in memory to read from.
 * \param type The type of data to read (char, short, int, String).
 * \param memory The memory vector to read from.
 */
void getMemory(unsigned int position, std::string type, std::vector<unsigned char>& memory)
{
	bool isOverflow = false;

	// Check for overflow based on the type of data being read
	if (type == "char")
	{
		if (position + 1 > memory.size() || memory.size() < 1)
		{
			isOverflow = true;
		}
		else
		{
			// Convert the char value to an int for appropriate preview
			std::cout << (int)memory[position] << "\n";
		}
	}
	else if (type == "short")
	{
		if (position + 2 > memory.size() || memory.size() < 2)
		{
			isOverflow = true;
		}
		else
		{
			// IMPORTANT: Use unsigned short to extend the range of the short value
			// since very large values may result in -1
			unsigned short result; // Temporary variable to store the result

			// Copy the memory content to the result variable
			memcpy(&result, &memory[position], sizeof(unsigned short));

			std::cout << result << "\n";
		}
	}
	else if (type == "int")
	{
		if (position + 3 > memory.size() || memory.size() < 4)
		{
			isOverflow = true;
		}
		else
		{
			int result; // Temporary variable to store the result

			// Copy the memory content to the result variable
			memcpy(&result, &memory[position], sizeof(int));

			std::cout << result << "\n";
		}
	}
	else if (type == "String")
	{
		std::string result; // Temporary variable to store the result

		// Loop from the given position to the end of the memory
		for (int i = position; i < memory.size(); i++)
		{
			// Stop reading if the null terminator is found
			if (memory[i] == '\0')
			{
				break;
			}

			// Append the character to the result string
			result += memory[i];
		}

		std::cout << result << "\n";
	}

	// Output warning message if overflow occurs
	if (isOverflow)
	{
		std::cout << "Violation Access.\n";
	}
}

int main()
{
	unsigned int memorySize;

	// Read the input for the size of the memory until the end of the file
	// and create a vector of unsigned char with the given size
	while (std::cin >> memorySize)
	{
		unsigned int numberOfCommands;
		std::vector<unsigned char> memory(memorySize, 0);

		// Ask the user for the number of commands to be executed
		std::cin >> numberOfCommands;

		// Ask for numberOfCommands times for the command to be executed
		for (int currentCount = 0; currentCount < numberOfCommands; currentCount++)
		{
			unsigned int position;
			std::string instructionType, type, value;

			// Read the instruction type (Set or Get) first
			std::cin >> instructionType;

			// If the instruction type is Set, read the position, type, and value
			// If the instruction type is Get, read the position and type
			// and call the appropriate function to set or get memory
			if (instructionType == "Set")
			{
				std::cin >> position >> type;
				// IMPORTANT: Ignore the previous input so that the next input can be read correctly using getline method
				std::cin.ignore();
				std::getline(std::cin, value);

				// Call the setMemory function to write to memory
				setMemory(position, type, value, memory);
			}
			else if (instructionType == "Get")
			{
				std::cin >> position >> type;

				// Call the getMemory function to read from memory
				getMemory(position, type, memory);
			}
		}
	}

	return 0;
}
