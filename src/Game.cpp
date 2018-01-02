#include "Game.h"
#include "Screen.h"
#include "Background.h"
#include "Level.h"
#include "Mario.h"
#include "Sprite.h"
#include <cstdlib>
#include <time.h>

using namespace std;

Game::Game()
{
    levelVector.assign(4,NULL);
    currentLevel = -1;
    gameOver = false;
    backgroundString = "Level1.txt";
    spriteString = "Sprite1.txt";
}

Game::~Game()
{
    //dtor
}

void Game::draw()
{
    Level *level = levelVector.at(currentLevel);
    Screen::draw(level->background);
    Screen::draw(Screen::getSize().Right-20,1,"Lives: ");
    cout << level->lives;
    if(level->mario->invincible>0)
    {
        Screen::draw(level->mario,level,rand()%7+9);
    }
    else
    {
        Screen::draw(level->mario,level);
    }
    for(int i = 0;i < level->spriteVector.size();i++)
    {
        Screen::draw(level->spriteVector.at(i),level,level->spriteVector.at(i)->color);
    }
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
    level->mario->getKeypress();
    for(int i = 0;i < level->spriteVector.size();i++)
    {
        if(level->spriteVector.at(i)->invisible==false){
            level->spriteVector.at(i)->update(level);
        }
    }
    level->mario->update(level);
    level->background->update(level);
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
    if(levelVector.at(currentLevel)->lives==0){
        gameOver = true;
    }
    return gameOver;
}

void Game::init()
{
    Screen::cls();
    Screen::maximize();
    load("Level1.txt", "Sprite1.txt",0);
    load("Level2.txt", "Sprite2.txt",1);
    load("Level3.txt", "Sprite3.txt",2);
}

void Game::run()
{
    clock_t t = clock();
	while (!isOver())
    {
		if(clock()-t>=1000/20)
        {
            clear();
            update();
            draw();
            t = clock();
		}
        if(levelVector.at(currentLevel)->finished == true)
        {
            init();
            chooseLevel();
        }
        else if(levelVector.at(currentLevel)->dead == true)
        {
            init();
            load(backgroundString, spriteString,3);
            cout << "test";
        }
	}
}

void Game::chooseLevel()
{
    bool enterPressed = false;
    int selectedLevel = 0;
    Screen::draw(Screen::getSize().Right/2-24,(Screen::getSize().Bottom/6)*1,"Mario (W/S to move up and down, Enter to select.)");
    Screen::draw(Screen::getSize().Right/3,(Screen::getSize().Bottom/6)*2,"Choose Level 1");
    Screen::draw(Screen::getSize().Right/3,(Screen::getSize().Bottom/6)*3,"Choose Level 2");
    Screen::draw(Screen::getSize().Right/3,(Screen::getSize().Bottom/6)*4,"Choose Level 3");
    Screen::draw(Screen::getSize().Right/3,(Screen::getSize().Bottom/6)*5,"Choose Custom Level");
    Screen::draw(Screen::getSize().Right/3-4,(Screen::getSize().Bottom/6)*(selectedLevel+2),">");
    while(!enterPressed)
    {
        if (_kbhit()){
            Screen::cls();
            Screen::draw(Screen::getSize().Right/2-24,(Screen::getSize().Bottom/6)*1,"Mario (W/S to move up and down, Enter to select.)");
            Screen::draw(Screen::getSize().Right/3,(Screen::getSize().Bottom/6)*2,"Choose Level 1");
            Screen::draw(Screen::getSize().Right/3,(Screen::getSize().Bottom/6)*3,"Choose Level 2");
            Screen::draw(Screen::getSize().Right/3,(Screen::getSize().Bottom/6)*4,"Choose Level 3");
            Screen::draw(Screen::getSize().Right/3,(Screen::getSize().Bottom/6)*5,"Choose Custom Level");
            char keypress = _getch();
            switch(keypress){
                case VK_RETURN:
                    enterPressed = true;
                    break;
                case 'w':
                    if(selectedLevel>0){
                        selectedLevel--;
                    }
                    break;
                case 's':
                    if(selectedLevel<3){
                        selectedLevel++;
                    }
                    break;
            }
            Screen::draw(Screen::getSize().Right/3-4,(Screen::getSize().Bottom/6)*(selectedLevel+2),">");
        }
    }
    currentLevel = selectedLevel;
    if(selectedLevel==3)
    {
        string levelFile, spriteFile;
        Screen::cls();
        Screen::draw(Screen::getSize().Right/3,(Screen::getSize().Bottom/6)*2,"Enter Level Filename(Ex: Level.txt):");
        cin >> levelFile;
        Screen::draw(Screen::getSize().Right/3,(Screen::getSize().Bottom/6)*3,"Enter Sprite Filename(Ex: Sprite.txt):");
        cin >> spriteFile;
        spriteString = spriteFile;
        backgroundString = levelFile;
        load(levelFile, spriteFile);
    }
    Screen::cls();
}

void Game::end()
{
    Screen::cls();
    Screen::draw(Screen::getSize().Right/2-4,Screen::getSize().Bottom/2,"Game Over");
    Screen::draw(0,Screen::getSize().Bottom-2,"");
}
