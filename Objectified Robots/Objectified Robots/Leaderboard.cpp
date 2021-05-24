#include "Leaderboard.h"

Leaderboard::Leaderboard(unsigned int mazeNumber) { //Constructor for the leaderboard
	//Makes sure a file for the winners of mazeNumber's maze already exists and saves its name for later use
	//MazeNumber has already been validated

	//1- Creating the name of the winners file from mazeNumber
	stringstream name;
	if (mazeNumber < 10) {
		name << "MAZE_0"; //if maze number is less than 10, the number is filled with an 0.
	}
	else {
		name << "MAZE_";
	}
	name << mazeNumber << "_WINNERS.txt"; //Completes the maze name
	mazeName = name.str(); //Saves the name to a string for convenience

	//2- Making sure the file exists
	ifstream instream;
	ofstream outstream;
	instream.open(mazeName);
	if (instream.fail()) { //If the file doesn't already exist
		instream.close();
		outstream.open(mazeName); //Creates one
		outstream << "Player			       – Time" << endl;
		outstream << "-------------------------------------" << endl; // Writes the two default lines
		outstream.close();
	}

	//3- Checks if there already are winners 
	string line;
	int lineNum = 0;
	instream.open(mazeName);
	while (getline(instream, line)) {
		lineNum++; // Gets the number of lines in the file
	}
	emptyBoard = false;
	instream.close();
	if (lineNum == 2) {
		emptyBoard = true; //If there are only 2 lines, then no winner has been added yet
	}
}

void Leaderboard::addWinner(string name, double time) {
	//1- If there is no name in the file, the new one can just be added
	ifstream instream;
	ofstream outstream;
	if (emptyBoard) {
		outstream.open(mazeName);
		outstream << "Player			       - Time" << endl;
		outstream << "-------------------------------------" << endl; // Two default lines
		outstream << left << setw(15) << name << "			- " << time << endl; //Name and score of the player
		emptyBoard = false;
		return; //Ends the function
	}

	//2- Reads and stores everything already written in the file
	string line;
	int lineNum = 0;
	instream.open(mazeName);
	while (getline(instream, line)) {
		lineNum++; // Gets the number of lines of the file
	}
	instream.close();
	instream.open(mazeName); // Cloes and reopens the file to reset the ifstream

	for (int i = 0; i < 2; i++) {
		getline(instream, line); // Ignores the two default lines
	}

	int currentLine = 0;
	vector<int> scores;
	vector<string> names;
	while (lineNum - 2 != currentLine) { // Loop that goes through every line
		string name = "", readSequence;
		int score;
		while (instream.peek() != '\n') { //while the line is not over, we read everyting
			instream >> readSequence;
			if (readSequence != "-") {
				if (isdigit(readSequence[0])) { //if the temporary file starts with a number, it must be the score
					score = stoi(readSequence);
				}
				else { // if it is not a "-" nor a number, it is a name, so we save it.
					name += readSequence;
				}
			}
		}
		instream.ignore(1, '\n'); // clearing the new line
		scores.push_back(score); // saving the score in the scores vector
		names.push_back(name); // saving the name in the names vector

		currentLine++; // increment the line, because this one is finished
	}
	instream.close(); //after finishing reading, we close the file

	//3- Sorts the winners
	//by score
	int currentMinimum = INT_MAX;
	int minimumIndex;
	vector<int> sortedScores;
	vector<string> tempNames;
	while (scores.size() != 0) {
		for (int i = 0; i < scores.size(); i++) {
			if (scores[i] < currentMinimum) {
				currentMinimum = scores[i];
				minimumIndex = i;
			}
		}
		sortedScores.push_back(currentMinimum);
		scores.erase(scores.begin() + minimumIndex);
		tempNames.push_back(names[minimumIndex]);
		names.erase(names.begin() + minimumIndex);
	}
	scores = sortedScores;
	names = tempNames;
	
	//by name
	for (int i = 0; i < names.size(); i++) {
		if (i == scores.size() - 1) {
			break;
		}
		for (int t = i + 1; names.size(); t++) {
			if (scores[i] != scores[t]) {
				sort(names.begin() + i, names.begin()+ t);
			}
		}
	}

	//4- Saves the winners in the file
	outstream.open(mazeName);
	for (int i = 0; i < names.size(); i++) {
		outstream << left << setw(15) << names[i] << "			- " << scores[i] << endl;
	}
	outstream.close();
}

void Leaderboard::print() {
	if (emptyBoard) {
		cout << "Empty list" << endl;
	}
	else {
		string line;
		ifstream instream;
		instream.open(mazeName);
		while (getline(instream, line)) {
			cout << line << endl; //Prints every line in the file
		}
	}
}