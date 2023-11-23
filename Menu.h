#pragma once

#ifndef MENU_H
#define MENU_H

class Menu
{
public:
	void displayMenu();

private:
	void displayTeams();
	void predictQFs(); // Quarter Finalists
	void predictSFs(); // Semi Finalists
	void predictWinner(); // Winner
	void adminMenu(); 
};

#endif
