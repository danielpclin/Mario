#include "Goomba.h"
#include "Level.h"
#include "Mario.h"
#include "Screen.h"

Goomba::Goomba(int lengthX, int lengthY, int posX, int posY) : Sprite(lengthX,lengthY,posX,posY)
{
    speedX = 1;
    counter = 0;
    color = 12;
}

Goomba::~Goomba()
{
    //dtor
}

void Goomba::update(Level *level)
{
    bool subtractLife = false;
    for(int i = 0;i<lengthX;i++){
        for(int j = 0;j<lengthY;j++){
            if((posX+i+speedX==level->mario->getPosX()+level->mario->getSpeedX()||posX+i+speedX==level->mario->getPosX()+level->mario->getSpeedX()+1)&&(posY+j+speedY==level->mario->getPosY()+level->mario->getSpeedY()||posY+j+speedY==level->mario->getPosY()+level->mario->getSpeedY()+1)){
                if(level->mario->invincible>0)
                {
                    invisible = true;
                }
                else if((posX+i+speedX==level->mario->getPosX()+level->mario->getSpeedX()||posX+i+speedX==level->mario->getPosX()+level->mario->getSpeedX()+1)&&(posY+j+speedY-1==level->mario->getPosY()||posY+j+speedY-1==level->mario->getPosY()+1))
                {
                    invisible = true;
                }
                else
                {
                    subtractLife = subtractLife || true;
                }
            }
        }
    }
    if(subtractLife){
        level->lives--;
        level->dead = true;
        Screen::cls();
        return;
    }

    if(getSpeedY()==0&&gravity){
        if(isPossibleMovement(getPosX(),getPosY()+1,level)){
            posY = getPosY()+1;
        }else{
            if(counter<1){
                if(getSpeedX()>0){
                    if(isPossibleMovement(getPosX()+1,getPosY(),level)&&!(notCollideWithBackground(getPosX()+2,getPosY()+1,level))){
                        posX = posX+1;
                    }else{
                        setSpeedX(-1);
                    }
                }
                counter++;
            }else{
                if(getSpeedX()<0){
                    if(isPossibleMovement(getPosX()-1,getPosY(),level)&&!(notCollideWithBackground(getPosX()-2,getPosY()+1,level))){
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
