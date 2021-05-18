#ifndef ROBOT_H
#define ROBOT_H

class Exit {
private:
	unsigned int posX;
	unsigned int posY;
public:
	Exit(unsigned int posX, unsigned int posY); //Class constructor
	unsigned int getPosX() const;
	unsigned int getPosY() const;
};

#endif

