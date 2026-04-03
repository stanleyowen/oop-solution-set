/*****************************************************************//**
 * \file   Source.cpp
 * \brief  Multiplication of two matrices
 *
 * \author Stanley Owen
 * \date   2025/4/6
 *********************************************************************/
#include <iostream>
#include <vector>

#define DEFAULT_BLANK_VALUE 0

 /**
  * Ask the user to input the vector values and store them in the vector.
  *
  * \param vector The vector to store the input values.
  */
void readInputVector(std::vector<std::vector<long long>>& vector)
{
	// Loop through the size of the vector and ask the user to input the values
	for (int row = 0; row < vector.size(); row++)
	{
		for (int col = 0; col < vector[row].size(); col++)
		{
			std::cin >> vector[row][col];
		}
	}
}

/**
 * Calculate the product of two vectors and store the result in the result vector.
 *
 * \param vectorA The first vector.
 * \param vectorB The second vector.
 * \param vectorResult The vector to store the result of the multiplication.
 */
void calculateVectorProduct(std::vector<std::vector<long long>>& vectorA, std::vector<std::vector<long long>>& vectorB, std::vector<std::vector<long long>>& vectorResult)
{
	// Loop through the size of the vector and calculate the product of the two vectors
	// and store the result in the vectorResult
	for (int row = 0; row < vectorResult.size(); row++)
	{
		for (int col = 0; col < vectorResult[row].size(); col++)
		{
			long long product = 0;
			std::vector<long long> vectorRow, vectorCol;

			// Access the entry of each value in row of vectorA
			for (int colFirst = 0; colFirst < vectorA[row].size(); colFirst++)
			{
				vectorRow.push_back(vectorA[row][colFirst]);
			}

			// Access the entry of each value in col of vectorB
			for (int rowSecond = 0; rowSecond < vectorB.size(); rowSecond++)
			{
				vectorCol.push_back(vectorB[rowSecond][col]);
			}

			// Calculate the product of the product of the row of vectorA and the column of vectorB
			// and store it to the product variable
			for (int length = 0; length < vectorRow.size(); length++)
			{
				product += vectorRow[length] * vectorCol[length];
			}

			// Store the final product in the vectorResult at the given row and column
			vectorResult[row][col] = product;
		}
	}
}

int main()
{
	int rowA, colA, // Row and column of vector A
		rowB, colB; // Row and column of vector B

	// Read the input for the size of the two vectors until the end of the file
	while (std::cin >> rowA >> colA >> rowB >> colB)
	{
		std::vector<std::vector<long long>> vectorA(rowA, std::vector<long long>(colA, DEFAULT_BLANK_VALUE)),
			vectorB(rowB, std::vector<long long>(colB, DEFAULT_BLANK_VALUE)),
			// Multiplication matrix size: mxn * nxp = mxp
			vectorResult(rowA, std::vector<long long>(colB, DEFAULT_BLANK_VALUE));

		// CAUTION: Read the user input although the size of the vector is invalid
		readInputVector(vectorA);
		readInputVector(vectorB);

		// Check if the number of columns in vectorA is equal to the number of rows in vectorB
		// Matrix multiplication rules: mxn * nxp = mxp
		if (colA == rowB)
		{
			// Calculate the product of the two vectors and store the result in the vectorResult
			calculateVectorProduct(vectorA, vectorB, vectorResult);

			// Output the result of the multiplication
			for (int row = 0; row < vectorResult.size(); row++)
			{
				for (int col = 0; col < vectorResult[row].size(); col++)
				{
					// CAUTION: Keep an eye for " " at the end of the line
					// Check if the column is the last column of the row
					// If it is the last column, do not add a space after the value
					if (col == vectorResult[row].size() - 1)
					{
						std::cout << vectorResult[row][col];
					}
					else
					{
						std::cout << vectorResult[row][col] << " ";
					}
				}

				std::cout << "\n";
			}
		}
		else
		{
			// Output the error message if the matrix is invalid
			std::cout << "Matrix multiplication failed.\n";
		}
	}

	return 0;
}
