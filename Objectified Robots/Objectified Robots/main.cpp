#include <iostream>

#include "MenuRules.h"
//Simple functions that deal with the interface

#include "Post.h"
#include "Robot.h"

int main() {

	bool running = true;
	while (running) { //loop that will only end if the player quits the game (if-break statements throughout the code)
		int menuChoice = getMenuChoice();
		if (menuChoice == 0 || std::cin.eof()) {
			running = false; //Exits game
		}
		else if (menuChoice == 1) { /*Work in Progress*/
			rules();
			//Shows rules
		}
		else if (menuChoice == 2) {
			/*Game class*/
		}
		else if (menuChoice == 3) {
			/*Leaderboard class*/
		}
	}
	return 0;
}