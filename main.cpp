#include <iostream>
#include "Screen.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <time.h>
#include "Background.h"
#include <fstream>
#include "Mario.h"
#include "Level.h"

using namespace std;

int main(){
    ifstream fin;
    fin.open("Background.txt");
	Mario *mario = new Mario(2,2,20,Screen::getSize().Bottom-2-2);
	vector<string> marioGrid{"##","##"};
	mario->setSpriteGrid(marioGrid);
	vector<string> backgroundCharMap;
	while(!fin.eof()){
        string str;
        getline(fin,str);
        backgroundCharMap.push_back(str);
	}
	Background *background = new Background(backgroundCharMap);
	COORD backgroundCoord;
	backgroundCoord.X = 0;
	backgroundCoord.Y = Screen::getSize().Bottom-background->getCharMap().size()+1;
	background->setCoord(backgroundCoord);
	Level *level1 = new Level();
	level1->background = background;
	level1->spriteVector.push_back(mario);
	//Screen::maximize();
	clock_t t = clock();
	//Screen::draw(background);
	while (true)
    {
        //Screen::setCursor(0,0);
		if(clock()-t>=1000/30)
        {
            Screen::cls();
            //Screen::clear(mario);
            Screen::draw(background);
            Screen::draw(mario,level1);

            if(GetKeyState('A') & 0x8000)
            {
                mario->setSpeedX(mario->getSpeedX()-1);
            }
            if(GetKeyState('D') & 0x8000)
            {
                mario->setSpeedX(mario->getSpeedX()+1);
            }
            if(GetKeyState(' ') & 0x8000)
            {
                if(!mario->isFalling()&&mario->getJump() <= 1){
                    if(mario->getSpeedY()==0||mario->getSpeedY()==-1){
                        mario->setJump(mario->getJump()+1);
                        mario->setSpeedY(mario->getSpeedY()-6);//8
                    }
                }
            }
            mario->update(level1);
            background->update(level1);
        t = clock();
		}
	}
	system("pause");
	return 0;
}
