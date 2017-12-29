#include "Mario.h"
#include <windows.h>
#include "Screen.h"

using namespace std;

Mario::Mario(int lengthX, int lengthY, int posX, int posY) : Sprite(lengthX,lengthY,posX,posY)
{
    this->falling = false;
	this->jump = 0;
}

Mario::~Mario()
{
    //dtor
}

void Mario::setJump(int jump)
{
    this->jump = jump;
}

void Mario::update(Level *level)
{
    getKeypress();

    if(isPossibleMovement(getPosX(),getPosY()+1,level)){
        if(getSpeedY()==0){
            falling = true;
            jump = 0;
        }
    }else{
        falling = false;
    }

    if(getSpeedX()>0){
        if(isPossibleMovement(getPosX()+1,getPosY(),level)){
            setSpeedX(getSpeedX()-1);
            posX = posX+1;
        }else{
            setSpeedX(0);
        }
    }
    if(getSpeedX()<0){
        if(isPossibleMovement(getPosX()-1,getPosY(),level)){
            setSpeedX(getSpeedX()+1);
            posX = getPosX()-1;
        }else{
            setSpeedX(0);
        }
    }

    if(getSpeedY()>0){
        if(isPossibleMovement(getPosX(),getPosY()+1,level)){
            setSpeedY(getSpeedY()-1);
            posY = getPosY()+1;
        }else{
            setSpeedY(0);
        }
    }else if(getSpeedY()<0){
        if(isPossibleMovement(getPosX(),getPosY()-1,level)){
            setSpeedY(getSpeedY()+1);
            posY = getPosY()-1;
        }else{
            setSpeedY(0);
        }
    }else if(getSpeedY()==0&&gravity){
        if(isPossibleMovement(getPosX(),getPosY()+1,level)){
            posY = getPosY()+1;
        }
    }

}

int Mario::getJump()
{
	return this->jump;
}

bool Mario::isFalling()
{
    return this->falling;
}

void Mario::getKeypress()
{
    if(GetKeyState('A') & 0x8000)
    {
        speedX -= 1;
    }
    if(GetKeyState('D') & 0x8000)
    {
        speedX += 1;
    }
    if(GetKeyState(' ') & 0x8000)
    {
        if(!this->isFalling()&&this->getJump() <= 1){
            if(this->getSpeedY()==0||this->getSpeedY()==-1){
                this->setJump(this->getJump()+1);
                this->setSpeedY(this->getSpeedY()-6);//8
            }
        }
    }
}

bool Mario::isPossibleMovement(int posX, int posY, Level *level)
{
    if(posX<0||posY<0||posX+lengthX-level->background->getCoord().X>Screen::getSize().Right||posY+getLengthY()>Screen::getSize().Bottom){
        return false;
    }
    if(!notCollideWithBackground(posX,posY,level)){
        return false;
    }
	return true;
}
