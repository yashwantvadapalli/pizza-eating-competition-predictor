#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

#include "TeamManager.h"

// Reading team names from a specified file.
void teamManager::readTeamsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string teamName;

    if (file.is_open()) {
        // Iterating through each line in the file.
        while (getline(file, teamName)) {
            if (!teamName.empty()) {
                // Adding non-empty team names to the list.
                teamNames.push_back(teamName);
            }
        }
        // Closing the file after reading.
        file.close();
    }
    else {
        // Displaying an error message if the file cannot be opened.
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

// Displaying teams in a formatted table.
void teamManager::displayTeams() const {
    // Setting up the column width and total width for the table.
    const int columnWidth = 20;  // Setting width for the team name column.
    const int totalWidth = columnWidth + 3;  // Including borders and separators.

    // Printing the top border of the table.
    std::cout << "+";
    for (int i = 0; i < totalWidth - 2; i++) { // Subtracting 2 for the corners of the border.
        std::cout << "-";
    }
    std::cout << "+" << std::endl;

    // Printing the header of the table.
    std::cout << "| " << std::setw(columnWidth) << std::left << "Team Name" << "|" << std::endl;

    // Printing the separator below the header.
    std::cout << "+";
    for (int i = 0; i < totalWidth - 2; i++) {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;

    // Iterating and printing each team name in the list.
    for (const auto& teamName : teamNames) {
        std::cout << "| " << std::setw(columnWidth) << std::left << teamName << "|" << std::endl;
    }

    // Printing the bottom border of the table.
    std::cout << "+";
    for (int i = 0; i < totalWidth - 2; i++) {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;
}
