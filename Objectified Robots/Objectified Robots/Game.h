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
	vector<Exit> exitList;

public:
	Game(const string& filename);
	// This constructor should initialize the Maze, the vector of Robots, and the Player,
	// using the chars read from the file
	bool play(); // implements the game loop; returns true if player wins, false otherwise
	bool isValid();

private: //Private methods
	void print() const;

	//Collisions
	bool collision(Robot& robot, Post& post); // Checks if robot collided with post (and possibly kill robot)
	bool collision(Robot& robot, Player& player); // Checks if player and robot collided (and possibly kill player)
	bool collision(Robot& robot1, Robot& robot2); //Checks if two robots collided (and possibly kill both)
	bool collision(Post& post, Player& player); //Checks if player collided with post (and possibly kill player)
	bool victory(Post& post, Player& player) const; //Checks if the player hit an exit
	//Must only be used after a collision with a post has been established

												  // other methods, for example:
	// to check if player is trying to move to a valid place
	// to apply a valid play and check collisions
};


#endif
