/*****************************************************************//**
 * \file   Source.cpp
 * \brief  Matrix multiplication of two matrices
 *
 * \author Stanley Owen
 * \date   2025/4/30
 *********************************************************************/
#include <iostream>
#include <vector>

 /**
  * Reads input from the user and fills the target vector with the specified number of rows and columns
  *
  * \param rowVector The number of rows in the matrix
  * \param colVector The number of columns in the matrix
  * \param targetVector The vector to be filled with input values
  */
void readInputToVector(int rowVector, int colVector, std::vector<std::vector<int>>& targetVector)
{
	// Resize the target vector to the specified number of rows
	targetVector.resize(rowVector);

	// Loop through each row and column to read input values and fill the vector
	for (int row = 0; row < rowVector; row++)
	{
		for (int col = 0; col < colVector; col++)
		{
			int inputNumber;

			std::cin >> inputNumber;

			targetVector[row].push_back(inputNumber);
		}
	}
}

int main()
{
	int rowVectorA, colVectorA, rowVectorB, colVectorB;
	std::vector<std::vector<int>> firstVector, secondVector, resultVector;

	// Read the dimensions of the matrices from the input until EOF
	while (std::cin >> rowVectorA >> colVectorA >> rowVectorB >> colVectorB)
	{
		// CAUTION: Allow the user to enter the matrix values although the dimensions are not equal
		readInputToVector(rowVectorA, colVectorA, firstVector);	 // Read first matrix
		readInputToVector(rowVectorB, colVectorB, secondVector); // Read second matrix

		// Check if the matrices can be multiplied
		if (colVectorA == rowVectorB)
		{
			// Initialize the result vector with the appropriate size (rowVectorA x colVectorB)
			resultVector = std::vector<std::vector<int>>(rowVectorA, std::vector<int>(colVectorB, 0));

			// Perform matrix multiplication
			for (int rowA = 0; rowA < rowVectorA; rowA++)
			{
				for (int colB = 0; colB < colVectorB; colB++)
				{
					for (int i = 0; i < colVectorA; i++)
					{
						// Multiply the corresponding elements and accumulate the result
						resultVector[rowA][colB] += firstVector[rowA][i] * secondVector[i][colB];
					}
				}
			}

			// Print the result of the matrix multiplication
			for (int row = 0; row < resultVector.size(); row++)
			{
				for (int col = 0; col < resultVector[row].size(); col++)
				{
					std::cout << resultVector[row][col];

					// CAUTION: Avoid printing a space after the last element
					if (col != resultVector[row].size() - 1)
					{
						std::cout << " ";
					}
				}

				std::cout << "\n";
			}
		}
		else
		{
			// Print an error message if the matrices cannot be multiplied
			std::cout << "Matrix multiplication failed.\n";
		}
	}
}
