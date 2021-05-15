#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>

using namespace std;

class Robot
{
private:

	//Object variables
	unsigned int posX;
	unsigned int posY;
	unsigned int id;
	bool status; //Status of the robot (1 - Alive | 0 - Dead)


	//Class variable
	static unsigned int counter;

public:
	Robot(unsigned int posX, unsigned int posY); //Class Constructor

	unsigned int getPosX() const; //Gets robot X position

	unsigned int getPosY() const; //Gets robot Y position

	unsigned int getId() const; //Gets robot ID (unique identifier)

	bool getStatus() const; //Get current Status of the robot

	void setStatus(bool status); //Sets robot status

	//Moving the player

	void moveUp();

	void moveDown();

	void moveLeft();

	void moveRight();
};

#endif

