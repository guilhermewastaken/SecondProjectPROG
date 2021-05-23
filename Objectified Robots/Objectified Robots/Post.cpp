#include "Post.h"

Post::Post(unsigned int posX, unsigned int posY, string type) { //Constructor for new posts 
	this->posX = posX;
	this->posY = posY;
	this->type = type;
}

unsigned int Post::getPosX() const {
	return posX;
}

unsigned int Post::getPosY() const {
	return posY;
}

string Post::getType() const {
	return type;
}
