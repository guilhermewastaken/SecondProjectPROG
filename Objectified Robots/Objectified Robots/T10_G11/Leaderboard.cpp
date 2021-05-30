#include "Leaderboard.h"
using namespace std;

void Leaderboard::updateMazeNumber(int mazeNumber) {
	ifstream instream;
	ofstream outstream;
	mazeName = createName(mazeNumber); //Creates mazeName from mazeNumber
	
	if (!fileExists(mazeName)) { //If the file doesn't already exist
		outstream.open(mazeName); //Creates one
		outstream << "Player			       - Time" << endl;
		outstream << "-------------------------------------" << endl; // Writes the two default lines
		outstream.close();
	}	
	
	int lineNum = getNumLines(mazeName);
	emptyBoard = false;
	if (lineNum == 2) { //If there are only 2 lines, then no winner has been added yet
		emptyBoard = true; 
	}
}

void Leaderboard::addWinner(string name, int time) {
	ifstream instream;
	ofstream outstream;
	string line;

	if (emptyBoard) { //If there is no name in the file, the new one can just be added
		outstream.open(mazeName);
		outstream << "Player                         - Time" << endl;
		outstream << "-------------------------------------" << endl; //Writes the two default lines
		outstream << left << setw(15) << name << "                - " << time << endl; //Name and score of the player
		emptyBoard = false;
		outstream.close();
		return; //Ends the function
	}

	//1- Storing the contents of the file and adding to those contents the new winner
	int lineNum = getNumLines(mazeName);	
	instream.open(mazeName);
	for (int i = 0; i < 2; i++) {
		getline(instream, line); // Ignores the two default lines
	}
	vector<int> scores;
	vector<string> names;	
	for (int currentLine = 0; currentLine < lineNum - 2; currentLine++) { //Loop that goes through every line
																//and stores its contents in vectors "scores" and "names"
		string readSequence, name = "";
		int score;
		while (instream.peek() != '\n') { //Reads everything in the line
			instream >> readSequence;
			if (readSequence != "-") {
				if (isdigit(readSequence[0])) { //If the readSequence starts with a number, it must be the score
					score = stoi(readSequence);
				}
				else { //If it is neither a "-" nor a number, it is a name
					name += readSequence;
					name += " ";
				}
			}
		}
		instream.ignore(1, '\n'); //Clears the line and moves onto next one(only \n was left)
		scores.push_back(score); //Saves the score in the scores vector
		name.erase(name.length() - 1); // removing the extra space
		names.push_back(name); //Saves the name in the names vector
	}
	instream.close();	
	scores.push_back(time);
	names.push_back(name); //Adds the new score to the stored file contents
	
	//2- Sorting the file contents:
	//by score	
	
	vector<int> sortedScores;
	vector<string> tempNames;
	while (scores.size() != 0) { //Until all scores have been processed
		int currentMinimum = INT_MAX;
		int minimumIndex = 0; // initializing to remove warning
		for (int i = 0; i < scores.size(); i++) {
			if (scores[i] < currentMinimum) { //Iterates through every time and selects the smallest
				currentMinimum = scores[i];
				minimumIndex = i; //Stores its index
			}
		}
		sortedScores.push_back(currentMinimum);
		scores.erase(scores.begin() + minimumIndex); //Adds the best time to the sorted vectors
		tempNames.push_back(names[minimumIndex]);
		names.erase(names.begin() + minimumIndex); //Removes it from the original
	}
	scores = sortedScores;
	names = tempNames; //Updates the vectors with the sorted values
	
	//and by name
	for (int i = 0; i < names.size() - 1; i++) { //Iterates through all names until only one is left
		for (int t = i + 1; t < names.size(); t++) {
			if (scores[i] != scores[t]) { //Iterates through all names with the same score as names[i]
				sort(names.begin() + i, names.begin()+ t); //Sorts them by name
			}
		}
	}

	//3- Saving the winners in the file
	outstream.open(mazeName);
	outstream << "Player                         - Time" << endl;
	outstream << "-------------------------------------" << endl; //Writes the two default lines
	for (int i = 0; i < names.size(); i++) { //Saves each winner and his time sequencially
		outstream << left << setw(15) << names[i] << "                - " << scores[i] << endl;
	}
	outstream.close();
}

void Leaderboard::print() {
	if (emptyBoard) { //If there are no winners in the file
		cout << "Empty list" << endl;
	}
	else {
		string line;
		ifstream instream;
		instream.open(mazeName);
		while (getline(instream, line)) {
			cout << line << endl; //Prints every line in the file
		}
		instream.close();
	}

}
//Private atributes
string Leaderboard::createName(int mazeNumber) {
	stringstream name;
	if (mazeNumber < 10) {
		name << "MAZE_0"; //if maze number is less than 10, the number is filled with an 0.
	}
	else {
		name << "MAZE_";
	}	
	name << mazeNumber << "_WINNERS.txt"; //Completes the maze name
	return (name.str()); //Saves the name to a string and returns
}

bool Leaderboard::fileExists(string mazeName) {
	ifstream instream;
	ofstream outstream;
	instream.open(mazeName);
	if (instream.fail()) {
		instream.close();
		return false; //File doesn't already exist
	}
	instream.close();
	return true; //File already exists
}

int Leaderboard::getNumLines(string mazeName) {
	ifstream instream;
	string line;
	int lineNum = 0;
	instream.open(mazeName);
	while (getline(instream, line)) {
		lineNum++; // Gets the number of lines in the file
	}
	instream.close();
	return lineNum;
}