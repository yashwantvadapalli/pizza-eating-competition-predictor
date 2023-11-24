#include "adminMenu.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

// Constructing the adminMenu with a reference to teamManager.
adminMenu::adminMenu(teamManager& tm) : teamMgr(tm) {
    adminTeamList = teamMgr.getTeams();  // Initializing the local copy with teams from teamManager
}

// Writing the current team list to a file.
void adminMenu::writeTeamsToFile() {
    std::ofstream file("Teams.txt");
    if (file.is_open()) {
        for (const auto& team : adminTeamList) {
            file << team << std::endl; // Writing each team to the file
        }
    }
    file.close(); // Closing the file
    teamMgr.readTeamsFromFile("Teams.txt");  // Updating teamManager with the new team list
}

// Creating a new team.
void adminMenu::createTeam() {
    std::string newTeamName;
    std::cout << "Enter new team name: ";
    std::cin.ignore();  // Clearing the input buffer
    std::getline(std::cin, newTeamName);  // Reading the full line for the new team name
    adminTeamList.push_back(newTeamName);  // Adding the new team to the list
    writeTeamsToFile();  // Updating the file with the new team list
    std::cout << "Team '" << newTeamName << "' added successfully.\n";
}

// Reading and displaying teams.
void adminMenu::readTeams() {
    std::cout << "Current teams:\n";
    for (const auto& teamName : adminTeamList) {
        std::cout << teamName << std::endl; // Displaying each team name
    }
}

// Updating an existing team's name.
void adminMenu::updateTeam() {
    std::string oldTeamName, newTeamName;
    std::cout << "Enter existing team name to update: ";
    std::cin.ignore(); // Clearing the input buffer
    std::getline(std::cin, oldTeamName); // Reading the old team name
    auto it = std::find(adminTeamList.begin(), adminTeamList.end(), oldTeamName);

    if (it != adminTeamList.end()) {
        std::cout << "Enter new team name: ";
        std::getline(std::cin, newTeamName); // Reading the new team name
        *it = newTeamName;  // Updating the team name in the list
        writeTeamsToFile();  // Synchronizing changes with the file
        std::cout << "Team updated successfully.\n";
    }
    else {
        std::cout << "Team not found.\n";
    }
}

// Deleting a team.
void adminMenu::deleteTeam() {
    std::string teamName;
    std::cout << "Enter team name to delete: ";
    std::cin.ignore(); // Clearing the input buffer
    std::getline(std::cin, teamName); // Reading the team name to delete
    auto it = std::find(adminTeamList.begin(), adminTeamList.end(), teamName);

    if (it != adminTeamList.end()) {
        adminTeamList.erase(it);  // Removing the team from the list
        writeTeamsToFile();  // Synchronizing changes with the file
        std::cout << "Team '" << teamName << "' deleted successfully.\n";
    }
    else {
        std::cout << "Team not found.\n";
    }
}

// Displaying the admin menu and handling user choices.
void adminMenu::displayAdminMenu() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username; // Reading the username
    std::cout << "Enter password: ";
    std::cin >> password; // Reading the password

    if (username == "AUser" && password == "pew2024") { // Authenticating user
        int choice;
        do {
            // Displaying menu options
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
            std::cin >> choice; // Reading the user's choice

            // Handling the user's choice
            switch (choice) {
            case 1:
                createTeam(); // Creating a new team
                break;
            case 2:
                readTeams(); // Displaying current teams
                break;
            case 3:
                updateTeam(); // Updating a team
                break;
            case 4:
                deleteTeam(); // Deleting a team
                break;
            case 5:
                std::cout << "Exiting admin menu.\n"; // Exiting the menu
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
            }
        } while (choice != 5); // Continuing until the exit option is selected
    }
    else {
        std::cout << "Invalid username or password. Please try again.\n";
    }
}
