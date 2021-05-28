#ifndef GAME_H

#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>

#include "Robot.h"
#include "Post.h"
#include "Maze.h"
#include "Player.h"
#include "Exit.h"

class Game {
private: //Atributes
	int scoreMultiplier = 50; //Arbitrary number defined by us to get an adjusted scoreboard
	chrono::system_clock::time_point gameBegin; //Time since the beginning of the program
	string mazeName;
	Maze maze;
	Player player;
	vector<Robot> robotList;
	bool victory;

public:
	//Constructor and maze creation methods
	Game(int mazeNumber); //Constructor that only stores the file name
	void updateMazeNumber(int mazeNumber); //Changes the file name
	bool validMaze(); //Checks if the file exists
	void createMaze(); //Reads the contents of the file and creates objects for classes Maze, Robots and Player

	void play(); // implements the game loop
	bool playerVictory(); //indicates whether the player won (true) or lost (false)
	int getScore();
private: //Private methods

	void gameStart(); //Set method for gameBegin

	//I/O Methods
	void print() const; //prints the current state of the maze, with posts, robots and the player
	char getDirection(); //gets a validated direction choice from the player
	//it doesn't check for dead robots or non electrified posts in the destination

	//Movement Methods
	void move(Robot& robot); //Makes a robots move towards the player
	void move(char direction); //Makes player move in a certain direction
	void reversePlayerMovement(char direction); //Reverses the player's movement
	bool validMove(char direction); //Check for dead robots or non electrified posts in the player destination

	//Collision Methods
	void initialCollisionCheck(char direction); //Checks if the player hit a post or a robot after moving
	
	bool collision(Robot& robot); // Checks if player and robot collided (and possibly kill player)
	bool collision(Robot& robot1, Robot& robot2); //Checks if two robots collided (and possibly kill both)
	
	bool postCollision(Robot& robot); // Checks if robot collided with any post (and possibly kill robot)	
	bool postCollision(char direction); //Checks if player collided with any post (and possibly kill player or win the game)

	//Game result (set and get) Methods
	void setVictory(bool result);
};


#endif
