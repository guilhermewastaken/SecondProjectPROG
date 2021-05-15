#ifndef POST_H
#define POST_H


class Post {
public:
	Post(int x, int y, bool charge); //Constructor for new posts

//Other Methods
	unsigned int getPostX() const;
	unsigned int getPostY() const;
	bool isElectrified() const;

private:
	//Atributes
	unsigned int postX;
	unsigned int postY;
	bool charge; //true if the post if eletrified, false if not
};


#endif