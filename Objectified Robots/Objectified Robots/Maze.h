#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include <vector>
#include <string>

#include "Post.h"

using namespace std;

class Maze {
private: //Atributes
	int numRows;
	int numCols;
	vector<Post> postList;
public:
	Maze(int numRows, int numCols); //Class constructor

	int getRows() const;
	int getCols() const;

	void addPost(const Post& post); //Adds new posts to the maze
	string postTypeAtPos(int posX, int posY) const; //Indicates if there are posts in target location and if yes, what type
	//Returns "None", "Electrified", "Not Electrified" and "Exit"
};


#endif