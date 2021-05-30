#include "Robot.h"

int Robot::counter = 0;

Robot::Robot(int posX, int posY) {
	counter++;

	this->posX = posX;
	this->posY = posY;
	status = true;
	id = counter;

}

int Robot::getPosX() const {
	return posX;
}

int Robot::getPosY() const {
	return posY;
}

int Robot::getId() const {
	return id;
}

bool Robot::isAlive() const {
	return status;
}

void Robot::kill() {
	status = false;
}

void Robot::setPos(int posX, int posY) {
	this->posX = posX;
	this->posY = posY;
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