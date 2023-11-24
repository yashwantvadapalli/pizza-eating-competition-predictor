#ifndef MENU_H
#define MENU_H

#include "TeamManager.h"
#include "pewPredictor.h"
#include "adminMenu.h"

class Menu {
public:
    void displayMenu();
    Menu();          // Constructor to initialize the predictor
    ~Menu();         // Destructor to clean up dynamically allocated memory

private:
    teamManager tm;  // TeamManager object to handle team operations
    pewPredictor* predictor;  // Pointer to Predictor object

    void displayTeams();
    void predictQFs();      // Quarter Finalists
    void predictSFs();      // Semi Finalists
    void predictWinner();   // Winner
    void displayAdminMenu();

    // Results from predictions
    std::vector<std::string> quarterFinalists;
    std::vector<std::string> semiFinalists;
    std::vector<std::string> finalists;
};

#endif