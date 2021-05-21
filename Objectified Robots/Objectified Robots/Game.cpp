#include "Game.h"

Game::Game(const string& filename) : maze(1, 1), player(1, 1) {
	ifstream instream;
	string line;
	instream.open(filename);

	int rows, columns;
	char charToIgnore;

	instream >> rows >> charToIgnore >> columns; //Gets the rows and columns of the maze
	Maze maze(rows, columns);
	this->maze = maze;
	unsigned int numberOfRow = 0;
	while (getline(instream, line)) {
		for (unsigned int i = 0; i < line.size(); i++) {
			switch (line[i]) {
			case '*':
				Post post(i, numberOfRow, 1);
				maze.addPost(post);
				break;
			case '+':
				Post post(i, numberOfRow, 0);
				maze.addPost(post);
				break;
			case 'H':
				Player player(i, numberOfRow);
				this->player = player;
				break;
			case 'R':
				Robot robot(i, numberOfRow);
				robotList.push_back(robot);
				break;
			case 'O':
				Exit exit(i, numberOfRow);
				exitList.push_back(exit);
				break;
			}
			numberOfRow++;
		}
	}


}
