#pragma once

#ifndef MENU_H
#define MENU_H

#include "teamManager.h"

class Menu {
public:
	void displayMenu();

	teamManager tm; // Add a teamManager object to the class

private:
	void displayTeams();
	void predictQFs(); // Quarter Finalists
	void predictSFs(); // Semi Finalists
	void predictWinner(); // Winner
	void adminMenu(); 
};

#endif
