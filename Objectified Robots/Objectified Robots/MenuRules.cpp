#include "MenuRules.h"

using namespace std;

int getMenuChoice() { //Displays a basic menu and gets a (validated) menu choice
	int menuChoice;
	cout << "Menu:\n0- Exit\n1- Rules\n2- Play\n3- Leaderboard\nYour Choice: " << flush; //Output a menu
	cin >> menuChoice;
	while (!menuValidation(menuChoice)) {
		cout << "\nInvalid Input\nYour Choice: " << flush;
		cin >> menuChoice; //The game asks the user for new inputs until he inserts a valid one (0, 1, 2 or 3) 
	}
	return menuChoice;
}

bool menuValidation(int choice) {

	if (((cin.peek() == '\n') && (choice == EXIT || choice == RULES || choice == PLAY || choice == LEADERBOARD)) || cin.eof()) {
		return true; //Inputs were inserted correctly and buffer is clear or player left the game
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return false; //Some error occured, clears buffer and indicates invalid input
	}

void rules() { //Shows rules
	string line;
	ifstream myfile("RULES.txt");
	while (getline(myfile, line)) {
		cout << line << endl; 
	} //Prints every line in the rules text file
	cout << endl << endl; //Puts two paragraphs at the end of the rules
	myfile.close();
}

int getMazeChoice() { //Gets a (validated) maze choice
	int mazeChoice;
	cout << "Please insert a valid maze number: " << flush;
	cin >> mazeChoice;
	while (!mazeValidation(mazeChoice)) {
		cout << "\nInvalid Input\nYour Choice: " << flush;
		cin >> mazeChoice; //The game asks the user for new inputs until he inserts a valid one (an integer from 1 to 99) 
	}
	return mazeChoice;
}

bool mazeValidation(int choice) {
	if (((cin.peek() == '\n') && (choice >= MAZEMIN) && (choice <= MAZEMAX)) || cin.eof()) {
		return true; //Inputs were inserted correctly and buffer is clear, player wants to return to the menu
	}		//or player left the game
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return false; //Some error occured, clears buffer and indicates invalid input
}

string getPlayerName() { //Gets a name to be put in the leaderboard
	string playerName;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clears buffer to ask for name
	cout << "Congratulations!! Enter your name (15 caracters Max including spaces): " << flush;
	getline(cin, playerName); //Gets the entire line (including spaces)
	while (!nameValidation(playerName)) {
		cout << "Invalid Input \n Your Name (15 caracters Max including space): " << flush;
		getline(cin, playerName); //The game asks the user for a new name until he quit
	}						//or inserts one with less than 15 characters
	return playerName;
}

bool nameValidation(string playerName) { //Validation function for getPlayerName()
	if (cin.eof()) {
		return true;
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clears buffer (since getline didn't)
	if (playerName.length() <= PLAYERNAMEMAXSIZE) { //If the name has 15 caracters or less		
		return true;
	}
	return false; //Some error occured
}