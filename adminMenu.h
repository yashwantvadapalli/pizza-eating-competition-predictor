#pragma once

#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <iostream>
#include <string>
#include <vector>

#include "teamManager.h"

class adminMenu {
private:
    teamManager& teamMgr; // Holding a reference to a teamManager instance
    std::vector<std::string> adminTeamList; // Storing a list of teams for admin operations

    void writeTeamsToFile(); // Writing the team list to a file

public:
    adminMenu(teamManager& tm); // Constructing adminMenu with a reference to teamManager

    void displayAdminMenu(); // Displaying the admin menu options
    void createTeam(); // Allowing the creation of a new team
    void readTeams(); // Reading and displaying the list of teams
    void updateTeam(); // Updating the name of an existing team
    void deleteTeam(); // Deleting a team from the list
};

#endif
