#ifndef ROBOT_H
#define ROBOT_H

class Robot {
private:
	//Object atributes
	int posX;
	int posY;
	int id; //unique identification number for each robot
	bool status; //true if the robot it alive, false if not

	//Class variable (for id)
	static int counter;

public:
	Robot(int posX, int posY); //Class Constructor

	int getPosX() const;
	int getPosY() const;
	int getId() const;
	bool isAlive() const; //get() for status atribute
	void kill(); //Sets robot status to false

	//Robot Movements
	void setPos(int posX, int posY); //Non descriptive position set for reversing the robot's movement
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};

#endif

