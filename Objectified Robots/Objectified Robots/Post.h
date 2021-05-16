#ifndef POST_H
#define POST_H

class Post {
private: //Atributes
	unsigned int postX;
	unsigned int postY;
	bool charge; //true if the post if eletrified, false if not

public:
	
	Post(int x, int y, bool charge); //Class constructor

//Other Methods
	unsigned int getPostX() const;
	unsigned int getPostY() const;
	bool isElectrified() const; //get() for charge atribute
};


#endif