#ifndef GAME_H

#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Robot.h"
#include "Post.h"
#include "Maze.h"
#include "Player.h"
#include "Exit.h"


using namespace std;

class Game {
private: //Atributes
	Maze maze;
	Player player;
	vector<Robot> robotList;
	bool victory;

public:
	Game(const string& filename);
	// This constructor should initialize the Maze, the vector of Robots, and the Player,
	// using the chars read from the file
	void play(); // implements the game loop; returns true if player wins, false otherwise
private: //Private methods
	//Input/Output
	void print() const;
	char getDirection(); //

	//Movements
	void move(Robot& robot); //Makes the robots move (individually) towards the player
	void move(char direction); //Makes player movement
	void reversePlayerMovement(char direction); //Reverses the player's movement
	bool validMove(char direction);

	//Collisions
	void initialCollisionCheck(char direction); //Checks if the player hit a post or a robot after moving
	void finalCollisionCheck(); //Checks if the robots hit the player or a post after moving
	
	bool collision(Robot& robot); // Checks if player and robot collided (and possibly kill player)
	bool collision(Robot& robot1, Robot& robot2); //Checks if two robots collided (and possibly kill both)
	
	bool postCollision(Robot& robot); // Checks if robot collided with any post (and possibly kill robot)	
	bool postCollision(char direction); //Checks if player collided with any post (and possibly kill player or win the game)

	//Game result
	void setGameResult(bool result);
	bool getGameResult();
};


#endif
