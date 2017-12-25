#include "Mario.h"

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
    }else if(getSpeedY()==0){
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
