#include <iostream>

#include "MenuRules.h"
//Simple functions for the menu and rules

#include "Post.h"
#include "Robot.h"
#include "Leaderboard.h"

#include "Game.h"

using namespace std;

int main() {
	Leaderboard leaderboard;
	Game game; //Creates objects leaderboard and game with default values, they'll later be updated

	while (true) { //loop that will only end if the player quits the game (if-break statements throughout the code)
		int menuChoice = getMenuChoice();
		if (menuChoice == EXIT || std::cin.eof()) {
			break; //Exits game
		}
		else if (menuChoice == RULES) {
			rules();
			//Shows rules
		}
		else if (menuChoice == PLAY) {
			int mazeChoice;			
			
			do {
				mazeChoice = getMazeChoice();
				if (std::cin.eof() || mazeChoice == RETURNTOMENU) {
					break; //The player quit the game, first of two breaks to end the game
					//Or the player chose to return to the main menu
				}
				game.updateMazeNumber(mazeChoice); //Replaces the previous game object with the player's choice
			} while (!game.validMaze()); //Checks if a file with the given name exists. If not, asks for another input
			
			if (std::cin.eof()) {
				break; //The player quit the game, second of two breaks to end the game 
			}
			if (mazeChoice == RETURNTOMENU) {
				continue; //The player chose to return to the main menu
			}

			game.createMaze();
			game.play(); //Starts the game

			if (std::cin.eof()) {
				break; //Player quit the game
			}
			else if (game.playerVictory()) { //The player won the game				
				cout << "\nYOU WIN\n" << endl;
				
				int playerScore = game.getScore();
				
				string playerName = getPlayerName(); //Get winner name
				if (cin.eof()) {
					break; //Player quit the game
				}

				leaderboard.updateMazeNumber(mazeChoice);
				leaderboard.addWinner(playerName, playerScore); //Adds winner stats to the leaderboard
			}
			else { //The Player lost
				cout << "\nYOU LOST\n" << endl;
			}
		}
		else if (menuChoice == LEADERBOARD) {
			int mazeChoice = getMazeChoice();			
			if (std::cin.eof()) {
				break; //Player quit the game
			}
			if (mazeChoice == RETURNTOMENU) {
				continue; //The player chose to return to the main menu
			}
			
			leaderboard.updateMazeNumber(mazeChoice);
			leaderboard.print(); //Prints the maze
		}
	}
	return 0;

}