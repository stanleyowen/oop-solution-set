/*****************************************************************//**
 * \file   ComputeStandardDeviation.cpp
 * \brief  Compute the average and standard deviation of input
 *		   scores.
 *
 * \author Stanley Owen
 * \date   2025/2/24
 *********************************************************************/

#include <iostream>
#include <math.h>
#include <vector>

 /**
  * Calculates the average scores by the given sum scores and the number of scores
  *
  * \param sumScores The sum of all the total scores
  * \param numberOfScores The number of scores
  * \return The average scores of all given scores
  */
double calculateAverageScores(double sumScores, long long numberOfScores) {
	// Compute and return the average scores
	return (double)sumScores / numberOfScores;
}

/**
 * Calculates the standard deviation scores by the given score, average scores, and the number of scores
 *
 * \param scores Collection of scores
 * \param averageScores Average of the overall scores
 * \param numberOfScores The number of scores
 * \return The standard deviation scores of all given scores
 */
double calculateStandardDeviationScores(std::vector<double>& scores, double averageScores, long long numberOfScores) {
	// Declare temporary variable
	double averageInputValues = 0;

	// Loop through each score and deduct it with the average scores then calculates the result
	// bv the power of two
	for (int i = 0; i < numberOfScores; i++) {
		averageInputValues += pow((scores[i] - averageScores), 2);
	}

	// Compute and return the standard deviation scores
	return sqrt(averageInputValues / numberOfScores);
}

int main() {
	int numberOfScores;

	// Loop until no input is found or also known as EOF
	while (std::cin >> numberOfScores) {
		// Declares all necessary variables
		std::vector<double> scores;
		double score,
			sumScores = 0,
			averageScores = 0,
			standardDeviationScores = 0;

		// Read each score, calculate the sum, and store each score in the vector
		for (int i = 0; i < numberOfScores; i++) {
			std::cin >> score;

			sumScores += score;
			scores.push_back(score);
		}

		// Call the calculateAverageScores function and store it to the averageScores variable
		averageScores = calculateAverageScores(sumScores, numberOfScores);
		// Call the calculateStandardDeviationScores function and store it to the standardDeviationScores variables
		standardDeviationScores = calculateStandardDeviationScores(scores, averageScores, numberOfScores);

		// Print the average scores and the standard deviation scores to the terminal
		std::cout << "Average:" << averageScores << "\tStandard deviation:" << standardDeviationScores << "\n";
	}

	return 0;
}
