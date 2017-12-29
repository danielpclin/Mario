#include "Goomba.h"
#include "Level.h"
#include "Mario.h"

Goomba::Goomba(int lengthX, int lengthY, int posX, int posY) : Sprite(lengthX,lengthY,posX,posY)
{
    speedX = 1;
    counter = 0;
}

Goomba::~Goomba()
{
    //dtor
}

void Goomba::update(Level *level)
{
    for(int i = 0;i<lengthX;i++){
        for(int j = 0;j<lengthY;j++){
            if((posX+i+speedX==level->mario->getPosX()||posX+i+speedX==level->mario->getPosX()+1)&&(posY+j+speedY==level->mario->getPosY()||posY+j+speedY==level->mario->getPosY()+1)){
                level->gameOver = true;//maybe add lives and reset level
            }
        }
    }
    if(getSpeedY()==0&&gravity){
        if(isPossibleMovement(getPosX(),getPosY()+1,level)){
            posY = getPosY()+1;
        }else{
            if(counter<1){
                if(getSpeedX()>0){
                    if(isPossibleMovement(getPosX()+1,getPosY(),level)){
                        posX = posX+1;
                    }else{
                        setSpeedX(-1);
                    }
                }
                counter++;
            }else{
                if(getSpeedX()<0){
                    if(isPossibleMovement(getPosX()-1,getPosY(),level)){
                        posX = getPosX()-1;
                    }else{
                        setSpeedX(1);
                    }
                }
                counter = 0;
            }
        }
    }
}

void Goomba::reverseSpeed()
{
    speedX = -speedX;
    speedY = -speedY;
}
