#include "pewPredictor.h"
#include <algorithm>
#include <random>

// Helper function to randomly select winners
std::vector<std::string> selectWinners(std::vector<std::string> teams, size_t numWinners) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(teams.begin(), teams.end(), g);
    teams.resize(numWinners);  // Keep only the required number of winners
    return teams;
}

pewPredictor::pewPredictor(const std::vector<std::string>& init_teams) : teams(init_teams) {}

std::vector<std::string> pewPredictor::predictQuarterFinalists() {
    return selectWinners(teams, 8);  // Select 8 quarterfinalists
}

std::vector<std::string> pewPredictor::predictSemiFinalists(const std::vector<std::string>& quarterFinalists) {
    return selectWinners(quarterFinalists, 4);  // Select 4 semifinalists
}

std::vector<std::string> pewPredictor::predictFinalists(const std::vector<std::string>& semiFinalists) {
    return selectWinners(semiFinalists, 2);  // Select 2 finalists
}

std::string pewPredictor::predictWinner(const std::vector<std::string>& finalists) {
    return selectWinners(finalists, 1).front();  // Select the winner
}
