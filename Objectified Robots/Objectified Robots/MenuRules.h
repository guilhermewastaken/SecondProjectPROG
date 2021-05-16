#ifndef MENURULES_H
#define MENURULES_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int getMenuChoice(); //Displays a basic menu and gets a (validated) menu choice
bool menu_validation(int choice); //Validation function for getMenuChoice()
//Checks if choice is either 0, 1, 2 or 3
void rules(); //Shows rules

#endif