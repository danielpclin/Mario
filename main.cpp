#include <time.h>
#include "Game.h"
#include <stdlib.h>

using namespace std;

int main(){
    Game game;
    game.load("Level1.txt");
    game.currentLevel = 0;
	//Screen::maximize();
	clock_t t = clock();
	while (true)
    {
		if(clock()-t>=1000/40)
        {
            game.draw();
            game.update();
        t = clock();
		}
	}
	system("pause");
	return 0;
}
