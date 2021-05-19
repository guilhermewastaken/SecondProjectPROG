#include "Player.h"
Player::Player(unsigned int posX, unsigned int posY) {
	this->posX = posX;
	this->posY = posY;
	life = true;
}

unsigned int Player::getPosX() const {
	return posX;
}

unsigned int Player::getPosY() const {
	return posY;
}

bool Player::isAlive() const {
	return life;
}

void Player::kill() {
	life = false;
}

void Player::moveUp() {
	posY--;
}

void Player::moveDown() {
	posY++;
}

void Player::moveLeft() {
	posX--;
}

void Player::moveRight() {
	posX++;
}