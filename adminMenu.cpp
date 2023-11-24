#include "adminMenu.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

adminMenu::adminMenu(teamManager& tm) : teamMgr(tm) {
		adminTeamList = teamMgr.getTeams();  // Initialize local copy
}

void adminMenu::writeTeamsToFile() {
	std::ofstream file("Teams.txt");
	if (file.is_open()) {
		for (const auto& team : adminTeamList) {
			file << team << std::endl;
		}
	}
	file.close();
	teamMgr.readTeamsFromFile("Teams.txt");  // Update teamManager with the new list
}

void adminMenu::createTeam() {
	std::string newTeamName;
	std::cout << "Enter new team name: ";
	std::cin.ignore();  // Clear the newline left in the input buffer
	std::getline(std::cin, newTeamName);  // Read the full line for team name
	adminTeamList.push_back(newTeamName);  // Add the new team
	writeTeamsToFile();  // Update the file with the new team list
	std::cout << "Team '" << newTeamName << "' added successfully.\n";
}

void adminMenu::readTeams() {
	std::cout << "Current teams:\n";
	for (const auto& teamName : adminTeamList) {
		std::cout << teamName << std::endl;
	}
}

void adminMenu::updateTeam() {
	std::string oldTeamName, newTeamName;
	std::cout << "Enter existing team name to update: ";
	std::cin.ignore();
	std::getline(std::cin, oldTeamName);
	auto it = std::find(adminTeamList.begin(), adminTeamList.end(), oldTeamName);

	if (it != adminTeamList.end()) {
		std::cout << "Enter new team name: ";
		std::getline(std::cin, newTeamName);
		*it = newTeamName;  // Update the team name
		writeTeamsToFile();  // Synchronize changes
		std::cout << "Team updated successfully.\n";
	}
	else {
		std::cout << "Team not found.\n";
	}
}

void adminMenu::deleteTeam() {
	std::string teamName;
	std::cout << "Enter team name to delete: ";
	std::cin.ignore();
	std::getline(std::cin, teamName);
	auto it = std::find(adminTeamList.begin(), adminTeamList.end(), teamName);

	if (it != adminTeamList.end()) {
		adminTeamList.erase(it);  // Remove the team
		writeTeamsToFile();  // Synchronize changes
		std::cout << "Team '" << teamName << "' deleted successfully.\n";
	}
	else {
		std::cout << "Team not found.\n";
	}
}

void adminMenu::displayAdminMenu() {
	std::string username, password;
	std::cout << "Enter username: ";
	std::cin >> username;
	std::cout << "Enter password: ";
	std::cin >> password;

	if (username == "AUser" && password == "pew2024") {
		int choice;
		do {
			std::cout << "\n*******************************************\n";
			std::cout << "*               ADMIN MENU                *\n";
			std::cout << "*******************************************\n";
			std::cout << "* 1. Create new team                      *\n";
			std::cout << "* 2. Display current teams                *\n";
			std::cout << "* 3. Update team list                     *\n";
			std::cout << "* 4. Delete team                          *\n";
			std::cout << "* 5. Exit Admin Menu                      *\n";
			std::cout << "*******************************************\n";
			std::cout << "\nEnter your choice: ";
			std::cin >> choice;
			std::cout << "\n";

			switch (choice) {
			case 1:
				createTeam();
				break;
			case 2:
				readTeams();
				break;
			case 3:
				updateTeam();
				break;
			case 4:
				deleteTeam();
				break;
			case 5:
				std::cout << "Exiting admin menu.\n";
				break;
			default:
				std::cout << "Invalid choice, please try again.\n";
				std::cout << " " << std::endl;
			}
		} while (choice != 5);
	}
	else {
		std::cout << "Invalid username or password. Please try again.\n";
		std::cout << " " << std::endl;
	}
}

