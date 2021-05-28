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

			Game game(100); //Creates a Game object where game.validMaze() will allways return false
			do {
				int mazeChoice = getMazeChoice();
				if (std::cin.eof()) {
					break; //The player quit the game, first of two breaks to end the game 
				}
				Game game(mazeChoice); //Replaces the previous game object with the player's choice
			} while (!game.validMaze()); //Checks if a file with the given name exists. If not, asks for another input
			if (std::cin.eof()) {
				break; //The player quit the game, second of two breaks to end the game 
			}

			game.createMaze();
			game.play(); //Starts the game

			if (std::cin.eof()) {
				running = false; //Player quit the game
			}
			else if (game.playerVictory()) { //The player won the game
				/*Adds player to leaderboard*/
			}
			else {//The Player lost
				/*You lost message?*/
			}
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