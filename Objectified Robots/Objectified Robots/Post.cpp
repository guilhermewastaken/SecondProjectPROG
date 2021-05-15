#include "Post.h"

Post::Post(int postX, int postY, bool charge) { //Constructor for new posts 
	this->postX = postX;
	this->postY = postY;
	this->charge = charge;
}

unsigned int Post::getPostX() const {
	return postX;
}

unsigned int Post::getPostY() const {
	return postY;
}

bool Post::isElectrified() const {
	return charge;
}
