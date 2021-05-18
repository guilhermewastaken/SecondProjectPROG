#include "Exit.h"

Exit::Exit(unsigned int posX, unsigned int posY) { //Constructor for new posts 
	this->posX = posX;
	this->posY = posY;
}

unsigned int Exit::getPosX() const {
	return posX;
}

unsigned int Exit::getPosY() const {
	return posY;
}