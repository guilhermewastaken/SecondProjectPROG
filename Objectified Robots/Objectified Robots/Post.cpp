#include "Post.h"

Post::Post(int postX, int postY, bool charge) { //Constructor for new posts 
	this->postX = postX;
	this->postY = postY;
	this->charge = charge;
}

unsigned int Post::getPostX() {
	return postX; 
}

unsigned int Post::getPostY() {
	return postY;
}

bool Post::isElectrified() {
	return charge;
}