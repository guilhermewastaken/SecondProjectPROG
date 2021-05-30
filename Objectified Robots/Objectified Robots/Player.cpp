#include "Player.h"
Player::Player(int posX, int posY) {
	this->posX = posX;
	this->posY = posY;
	life = true;
}

int Player::getPosX() const {
	return posX;
}

int Player::getPosY() const {
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