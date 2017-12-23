#include "Background.h"

using namespace std;

Background::Background(vector<string> charMap)
{
    this->charMap = charMap;
    COORD coord;
    coord.X=0;
    coord.Y=Screen::getSize().Bottom;
    this->setCoord(coord);
}

Background::Background()
{
    COORD coord;
    coord.X=0;
    coord.Y=Screen::getSize().Bottom;
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
