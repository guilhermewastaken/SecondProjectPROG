#include "MenuRules.h"

int getMenuChoice() { //Displays a basic menu and gets a (validated) menu choice
	int menuChoice;
	cout << "Menu:\n0- Exit\n1- Rules\n2- Play\n3- Leaderboard\nYour Choice: " << std::flush; //Output a menu
	cin >> menuChoice;
	while (!menu_validation(menuChoice)) {
		cout << "\nInvalid Input\nYour Choice: " << std::flush;
		cin >> menuChoice; //The game asks the user for new inputs until he inserts a valid one (0, 1, 2 or 3) 
	}
	return menuChoice;
}

bool menu_validation(int choice) {
	if (((cin.peek() == '\n') && (choice == 0 || choice == 1 || choice == 2 || choice == 3)) || cin.eof()) {
		return true; //Inputs were inserted correctly and buffer is clear or player left the game
	}
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return false; //Some error occured, clears buffer and indicates invalid input
	}

void rules() { //Shows rules
	string line;
	ifstream myfile("RULES.txt");
	//Rules for how a maze is selected are explained when the user selects play
	while (getline(myfile, line))
	{
		cout << line << endl;
	}
	cout << endl << endl;
	myfile.close();
}
