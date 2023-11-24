#pragma once

#ifndef TEAMMANAGER_H
#define TEAMMANAGER_H

#include <iostream>
#include <string>
#include <vector>


class teamManager {
private:
    std::vector<std::string> teamNames;     // Holding a list of team names.

public:
    teamManager() {}  // Default constructor.
    teamManager(const std::string& fileName); // Constructor to read teams from a file.
    void readTeamsFromFile(const std::string& filename);     // Reading teams from a teams.txt file and storing them in the list.
    void displayTeams() const;     // Displaying the list of team names.
    const std::vector<std::string>& getTeams() const { return teamNames; } // Providing access to the list of team names.
};

#endif
