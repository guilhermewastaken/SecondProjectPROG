#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <limits>
#include <algorithm>
#include <cctype>
#include <iomanip>


class Leaderboard {
private:
	int mazeNumber;
	std::string mazeName;
	bool emptyBoard;
public:
	Leaderboard() = default;//Class constructor
	//Only exists so a leaderboard object can be declared before the main game loop, its atributes will be given values later

	void updateMazeNumber(int mazeNumber);
	//Makes sure a file for the winners of mazeNumber's maze already exists and saves its name for later use

	void addWinner(std::string name, int time);
	void print();
private:
	std::string createName(int mazeNumber); //Creates a proper mazeName (MAZE_01_WINNERS.txt) from a mazeNumber (1)
	bool fileExists(std::string mazeName); //Checks if the file exists
	int getNumLines(std::string mazeName); //Returns the number of lines of the fileSS
};
#endif
