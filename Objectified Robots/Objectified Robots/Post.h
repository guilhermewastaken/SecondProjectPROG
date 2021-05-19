#ifndef POST_H
#define POST_H

class Post {
private: //Atributes
	unsigned int posX;
	unsigned int posY;
	bool charge; //true if the post if eletrified, false if not

public:
	
	Post(unsigned int posX,unsigned int posY, bool charge); //Class constructor

//Other Methods
	unsigned int getPosX() const;
	unsigned int getPosY() const;
	bool isElectrified() const; //get() for charge atribute
};


#endif