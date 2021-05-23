#ifndef POST_H
#define POST_H

#include <string>

using namespace std;

class Post {
private: //Atributes
	unsigned int posX;
	unsigned int posY;
	string type; //Indicates whether the post is electrified or not and if it is an exit
	//"Electrified", "Not electrified", "Exit"

public:
	
	Post(unsigned int posX,unsigned int posY, string type); //Class constructor

//Other Methods
	unsigned int getPosX() const;
	unsigned int getPosY() const;
	string getType() const;
};


#endif