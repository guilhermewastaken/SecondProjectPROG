#ifndef MENURULES_H
#define MENURULES_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int getMenuChoice(); //Displays a basic menu and gets a (validated) menu choice
bool menuValidation(int choice); //Validation function for getMenuChoice()
void rules(); //Shows rules
int getMazeChoice(); //Displays a basic menu and gets a (validated) maze choice
bool mazeValidation(int choice); //Validation function for getMazeChoice()

#endif