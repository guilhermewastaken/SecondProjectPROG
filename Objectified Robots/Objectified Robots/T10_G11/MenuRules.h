#ifndef MENURULES_H
#define MENURULES_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>

//Constants used
const int EXIT = 0;
const int RULES = 1;
const int PLAY = 2;
const int LEADERBOARD = 3;
const int MAZEMIN = 0; //The minimum value for a maze is 1 but player can write 0 to return to main menu
const int RETURNTOMENU = 0;
const int MAZEMAX = 99;
const int PLAYERNAMEMAXSIZE = 15;

//Functions
int getMenuChoice(); //Displays a basic menu and gets a (validated) menu choice
bool menuValidation(int choice); //Validation function for getMenuChoice()
void rules(); //Shows rules
int getMazeChoice(); //Gets a (validated) maze choice
bool mazeValidation(int choice); //Validation function for getMazeChoice()
std::string getPlayerName(); //Gets a name to be put in the leaderboard
bool nameValidation(std::string playerName); //Validation function for getPlayerName()



#endif