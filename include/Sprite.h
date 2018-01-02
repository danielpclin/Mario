#ifndef SPRITE_H
#define SPRITE_H
#include <vector>
#include <string>

class Level;

class Sprite
{
public:
	Sprite();
	Sprite(int lengthX, int lengthY);
	Sprite(int lengthX, int lengthY, int posX, int posY);
	~Sprite();
	int getLengthX();
	int getLengthY();
	int getPosX();
	int getPosY();
	int getSpeedX();
	int getSpeedY();
	std::vector<std::string> getSpriteGrid();
	//int setLengthX();
	//int setLengthY();
	void setPosX(int posX);
	void setPosY(int posY);
	void setSpeedX(int speedX);
	void setSpeedY(int speedY);
	void setSpriteGrid(std::vector<std::string>);
	virtual bool isPossibleMovement(int posX, int posY, Level *level);
	virtual void update(Level *level) = 0;
	bool notCollideWithBackground(int posX, int poxY, Level *level);
	int color;
	bool invisible;
protected:
    int speedX;
    int speedY;
	int lengthX;
	int lengthY;
	int posX;//Position X on the top left of the sprite
	int posY;//Position Y on the top left of the sprite
	std::vector<std::string> spriteGrid;//maybe change to array of strings
	bool gravity;
};

#endif // SPRITE_H
