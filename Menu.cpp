#include <iostream>
#include "Menu.h"

// Constructor
Menu::Menu() {
	// Initialize the predictor with the list of teams
	predictor = nullptr;
}

// Destructor
Menu::~Menu() {
	// Clean up the dynamically allocated predictor
	delete predictor;
}

void Menu::displayTeams()
{
	std::cout << "Displaying teams...\n";
	tm.readTeamsFromFile("teams.txt"); // Load teams from file
	tm.displayTeams();
}

void Menu::predictQFs() {
	std::cout << "Predicting Quarter Finalists...\n";
	std::cout << "" << std::endl;
	if (!predictor) {
		predictor = new pewPredictor(tm.getTeams()); // Initialize the predictor with teams
	}
	quarterFinalists = predictor->predictQuarterFinalists();

	// Display the quarterFinalists
	std::cout << "Quarter Finalists:\n";
	std::cout << "" << std::endl;
	for (const auto& team : quarterFinalists) {
		std::cout << team << std::endl;
	}
}

void Menu::predictSFs() {
	std::cout << "Predicting Semi Finalists...\n";
	std::cout << "" << std::endl;
	if (predictor && !quarterFinalists.empty()) {
		semiFinalists = predictor->predictSemiFinalists(quarterFinalists);

		// Display the semiFinalists
		std::cout << "Semi Finalists:\n";
		std::cout << "" << std::endl;
		for (const auto& team : semiFinalists) {
			std::cout << team << std::endl;
		}
	}
	else {
		std::cout << "Please predict the quarter finalists first.\n";
	}
}

void Menu::predictWinner() {
	std::cout << "Predicting Winner...\n";
	std::cout << "" << std::endl;
	if (predictor && !semiFinalists.empty()) {
		finalists = predictor->predictFinalists(semiFinalists);

		// Display the finalists
		std::cout << "Finalists:\n";
		std::cout << "" << std::endl;
		for (const auto& team : finalists) {
			std::cout << team << std::endl;
		}

		// Predict and display the winner
		std::string winner = predictor->predictWinner(finalists);
		std::cout << "" << std::endl;
		std::cout << "Winner:\n" << winner << std::endl;
	}
	else {
		std::cout << "Please predict the semi finalists first.\n";
	}
}

void Menu::adminMenu()
{
	std::cout << "Admin Menu...\n";
}

void Menu::displayMenu() {
	int choice;

	do {
		std::cout << "\n*******************************************\n";
		std::cout << "*       Welcome to the PEW Predictor      *\n";
		std::cout << "*                Menu                     *\n";
		std::cout << "*******************************************\n";
		std::cout << "* 1. Display Teams                        *\n";
		std::cout << "* 2. Predict Quarter Finalists            *\n";
		std::cout << "* 3. Predict Semi Finalists               *\n";
		std::cout << "* 4. Predict Winner                       *\n";
		std::cout << "* 5. Admin Menu                           *\n";
		std::cout << "* 6. Exit                                 *\n";
		std::cout << "*******************************************\n";
		std::cout << "\nEnter your choice: ";
		std::cin >> choice;
		std::cout << "\n";


		switch (choice) {
		case 1:
			displayTeams();
			break;
		case 2:
			predictQFs();	
			break;
		case 3:
			predictSFs();
			break;
		case 4:
			predictWinner();
			break;
		case 5:
			adminMenu();	
			break;
		case 6:
			std::cout << "Exiting the program...\n";
			break;
		default:
			std::cout << "Please enter a valid choice.\n";
		}
	} while (choice != 6);
}