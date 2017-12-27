#include "Game.h"
#include "Screen.h"
#include "Background.h"
#include "Level.h"
#include "Mario.h"

using namespace std;

Game::Game()
{
    currentLevel = -1;
}

Game::~Game()
{
    //dtor
}


void Game::draw()
{
    Level *level = levelVector.at(currentLevel);
    Screen::cls();
    //Screen::clear(mario);
    Screen::draw(level->background);
    Screen::draw(level->mario,level);
    /*
    for(int i = 0;i < level->spriteVector.length();i++)
    {
        Screen::draw(level->spriteVector(i),level);
    }
    */
}

void Game::load(string str)
{
    Level *level = new Level(str);
    this->levelVector.push_back(level);
}

void Game::update()
{
    Level *level = levelVector.at(currentLevel);
    level->mario->update(level);
    level->background->update(level);
}
