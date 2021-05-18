#include "Post.h"

Post::Post(unsigned int posX, unsigned int posY, bool charge) { //Constructor for new posts 
	this->posX = posX;
	this->posY = posY;
	this->charge = charge;
}

unsigned int Post::getPostX() const {
	return posX;
}

unsigned int Post::getPostY() const {
	return posY;
}

bool Post::isElectrified() const {
	return charge;
}
