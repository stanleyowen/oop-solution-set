/*****************************************************************//**
 * \file   textBasedHistogram.cpp
 * \brief  Read each students' quiz score and create a simple
 *		   report of the overall grades.
 *
 * \author Stanley Owen
 * \date   2025/3/7
 *********************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

 /**
  * Count the score based on the scores vector and store it to the scoresScaleCount vector.
  *
  * \param scores The vector containing the scores
  * \param scoresScaleCount The vector containing the count of each score
  */
void countScore(std::vector<int>& scores, std::vector<int>& scoresScaleCount)
{
	// Loop through the scores vector and increment the count of the score
	// based on the appropriate index
	for (int i = 0; i < scores.size(); i++)
	{
		scoresScaleCount[scores[i]] += 1;
	}
}

/**
 * Generate the output to the vector based on the scoresScaleCount vector.
 *
 * \param scoresScaleCount The vector containing the count of each score
 * \param output The vector containing the output
 */
void generateOutputToVector(std::vector<int>& scoresScaleCount, std::vector<std::string>& output)
{
	// Loop through the scoresScaleCount vector and generate the output
	// based on the count of the score
	for (int i = 0; i < scoresScaleCount.size(); i++)
	{
		output.push_back(std::to_string(scoresScaleCount[i]) + " grade(s) of " + std::to_string(i));
	}
}

int main()
{
	// Declare necessary variables
	std::fstream readScoresFile, writeScoresFile;
	std::string scoresEachLine, score;

	// Open the file for reading the scores
	readScoresFile.open("grade.txt");
	// Open the file for writing the scores and clear the content of the file
	writeScoresFile.open("grades.output", std::ios::in | std::ios::out | std::ios::trunc);

	// Loop through each line of the file and store the data to the scoresEachLine variable
	while (std::getline(readScoresFile, scoresEachLine))
	{
		std::vector<int> scores;
		std::vector<std::string> dataOutput;
		// Declare the scores scale count where the index represents the score and the value represents the count
		std::vector<int> scoresScaleCount = { 0, 0, 0, 0, 0, 0 };
		// Declare the string stream to read the scores each line so that it can be separated by space
		std::istringstream stringStream(scoresEachLine);

		// Loop through each score and push it to the vector
		while (stringStream >> score)
		{
			scores.push_back(std::stoi(score));
		}

		// Count the score and generate the output to the vector
		countScore(scores, scoresScaleCount);
		generateOutputToVector(scoresScaleCount, dataOutput);

		// Loop through the output and write it to the file
		for (int i = 0; i < dataOutput.size(); i++)
		{
			writeScoresFile << dataOutput[i] << "\n";
		}
	}

	// Close the files after the process is done
	writeScoresFile.close();
	readScoresFile.close();

	return 0;
}