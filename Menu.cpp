#include <iostream>
#include "Menu.h"
#include "teamManager.h"
#include "adminMenu.h"

// Initializing the constructor.
Menu::Menu() : predictor(nullptr) {
    // Loading teams from the file "Teams.txt".
    tm.readTeamsFromFile("Teams.txt");
}

// Executing the destructor.
Menu::~Menu() {
    // Cleaning up the dynamically allocated predictor.
    delete predictor;
}

// Displaying teams.
void Menu::displayTeams()
{
    std::cout << "Displaying teams...\n";
    // Delegating the task to teamManager to display teams.
    tm.displayTeams();
}

// Predicting Quarter Finalists.
void Menu::predictQFs() {
    std::cout << "Predicting Quarter Finalists...\n";
    if (!predictor) {
        // Initializing the predictor with the list of teams.
        predictor = new pewPredictor(tm.getTeams());
    }
    // Storing the predicted quarter finalists.
    quarterFinalists = predictor->predictQuarterFinalists();

    // Displaying the quarter finalists.
    std::cout << "Quarter Finalists:\n";
    for (const auto& team : quarterFinalists) {
        std::cout << team << std::endl;
    }
}

// Predicting Semi Finalists.
void Menu::predictSFs() {
    std::cout << "Predicting Semi Finalists...\n";
    if (predictor && !quarterFinalists.empty()) {
        // Predicting semi finalists based on the quarter finalists.
        semiFinalists = predictor->predictSemiFinalists(quarterFinalists);

        // Displaying the semi finalists.
        std::cout << "Semi Finalists:\n";
        for (const auto& team : semiFinalists) {
            std::cout << team << std::endl;
        }
    }
    else {
        std::cout << "Please predict the quarter finalists first.\n";
    }
}

// Predicting the Winner.
void Menu::predictWinner() {
    std::cout << "Predicting Winner...\n";
    if (predictor && !semiFinalists.empty()) {
        // Predicting finalists from the semi finalists.
        finalists = predictor->predictFinalists(semiFinalists);

        // Displaying the finalists.
        std::cout << "Finalists:\n";
        for (const auto& team : finalists) {
            std::cout << team << std::endl;
        }

        // Predicting and displaying the winner.
        std::string winner = predictor->predictWinner(finalists);
        std::cout << "Winner:\n" << winner << std::endl;
    }
    else {
        std::cout << "Please predict the semi finalists first.\n";
    }
}

// Displaying the Admin Menu.
void Menu::displayAdminMenu() {
    std::cout << "Admin Menu...\n";
    // Creating an adminMenu object and displaying the admin menu.
    adminMenu am(tm);
    am.displayAdminMenu();
}

// Displaying the main menu and handling user input.
void Menu::displayMenu() {
    int choice;

    do {
        // Printing the main menu options.
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

        // Handling the user's choice.
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
            displayAdminMenu();
            break;
        case 6:
            std::cout << "Exiting the program...\n";
            break;
        default:
            std::cout << "Please enter a valid choice.\n";
        }
    } while (choice != 6);  // Repeating until the exit option is chosen.
}
