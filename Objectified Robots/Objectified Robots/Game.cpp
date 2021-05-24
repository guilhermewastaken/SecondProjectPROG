#include "Game.h"

Game::Game(const string& filename) : maze(1, 1), player(1, 1) {
	ifstream instream;
	string line;
	instream.open(filename);

	int rows, columns;
	char charToIgnore;

	instream >> rows >> charToIgnore >> columns; //Gets the rows and columns of the maze
	getline(instream, line); // Clear the line
	Maze maze(rows, columns);
	unsigned int numberOfRow = 0;
	while (getline(instream, line)) {
		for (unsigned int i = 0; i < line.size(); i++) {
			if (line[i] == '*') {
				Post post(i, numberOfRow, "Electrified");
				maze.addPost(post); //Adds electrified post to maze
			}
			else if (line[i] == '+') {
				Post post(i, numberOfRow, "Not electrified");
				maze.addPost(post); //Adds not electrified post to maze
			}
			else if (line[i] == 'O') {
				Post post(i, numberOfRow, "Exit");
				maze.addPost(post); //Adds exit to maze
			}
			else if (line[i] == 'H') {
				Player player(i, numberOfRow);
				this->player = player;
			}
			else if (line[i] == 'R') {
				Robot robot(i, numberOfRow);
				robotList.push_back(robot);
			}

		}
		numberOfRow++;
	}
	instream.close();
	this->maze = maze;
}

void Game::print() const {
	for (int row = 0; row < maze.getRows(); row++) {

		for (int col = 0; col < maze.getCols(); col++) { //Iterates through each position in the matrix
			//If several objects are in the same cell only one will be outputed. The priorities are as follows:
			// 1- Player	2- Robots	3- Posts
			if (col == player.getPosX() && row == player.getPosY()) { //Player object found in the cell
				if (player.isAlive()) {
					cout << "H"; //The player is alive, prints H and moves on to next cell
					continue;
				}
				cout << "h"; //The player is dead, prints h and moves on to next cell
				continue;
			}

			bool skipCell = false;
			for (int i = 0; i < robotList.size(); i++) { //iterates through all the robots
				if (col == robotList[i].getPosX() && row == robotList[i].getPosY()) { //Robot object found in the cell
					if (robotList[i].isAlive()) {
						cout << "R"; //The robot is alive, prints R and moves on to next cell
						skipCell = true;
						break;
					}
					cout << "r"; //The robot is dead, prints r and moves on to next cell
					continue;
				}
			}
			if (skipCell) {
				continue;
			}
			
			//Checks for posts
			if (maze.postTypeAtPos(col, row) == "Exit") { //There's an exit in the cell
				cout << "O";
			}
			else if (maze.postTypeAtPos(col, row) == "Electrified") { //There's an electrified post in the cell
				cout << "*";
			}
			else if (maze.postTypeAtPos(col, row) == "Not Electrified") { //There's a non electrified in the cell
				cout << "+";
			}
			else if (maze.postTypeAtPos(col, row) == "None") { //Nothig was found occupying the cell
				cout << " ";
			} 
		}
		cout << "\n"; //Moves onto next paragraph
	}
}

//Collisions
bool Game::collision(Robot& robot, Post& post) {
	if ((robot.getPosX() == post.getPosX()) && (robot.getPosY() == post.getPosY())) { //Both at the same position
		robot.kill(); //The robot is killed immediatly, but where it will lie dead will be decided in the caller method
		return true;
	}
	return false; //No collision
}

bool Game::collision(Robot& robot, Player& player) {
	if ((robot.getPosX() == player.getPosX()) && (robot.getPosY() == player.getPosY())) { //Both at the same position
		if (robot.isAlive()) {
			player.kill();
			return true; //The player hit a functioning robot, he dies
		}
		return true; //The player hit a dead robot, he doesn't die
	}
	return false; //No collision
}

bool Game::collision(Robot& robot1, Robot& robot2) {
	if ((robot1.getPosX() == robot2.getPosX()) && (robot1.getPosY() == robot2.getPosY())) { //Both at the same position
		robot1.kill();
		robot2.kill();
		return true; //The robots hit eachother, both die (doesn't matter if they're allready dead
		}
	return false; //No collision
}

bool Game::collision(Post& post, Player& player) {
	if ((post.getPosX() == player.getPosX()) && (post.getPosY() == player.getPosY())) { //Both at the same position
		if (post.getType() == "Electrified") {
			player.kill(); //The player hit an electrified robot, he dies
			return true;
		}
		return true; //The player hit either an exit or an electrified post. Game::victory() will be used next
	}
}

bool Game::victory(Post& post, Player& player) const { //This method assumes the player and the post are in the same position
	if (post.getType() == "Exit") {
		return true; //The player hit an exit
	}
	return false;
}