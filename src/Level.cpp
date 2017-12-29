#include "Level.h"
#include "Screen.h"
#include "Goomba.h"
#include <fstream>

using namespace std;

Level::Level(string backgroundStr, string spriteStr)
{
	Mario *mario = new Mario(2,2,20,Screen::getSize().Bottom-5);
	vector<string> marioGrid{"##","##"};
	mario->setSpriteGrid(marioGrid);
	vector<string> backgroundCharMap;
	ifstream fin(backgroundStr);
	while(!fin.eof()){
        string str;
        getline(fin,str);
        backgroundCharMap.push_back(str);
	}
	fin.close();
	fin.open(spriteStr);
	while(!fin.eof()){
	    string str;
        fin >> str;
        if(str.compare("Goomba")==0){
            int posX, posY;
            fin >> posX >> posY;
            Goomba *goomba = new Goomba(2,2,posX,posY);
            vector<string> goombaGrid = {"GG","GG"};
            goomba->setSpriteGrid(goombaGrid);
            spriteVector.push_back(goomba);
        }else if(str.compare("Star")==0){
            /*
            int posX, posY;
            fin >> posX >> posY;
            Star *star = new Star(2,2,posX,posY);
            vector<string> starGrid = {"SS","SS"};
            star->setSpriteGrid(starGrid);
            spriteVector.push_back(star);
            */
        }
	}
	fin.close();
	Background *background = new Background(backgroundCharMap);
	COORD backgroundCoord;
	backgroundCoord.X = 0;
	backgroundCoord.Y = Screen::getSize().Bottom-background->getCharMap().size();
	background->setCoord(backgroundCoord);
	this->background = background;
	this->mario = mario;
	lives = 3;
	gameOver = false;
}

Level::~Level()
{
    //dtor
}
