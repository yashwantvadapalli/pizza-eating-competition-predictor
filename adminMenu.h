#pragma once

#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <iostream>
#include <string>
#include <vector>


#include "teamManager.h"

class adminMenu {
private: 
    teamManager& teamMgr;
	std::vector<std::string> adminTeamList;

    void writeTeamsToFile();
public:
    adminMenu(teamManager& tm);
    void displayAdminMenu();
    void createTeam();
    void readTeams();
    void updateTeam();
    void deleteTeam();
};
#endif
