#include "Game.h"

Game::Game(const string& filename) : maze(1, 1), player(1, 1) {
	ifstream instream;
	string line;
	instream.open(filename);

	int rows, columns;
	char charToIgnore;

	victory = false;

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

void Game::play() {
	while (true) { //Infinite loop that will be broken when the player either wins, loses or quits the game
		char direction;
		print(); //Prints the current state of the maze
		do {
			direction = getDirection(); //Gets a validated direction from the player
			if (cin.eof()) {
				return; //Player quit the game
			}
			move(direction); //Moves the player in the specified direction
			initialCollisionCheck(direction); //Checks if the player hit anything
		} while (!validMove(direction)); //Checks if the movement was valid. If not, ask for a new one

		if (getGameResult() == true || player.isAlive() == false) {
			return; //If the player already died or won the game it ends
		}

		for (int i = 0; i < robotList.size(); i++) {//Iterating through all the robots
			int prevRobotPosX = robotList[i].getPosX();
			int prevRobotPosY = robotList[i].getPosY();
			move(robotList[i]); //Makes each robot move towards the player
			if (collision(robotList[i])) {
				return; //The robot hit the player, game ends
			}
			if (postCollision(robotList[i])) {
				if (maze.postTypeAtPos(robotList[i].getPosX(), robotList[i].getPosY()) == "Electrified") {
					robotList[i].setPos(prevRobotPosX, prevRobotPosY);
				} //If the robot hit an electrified post, his movement will be reversed
				//Otherwise he'll replace the post
			}
		}
	}
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

//Input/Output
char Game::getDirection() {
	char direction;
	cout << "\nYour Move [A - left | D - right | W - up | X - down |"
		<< "\nQ - upper left | E - upper right | Z - lower left |"
		<< "\nC - lower right | S - Don't Move]: "
		<< flush;
	cin >> direction;
	while (true) { //Infinite loop that will be broken once a valid direction choice is reached or player quits the game
		if ((cin.peek() == '\n' && (direction == 'a' || direction == 'A'
			|| direction == 'x' || direction == 'X' || direction == 'd'
			|| direction == 'D' || direction == 'w' || direction == 'W'
			|| direction == 'q' || direction == 'Q' || direction == 's'
			|| direction == 'S' || direction == 'e' || direction == 'E'
			|| direction == 'z' || direction == 'Z' || direction == 'c'
			|| direction == 'C')) || cin.eof()) {
			return direction; //Inputs were inserted correctly and buffer is clear (player may have chosen to quit the game)
		}
		cin.clear(); //Since the direction chosen was invalid, the game asks for a new one and buffer is cleared
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nInvalid move, please choose a valid direction to move towards" <<
			"\nYour Move [A - left | D - right | W - up | X - down |"
			<< "\nQ - upper left | E - upper right | Z - lower left |"
			<< "\nC - lower right | S - Don't Move]: "
			<< flush;
		cin >> direction;
	}
}

//Movements

bool Game::validMove(char direction) {
	if (player.isAlive() == false || getGameResult() == true) {
		return true; //If the player died or won the game, the movement was valid
	}

	for (int i = 0; i < robotList.size(); i++) { //Iterates through all he robots
		if (collision(robotList[i])) {  //If the player hit a robot and didn't die, then the robot was dead
			reversePlayerMovement(direction); //Reverses the movement and indicates invalid movement
			cout << "\nInvalid move, please choose a valid direction to move towards"
				<< "\nRemember that you can't move to cells with dead robots (r) in them";
			//No need to end line because a new direction will be asked for immediatly after
			return false; 
		}
	}

	if (postCollision(direction)) {
		reversePlayerMovement(direction); //Reverses the movement and indicates invalid movement
		cout << "\nInvalid move, please choose a valid direction to move towards"
			<< "\nRemember that you can't move to cells with non electrified posts (+) in them";
		//No need to end line because a new direction will be asked for immediatly after
		return false;
	}
	return true;
}

void Game::move(Robot& robot) {
	//Horizontal movement
	if ((player.getPosX() - robot.getPosX()) < 0) { //The player is left of the robot
		robot.moveLeft();
	}
	else if ((player.getPosX() - robot.getPosX()) > 0) { //The player is right of the robot
		robot.moveRight();
	}
	//If their PosX is the same there's no need to move horizontally

	//Vertical movement
	if ((player.getPosY() - robot.getPosY()) < 0) { //The player is higher than the robot
		robot.moveUp();
	}
	else if ((player.getPosY() - robot.getPosY()) > 0) { //The player is right of the robot
		robot.moveDown();
	}
	//If their PosY is the same there's no need to move vertically
}
void Game::move(char direction) {
	if (direction == 'Q' || direction == 'q') {
		player.moveLeft(); //Upper left
		player.moveUp();
	}
	else if (direction == 'A' || direction == 'a') {
		player.moveLeft(); //Left
	}
	else if (direction == 'Z' || direction == 'z') {
		player.moveDown();//Lower left
		player.moveLeft();
	}
	else if(direction == 'X' || direction == 'x') {
		player.moveDown(); //Down
	}
	else if (direction == 'C' || direction == 'c') {
		player.moveRight(); //Lower right
		player.moveDown();
	}
	else if (direction == 'D' || direction == 'd') {
		player.moveRight(); //Right
	}
	else if (direction == 'E' || direction == 'e') {
		player.moveRight(); //Upper right
		player.moveUp();
	}
	else if (direction == 'W' || direction == 'w') {
		player.moveUp(); //Up
	}
	//If no other condition was triggered the player chose to stay still, so there's no need to update his position
}

void Game::reversePlayerMovement(char direction) {
	if (direction == 'Q' || direction == 'q') {
		player.moveRight(); //The player had moved towards the upper left
		player.moveDown();
	}
	else if (direction == 'A' || direction == 'a') {
		player.moveRight(); //The player had moved towards the left
	}
	else if (direction == 'Z' || direction == 'z') {
		player.moveUp();//The player had moved towards the lower left
		player.moveRight();
	}
	else if (direction == 'X' || direction == 'x') {
		player.moveUp(); //The player had moved downwards
	}
	else if (direction == 'C' || direction == 'c') {
		player.moveLeft(); //The player had moved towards the lower right
		player.moveUp();
	}
	else if (direction == 'D' || direction == 'd') {
		player.moveLeft(); //The player had moved towards the right
	}
	else if (direction == 'E' || direction == 'e') {
		player.moveLeft(); //The player had moved towards the upper right
		player.moveDown();
	}
	else if (direction == 'W' || direction == 'w') {
		player.moveDown(); //The player had moved upwards
	}
}

//Collision checks
void Game::initialCollisionCheck(char direction) {
	for (int i = 0; i < robotList.size(); i++) {//Iterating through all the robots
		if (collision(robotList[i]) ){
			return; //The player hit the robot
		}
	}
	postCollision(direction); //Checks for collisions with posts
}

//Collisions
bool Game::postCollision(Robot& robot) {
	if (maze.postTypeAtPos(robot.getPosX(),robot.getPosY()) != "None") { //The robot hit a post
		robot.kill(); //It dies, the position where he will lie dead will be up to the caller function to determine
		return true;
	}
	return false; //No collision
}

bool Game::collision(Robot& robot) {
	if ((robot.getPosX() == player.getPosX()) && (robot.getPosY() == player.getPosY())) { //Both at the same position
		if (robot.isAlive()) {
			player.kill();
			return true; //The player hit a functioning robot, he dies
		}		
		return true; //The player hit a dead robot, he doesn't die
		//The movement is reversed on validMove(...) method
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

bool Game::postCollision(char direction) {
	if (maze.postTypeAtPos(player.getPosX(),player.getPosY()) == "Electrified") { //Player hit an electrified post
		player.kill();
		reversePlayerMovement(direction); 
		return true;//Kills the player and reverses his movement
	}
	else if (maze.postTypeAtPos(player.getPosX(), player.getPosY()) == "Not Electrified") {
															//Player hit a non electrified post
		return true; //Invalid movement, the player movement will be reversed in validMove(...)
	}
	else if (maze.postTypeAtPos(player.getPosX(), player.getPosY()) == "Exit") { //The player hit an exit
		setGameResult(true);
		return true; //The player won the game
	}
	return false; //Player didn't hit a post
}

void Game::setGameResult(bool result) {
	victory = result;
}

bool Game::getGameResult() {
	return victory;
}