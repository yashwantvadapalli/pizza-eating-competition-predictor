#pragma once

#ifndef TEAMMANAGER_H
#define TEAMMANAGER_H

#include <iostream>
#include <string>
#include <vector>

class teamManager {
private:
	std::vector<std::string> teamNames;
public:
	teamManager() {}
	teamManager(const std::string& fileName);

	void readTeamsFromFile(const std::string& filename);
	void displayTeams() const;
};
#endif
