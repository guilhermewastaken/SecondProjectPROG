#ifndef ROBOT_H
#define ROBOT_H

class Robot {
private:
	//Object atributes
	unsigned int posX;
	unsigned int posY;
	unsigned int id; //unique identification number for each robot
	bool status; //true if the robot it alive, false if not

	//Class variable (for id)
	static unsigned int counter;

public:
	Robot(unsigned int posX, unsigned int posY); //Class Constructor

	unsigned int getPosX() const;
	unsigned int getPosY() const;
	unsigned int getId() const;
	bool isAlive() const; //get() for status atribute
	void kill(); //Sets robot status to false

	//Robot Movements
	void setPos(unsigned int posX, unsigned int posY); //Non descriptive position set for reversing the robot's movement
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};

#endif

