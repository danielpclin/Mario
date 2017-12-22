#include <iostream>
#include "Sprite.h"
#include "Screen.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <time.h>
#include "Background.h"
#include <fstream>
#include "Mario.h"


using namespace std;

int main() {
    ifstream fin;
    fin.open("Background.txt");
	Mario *mario = new Mario(2,2,8,8);
	vector<string> marioGrid{"##","##"};
	mario->setSpriteGrid(marioGrid);
	vector<string> backgroundCharMap;
	while(!fin.eof()){
        string str;
        getline(fin,str);
        backgroundCharMap.push_back(str);
	}
	Background *background = new Background(backgroundCharMap);
	//Screen::maximize();
	clock_t t = clock();

	while (true)
    {
        //Screen::setCursor(0,0);
		if(clock()-t>=1000/30)
        {
            Screen::cls();
            //Screen::clear(mario);
            Screen::draw(background);
            Screen::draw(mario);
            //if(GetKeyState('W') & 0x8000 /*check if high-order bit is set (1 << 15)*/)
            //{
            //    mario->setSpeedY(-1);
            //}
            if(GetKeyState('A') & 0x8000)
            {
                mario->setSpeedX(mario->getSpeedX()-1);
            }
            //if(GetKeyState('S') & 0x8000)
            //{
            //    mario->setSpeedY(1);
            //}
            if(GetKeyState('D') & 0x8000)
            {
                mario->setSpeedX(mario->getSpeedX()+1);
            }
            if(GetKeyState(' ') & 0x8000)
            {
                if(!mario->isFalling()&&mario->getJump() <= 1){
                    if(mario->getSpeedY()==0||mario->getSpeedY()==-1){
                        mario->setJump(mario->getJump()+1);
                        mario->setSpeedY(mario->getSpeedY()-8);
                    }
                }
            }
            mario->update();
        t = clock();
		}
	}
	system("pause");
	return 0;
}

/*
if (_kbhit()){
    char keypress = _getch();
    switch(keypress){
        case 'w':
            cout << 'w';
            break;
        case 'a':
            cout << 'a';
            break;
        case 's':
            cout << 's';
            break;
        case 'd':
            cout << 'd';
            break;
        case ' ':
            cout << ' ';
            break;
    }
}*/
/*
while (true)
{
    system("cls");
    Screen::draw(mario);
    Screen::setCursor(0,0);
    cout << time(0);
    if (_kbhit())
    {
    char keypress = _getch();
        switch(keypress)
        {
            case 'w':
                mario->setPosY(mario->getPosY()-1);
                break;
            case 'a':
                mario->setPosX(mario->getPosX()-1);
                break;
            case 's':
                mario->setPosY(mario->getPosY()+1);
                break;
            case 'd':
                mario->setPosX(mario->getPosX()+1);
                break;
            case ' ':
                mario->setPosY(mario->getPosY()-1);
                break;
        }
    }
}
*/
//Sleep( 1000/60 );
