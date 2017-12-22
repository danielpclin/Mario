#include "Mario.h"

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

void Mario::update()
{
    if(getSpeedX()>0){
        if(isPossibleMovement(getPosX()+1,getPosY())){
            setSpeedX(getSpeedX()-1);
            posX = posX+1;
        }else{
            setSpeedX(0);
        }
    }
    if(getSpeedX()<0){
        if(isPossibleMovement(getPosX()-1,getPosY())){
            setSpeedX(getSpeedX()+1);
            posX = getPosX()-1;
        }else{
            setSpeedX(0);
        }
    }

    if(getSpeedY()>0){
        if(isPossibleMovement(getPosX(),getPosY()+1)){
            setSpeedY(getSpeedY()-1);
            posY = getPosY()+1;
        }else{
            setSpeedY(0);
        }
    }else if(getSpeedY()<0){
        if(isPossibleMovement(getPosX(),getPosY()-2)){
            setSpeedY(getSpeedY()+1);
            posY = getPosY()-1;
        }else{
            setSpeedY(0);
        }
    }else if(getSpeedY()==0){
        if(isPossibleMovement(getPosX(),getPosY()+1)){
            posY = getPosY()+1;
        }
    }

    if(isPossibleMovement(getPosX(),getPosY()+1)){
        if(getSpeedY()==0){
            falling = true;
            jump = 0;
        }
    }else{
        falling = false;
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
