#include "Level.h"
#include "Screen.h"
#include <fstream>

using namespace std;

Level::Level(string str)
{
    ifstream fin;
    fin.open(str);
	Mario *mario = new Mario(2,2,20,Screen::getSize().Bottom-5);
	vector<string> marioGrid{"##","##"};
	mario->setSpriteGrid(marioGrid);
	vector<string> backgroundCharMap;
	while(!fin.eof()){
        string str;
        getline(fin,str);
        backgroundCharMap.push_back(str);
	}
	fin.close();
	Background *background = new Background(backgroundCharMap);
	COORD backgroundCoord;
	backgroundCoord.X = 0;
	backgroundCoord.Y = Screen::getSize().Bottom-background->getCharMap().size();
	background->setCoord(backgroundCoord);
	this->background = background;
	this->mario = mario;
}

Level::~Level()
{
    //dtor
}
