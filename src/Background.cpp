#include "Background.h"
#include "Screen.h"

using namespace std;

Background::Background(vector<string> charMap)
{
    this->charMap = charMap;
    COORD coord;
    coord.X=0;
    coord.Y=0;
    this->setCoord(coord);
}

Background::Background()
{
    COORD coord;
    coord.X=0;
    coord.Y=0;
    this->setCoord(coord);
}

Background::~Background()
{
    //dtor
}

void Background::setCoord(COORD backgroundCoord)
{
    this->backgroundCoord = backgroundCoord;
}

COORD Background::getCoord()
{
    return this->backgroundCoord;
}

void Background::setCharMap(vector<string>charMap)
{
    this->charMap = charMap;
}

vector<string> Background::getCharMap()
{
    return this->charMap;
}

void Background::update(Level *level)
{
    if((backgroundCoord.X+Screen::getSize().Right-level->mario->getPosX())<=(Screen::getSize().Right*0.1))
    {
        if((charMap.at(0).size()-level->mario->getPosX())>=(Screen::getSize().Right*0.1))
        {
            this->backgroundCoord.X += 1;
        }
    }

    if((level->mario->getPosX()-this->backgroundCoord.X)<=(Screen::getSize().Right*0.1))
    {
        if((level->mario->getPosX())>=(Screen::getSize().Right*0.1))
        {
            this->backgroundCoord.X -= 1;
        }
    }
}
