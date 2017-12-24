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
    this->posX = posX;
    //if(this->isPossibleMovement(posX,this->getPosY(),level)){
    //    this->posX = posX;
    //}
}

void Sprite::setPosY(int posY)
{
    this->posY = posY;
    //if(this->isPossibleMovement(this->getPosX(),posY)){
    //    this->posY = posY;
    //}
}

void Sprite::setSpriteGrid(vector<string> spriteGrid)
{
	this->spriteGrid = spriteGrid;
}

bool Sprite::isPossibleMovement(int posX, int posY, Level *level)
{
    if(posX<0||posY<0||posX+lengthX-level->background->getCoord().X>Screen::getSize().Right||posY+getLengthY()>Screen::getSize().Bottom){
        return false;
    }
    if(!notCollideWithBackground(posX,posY,level)){
        return false;
    }
	return true;
}

bool Sprite::notCollideWithBackground(int posX, int posY, Level *level)
{
    bool result = true;
    for(int i = 0;i<lengthX;i++){
        for(int j = 0;j<lengthY;j++){
            try{
                if(level->background->getCharMap().at(posY-Screen::getSize().Bottom+level->background->getCharMap().size()+j-1).compare(posX+i,1," ")==0){
                    //cout << "true" << posY-Screen::getSize().Bottom+level->background->getCharMap().size()+j << " " << posX + i;
                    result = result&&true;
                }else{
                    //cout << "false" << posY-Screen::getSize().Bottom+level->background->getCharMap().size()+j << " " << posX + i;
                    result = result&&false;
                }
            }catch(out_of_range e){
                result = result&&true;
            }
        }
    }
    return result;
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

void Sprite::update(Level *level)
{

}
