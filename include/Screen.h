#ifndef SCREEN_H
#define SCREEN_H
#define _WIN32_WINNT 0x500
#include "Sprite.h"
#include "Mario.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "Background.h"
#include "Level.h"
#include <string>

class Background;
class Sprite;

class Screen
{
public:
	Screen();
	~Screen();
	static void draw(Sprite *, Level *level, int color = 15);
	static void draw(Background *, int color = 15);
	static void draw(int posX, int posY, std::string str, int color = 15);
	static void clear(Sprite *, Level *level, int color = 15);
	static void setCursor(int, int);
	static void cls();
	static SMALL_RECT getSize();
	static void maximize();
};

#endif // SCREEN_H
