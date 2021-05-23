#ifndef MENURULES_H
#define MENURULES_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int getMenuChoice(); //Displays a basic menu and gets a (validated) menu choice
bool menuValidation(int choice); //Validation function for getMenuChoice()
//Checks if choice is either 0, 1, 2 or 3
void rules(); //Shows rules
int getMazeChoice(); //Displays a basic menu and gets a (validated) maze choice
bool mazeValidation(int choice);
string getMazeName(int choice);

#endif