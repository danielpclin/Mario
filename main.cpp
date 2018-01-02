#include "Game.h"
#include <stdlib.h>

using namespace std;

int main(){
    Game game;
    game.init();
    game.chooseLevel();
    game.run();
	game.end();
	system("pause");
	return 0;
}
