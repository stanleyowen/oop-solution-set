/*****************************************************************//**
 * \file   Source.cpp
 * \brief  Reading the input file, process, and output the top
 *		   three players' scores game.
 *
 * \author Stanley Owen
 * \date   2025/2/27
 *********************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

 /**
  * Function to compare player scores in descending order
  *
  * \param a A pair containing a player's name and score
  * \param b A pair containing another player's name and score
  * \return true if the score of player a is greater than the score of player b, else false
  */
bool comparePlayerScores(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
	// Compare two different scores from each players'
	return a.second > b.second;
}

/**
 * Read the scores.txt, sort the data, and returns the top three \n
 * players' names and scores respectively
 *
 * \param topThreePlayerNames Array containing top three players' names
 * \param topThreePlayerScores Array containing top three players' scores
 */
void getHighScores(std::string topThreePlayerNames[], int topThreePlayerScores[]) {
	// Declares all necessary variables
	std::fstream fileContent;
	std::string playerName;
	int playerScore;
	// 2D vector with 2 different datatypes: {string, integer}
	std::vector<std::pair<std::string, int>> playerData;

	// Open the file containing the players' names and scores
	fileContent.open("scores.txt");

	// Assign the value of the players' name and score respectively
	// from the fileContent
	while (fileContent >> playerName >> playerScore) {
		// Append each player's name and score to the playerData container
		playerData.push_back({ playerName, playerScore });
	}

	// Sort the playerData in ascending order based on each player's score
	std::sort(playerData.begin(), playerData.end(), comparePlayerScores);

	// Assign the top three players' data to the corresponding arrays passed
	// in the function parameters
	for (int i = 0; i < 3; i++) {
		topThreePlayerNames[i] = playerData[i].first;
		topThreePlayerScores[i] = playerData[i].second;
	}
}

int main() {
	// Declares all necessary variables
	std::string topThreePlayerNames[3];
	int topThreePlayerScores[3];

	// Call the getHighScores function
	getHighScores(topThreePlayerNames, topThreePlayerScores);

	// Print each of the player name and score with the top three highest scores' game
	for (int i = 0; i < 3; i++) {
		std::cout << topThreePlayerNames[i] << "\n" << topThreePlayerScores[i] << "\n";
	}

	return 0;
}
