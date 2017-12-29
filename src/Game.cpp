#include "Game.h"
#include "Screen.h"
#include "Background.h"
#include "Level.h"
#include "Mario.h"
#include "Sprite.h"

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
    Screen::draw(level->background);
    Screen::draw(level->mario,level);
    for(int i = 0;i < level->spriteVector.size();i++)
    {
        Screen::draw(level->spriteVector.at(i),level);
    }
    //goto 00
    //cout << "¡½";
}

void Game::load(string backgroundStr, string spriteStr)
{
    Level *level = new Level(backgroundStr, spriteStr);
    this->levelVector.push_back(level);
}

void Game::load(string backgroundStr, string spriteStr, int levelID)
{
    Level *level = new Level(backgroundStr, spriteStr);
    this->levelVector.at(levelID) = level;
}

void Game::update()
{
    Level *level = levelVector.at(currentLevel);
    level->mario->update(level);
    level->background->update(level);
    for(int i = 0;i < level->spriteVector.size();i++)
    {
        level->spriteVector.at(i)->update(level);
    }
}

void Game::clear()
{
    Level *level = levelVector.at(currentLevel);
    Screen::clear(level->mario,level);
    for(int i = 0;i < level->spriteVector.size();i++)
    {
        Screen::clear(level->spriteVector.at(i),level);
    }
}

bool Game::isOver()
{
    Level *level = levelVector.at(currentLevel);
    return level->gameOver;
}
