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
				Post post(i, numberOfRow, "Electrified"); 
				maze.addPost(post); //Adds electrified post to maze
				break;
			case '+':
				Post post(i, numberOfRow, "Not electrified"); 
				maze.addPost(post); //Adds not electrified post to maze
				break;
			case 'O':
				Post post(i, numberOfRow, "Exit");
				maze.addPost(post); //Adds exit to maze
				break;
			case 'H':
				Player player(i, numberOfRow);
				this->player = player;
				break;
			case 'R':
				Robot robot(i, numberOfRow);
				robotList.push_back(robot);
				break;
			}
			numberOfRow++;
		}
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