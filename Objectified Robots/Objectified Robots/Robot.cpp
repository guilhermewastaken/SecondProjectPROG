#include "Robot.h"

unsigned int Robot::counter = 0;

Robot::Robot(unsigned int posX, unsigned int posY) {
	counter++;

	this->posX = posX;
	this->posY = posY;
	status = true;
	id = counter;

}

unsigned int Robot::getPosX() const {
	return posX;
}

unsigned int Robot::getPosY() const {
	return posY;
}

unsigned int Robot::getId() const {
	return id;
}

bool Robot::isAlive() const {
	return status;
}

void Robot::kill() {
	status = false;
}

void Robot::moveUp() {
	posY--;
}

void Robot::moveDown() {
	posY++;
}

void Robot::moveLeft() {
	posX--;
}

void Robot::moveRight() {
	posX++;
}