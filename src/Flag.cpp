#include "Flag.h"
#include "Level.h"
#include "Mario.h"

Flag::Flag(int lengthX, int lengthY, int posX, int posY) : Sprite(lengthX,lengthY,posX,posY)
{
    color = 10;
}

Flag::~Flag()
{
    //dtor
}

void Flag::update(Level *level)
{
    for(int i = 0;i<lengthX;i++){
        for(int j = 0;j<lengthY;j++){
            if((posX+i+speedX==level->mario->getPosX()+level->mario->getSpeedX()||posX+i+speedX==level->mario->getPosX()+level->mario->getSpeedX()+1)&&(posY+j+speedY==level->mario->getPosY()+level->mario->getSpeedY()||posY+j+speedY==level->mario->getPosY()+level->mario->getSpeedY()+1)){
                invisible = true;
                level->finished = true;
                //level->mario->invincible = 100;
            }
        }
    }
}
