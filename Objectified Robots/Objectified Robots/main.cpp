#include <iostream>

#include "MenuRules.h"
//Simple functions for the menu and rules

#include "Post.h"
#include "Robot.h"
#include "Leaderboard.h"

int main() {

	bool running = true;
	while (running) { //loop that will only end if the player quits the game (if-break statements throughout the code)
		int menuChoice = getMenuChoice();
		if (menuChoice == 0 || std::cin.eof()) {
			running = false; //Exits game
		}
		else if (menuChoice == 1) {
			rules();
			//Shows rules
		}
		else if (menuChoice == 2) {
			/*Game class*/
		}
		else if (menuChoice == 3) {
			int mazeChoice = getMazeChoice();
			Leaderboard winners(mazeChoice);
			winners.print();
		}
	}
	return 0;
}