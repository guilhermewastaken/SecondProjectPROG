#include "Maze.h"

Maze::Maze(int numRows, int numCols) {
	this->numRows = numRows;
	this->numCols = numCols;
}

void Maze::addPost(const Post& post) {
	postList.push_back(post); //Adds object to the posts vector
}

string Maze::postTypeAtPos(int posX, int posY) {
	for (int i = 0; i < postList.size(); i++) { //Iterates through all the posts
		if ((postList[i].getPosX() == posX) && (postList[i].getPosY() == posY)) { //There's a post
			if (postList[i].isElectrified()) {
				return "Electrified";
			}
			return "Not electrified"; //isElectrified returned false
		}
	}
	return "None"; //No post
}