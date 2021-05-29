#ifndef MENURULES_H
#define MENURULES_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

const int EXIT = 0;
const int RULES = 1;
const int PLAY = 2;
const int LEADERBOARD = 3;

const int MAZEMIN = 1;
const int MAZEMAX = 99;

const int PLAYERNAMEMAXSIZE = 15;


int getMenuChoice(); //Displays a basic menu and gets a (validated) menu choice
bool menuValidation(int choice); //Validation function for getMenuChoice()
void rules(); //Shows rules
int getMazeChoice(); //Displays a basic menu and gets a (validated) maze choice
bool mazeValidation(int choice); //Validation function for getMazeChoice()
bool nameValidation(string playerName);
string getPlayerName();



#endif