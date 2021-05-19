#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
	unsigned int posX;
	unsigned int posY;
	bool life; //true if the player it alive, false if not

public:
	Player(unsigned int posX, unsigned int posY); //Class constructor

	unsigned int getPosX() const;
	unsigned int getPosY() const;
	bool isAlive() const; //get() for life atribute
	void kill(); //sets player's life to false
	
	//Player Movements
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};

#endif

