#include "pewPredictor.h"
#include <algorithm>
#include <random>

// Defining a helper function to randomly select winners.
std::vector<std::string> selectWinners(std::vector<std::string> teams, size_t numWinners) {
    std::random_device rd; // Initializing a random device for generating random numbers.
    std::mt19937 g(rd()); // Creating a Mersenne Twister engine using the random device.
    std::shuffle(teams.begin(), teams.end(), g); // Shuffling the team list randomly.
    teams.resize(numWinners);  // Trimming the list to keep only the required number of winners.
    return teams; // Returning the selected winners.
}

// Constructing the pewPredictor with a list of teams.
pewPredictor::pewPredictor(const std::vector<std::string>& init_teams) : teams(init_teams) {}

// Predicting quarter finalists by selecting 8 random teams.
std::vector<std::string> pewPredictor::predictQuarterFinalists() {
    return selectWinners(teams, 8);  // Selecting 8 quarterfinalists.
}

// Predicting semi finalists from the given quarter finalists by selecting 4 random teams.
std::vector<std::string> pewPredictor::predictSemiFinalists(const std::vector<std::string>& quarterFinalists) {
    return selectWinners(quarterFinalists, 4);  // Selecting 4 semifinalists.
}

// Predicting finalists from the given semi finalists by selecting 2 random teams.
std::vector<std::string> pewPredictor::predictFinalists(const std::vector<std::string>& semiFinalists) {
    return selectWinners(semiFinalists, 2);  // Selecting 2 finalists.
}

// Predicting the overall winner from the list of finalists.
std::string pewPredictor::predictWinner(const std::vector<std::string>& finalists) {
    return selectWinners(finalists, 1).front();  // Selecting the single winner.
}
