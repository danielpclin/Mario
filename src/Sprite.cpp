#include "Sprite.h"

using namespace std;

Sprite::Sprite()
{
	this->lengthX = 0;
	this->lengthY = 0;
	this->posX = 0;
	this->posY = 0;
	this->speedX = 0;
	this->speedY = 0;
	this->gravity = true;
}

Sprite::Sprite(int lengthX, int lengthY)
{
	this->lengthX = lengthX;
	this->lengthY = lengthY;
	this->posX = 0;
	this->posY = 0;
    this->speedX = 0;
	this->speedY = 0;
	this->gravity = true;
}

Sprite::Sprite(int lengthX, int lengthY, int posX, int posY)
{
	this->lengthX = lengthX;
	this->lengthY = lengthY;
	this->setPosX(posX);
	this->setPosY(posY);
	this->speedX = 0;
	this->speedY = 0;
	this->gravity = true;
}

Sprite::~Sprite()
{
}

int Sprite::getLengthX()
{
	return this->lengthX;
}

int Sprite::getLengthY()
{
	return this->lengthY;
}

int Sprite::getPosX()
{
	return this->posX;
}

int Sprite::getPosY()
{
	return this->posY;
}

vector<string> Sprite::getSpriteGrid()
{
	return this->spriteGrid;
}

void Sprite::setPosX(int posX)
{
    if(this->isPossibleMovement(posX,this->getPosY())){
        this->posX = posX;
    }
}

void Sprite::setPosY(int posY)
{
    if(this->isPossibleMovement(this->getPosX(),posY)){
        this->posY = posY;
    }
}

void Sprite::setSpriteGrid(vector<string> spriteGrid)
{
	this->spriteGrid = spriteGrid;
}

bool Sprite::isPossibleMovement(int posX, int posY)
{
    CONSOLE_SCREEN_BUFFER_INFO *csbi = (CONSOLE_SCREEN_BUFFER_INFO*)malloc(sizeof(CONSOLE_SCREEN_BUFFER_INFO));
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), csbi);
    if(posX<0||posY<0||posX+getLengthX()>csbi->srWindow.Right||posY+getLengthY()>csbi->srWindow.Bottom){//posY+this->getLengthY()-1>csbi->srWindow.Bottom
        return false;
    }
    //if(posX<0||posY<0||posX+this->getLengthX()>csbi->srWindow.Right||posY+this->getLengthY()>csbi->srWindow.Bottom){//posY+this->getLengthY()-1>csbi->srWindow.Bottom
    //    return false;
    //}
	return true;
}

int Sprite::getSpeedX()
{
    return this->speedX;
}
int Sprite::getSpeedY()
{
    return this->speedY;
}
void Sprite::setSpeedX(int speedX)
{
    this->speedX = speedX;
}
void Sprite::setSpeedY(int speedY)
{
    this->speedY = speedY;
}

void Sprite::update()
{

}
