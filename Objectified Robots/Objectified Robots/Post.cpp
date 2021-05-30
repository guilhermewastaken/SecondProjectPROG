#include "Post.h"

Post::Post(int posX, int posY, string type) { //Constructor for new posts 
	this->posX = posX;
	this->posY = posY;
	this->type = type;
}

int Post::getPosX() const {
	return posX;
}

int Post::getPosY() const {
	return posY;
}

string Post::getType() const {
	return type;
}
