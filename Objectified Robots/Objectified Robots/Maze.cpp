#include "Maze.h"

Maze::Maze(int numRows, int numCols) {
	this->numRows = numRows;
	this->numCols = numCols;
}

void Maze::addPost(const Post& post) {
	postList.push_back(post); //Adds object to the posts vector
}

string Maze::postTypeAtPos(int posX, int posY) const {
	for (int i = 0; i < postList.size(); i++) { //Iterates through all the posts
		cout << postList[i].getPosX() << endl;
		if ((postList[i].getPosX() == posX) && (postList[i].getPosY() == posY)) { //There's a post at target location
			return postList[i].getType(); //Returns the post type
		}
	}
	return "None"; //No post
}

int Maze::getRows() const {
	return numRows;
}

int Maze::getCols() const {
	return numCols;
}