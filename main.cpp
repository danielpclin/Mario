#include <time.h>
#include "Game.h"
#include <stdlib.h>
#include "Screen.h"

using namespace std;

int main(){
    Screen::maximize();
    Game game;
    game.load("Level1.txt", "Sprite1.txt");
    game.currentLevel = 0;
	clock_t t = clock();
	while (!game.isOver())
    {
		if(clock()-t>=1000/20)
        {
            game.clear();
            game.update();
            game.draw();
            t = clock();
		}
	}
	system("cls");
	system("pause");
	return 0;
}
