#include <iostream>

#include "MenuRules.h"
//Simple functions for the menu and rules

#include "Post.h"
#include "Robot.h"
#include "Leaderboard.h"

#include "Game.h"

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
			int mazeChoice = getMazeChoice();

			if (std::cin.eof()) {
				break;
			}

			string mazeName = getMazeName(mazeChoice);

			while (mazeName == "ERROR") {
				cout << "Maze Not Found!" << endl;
				int mazeChoice = getMazeChoice();
				cout << mazeChoice << endl;

				if (std::cin.eof()) {
					break;
				}

				mazeName = getMazeName(mazeChoice);
			}
			Game game(mazeName);
			game.print();

		}
		else if (menuChoice == 3) {
			int mazeChoice = getMazeChoice();
			
			if (std::cin.eof()) {
				break;
			}
			
			Leaderboard winners(mazeChoice);
			winners.print();
		}
	}
	return 0;
}