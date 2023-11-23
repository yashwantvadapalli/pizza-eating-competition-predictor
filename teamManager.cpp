#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

#include "TeamManager.h"

void teamManager::readTeamsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string teamName;

    if (file.is_open()) {
        while (getline(file, teamName)) {
            if (!teamName.empty()) {
                teamNames.push_back(teamName);
            }
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void teamManager::displayTeams() const {
    // Determine the total width of the table for the border
    const int columnWidth = 20;  // Width for the team name column
    const int totalWidth = columnWidth + 3;  // Including borders and separators

    // Print the top border of the table
    std::cout << "+";
    for (int i = 0; i < totalWidth - 2; i++) { // -2 for the corners of the border
        std::cout << "-";
    }
    std::cout << "+" << std::endl;

    // Print the header
    std::cout << "| " << std::setw(columnWidth) << std::left << "Team Name" << "|" << std::endl;

    // Print the separator below the header
    std::cout << "+";
    for (int i = 0; i < totalWidth - 2; i++) {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;

    // Print each team name in the list
    for (const auto& teamName : teamNames) {
        std::cout << "| " << std::setw(columnWidth) << std::left << teamName << "|" << std::endl;
    }

    // Print the bottom border of the table
    std::cout << "+";
    for (int i = 0; i < totalWidth - 2; i++) {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;
}
