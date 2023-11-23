#include "Menu.h"
#include <iostream>

void Menu::displayTeams()
{
	std::cout << "Displaying teams...\n";
}

void Menu::predictQFs()
{
	std::cout << "Predicting Quarter Finalists...\n";
}

void Menu::predictSFs()
{
	std::cout << "Predicting Semi Finalists...\n";
}

void Menu::predictWinner()
{
	std::cout << "Predicting Winner...\n";
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
