#ifndef SCREEN_H
#define SCREEN_H
#define _WIN32_WINNT 0x500

#include "Sprite.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "Background.h"

class Background;
class Sprite;

class Screen
{
public:
	Screen();
	~Screen();
	static void draw(Sprite *);
	static void draw(Background *);
	static void clear(Sprite *);
	static void setCursor(int, int);
	static void cls();
	static SMALL_RECT getSize();
	static void maximize();
};

#endif // SCREEN_H
