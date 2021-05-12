#include <iostream>
#include "MenuRules.h"

int getMenuChoice() { //Displays a basic menu and gets a (validated) menu choice
	int menuChoice;
	std::cout << "Menu:\n0- Exit\n1- Rules\n2- Play\n3- Leaderboard\nYour Choice: " << std::flush; //Output a menu
	std::cin >> menuChoice;
	while (!menu_validation(menuChoice)) {
		std::cout << "\nInvalid Input\nYour Choice: " << std::flush;
		std::cin >> menuChoice; //The game asks the user for new inputs until he inserts a valid one (0, 1, 2 or 3) 
	}
	return menuChoice;
}

bool menu_validation(int choice) {
	if (((std::cin.peek() == '\n') && (choice == 0 || choice == 1 || choice == 2 || choice == 3)) || std::cin.eof()) {
		return true; //Inputs were inserted correctly and buffer is clear or player left the game
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return false; //Some error occured, clears buffer and indicates invalid input
	}

void rules() { //Shows rules
	/*Work in progress- previous code:*/
	std::cout << "\n------------------------------------ Rules ------------------------------------\n" <<
		"You find yourself in a maze made out of eletric fences. Interceptor robots are chasing you!\n" <<
		"You can move like this (or remain in place by pressing S):\n" << std::endl;
	std::cout << "  Q  *  W  *  E  \n" << " * * * * * * * *\n" << "  A  * YOU *  D  \n" <<
		" * * * * * * * *\n" << "  Z  *  X  *  C  " << std::endl; //Displays a table with the possible player movements
	std::cout << "Where, for example, if you inputed Q you'd move diagonally to the upper left cell.\n" <<
		"The robots (R) can make the same movements as you.\n" <<
		"They'll always try to take the shortest path to your position (ignoring obstacles in the way).\n" <<
		"If a robot hits another robot or a fence (*) they die. They'll then be represented by an 'r'.\n" <<
		"If you hit a robot or a fence you lose. You also can't move to a cell occupied by a dead robot.\n" <<
		"If all robots die, you win!\n" << std::endl;
}