#include "Screen.h"

using namespace std;

Screen::Screen()
{
}


Screen::~Screen()
{
}

void Screen::cls()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordScreen = { 0, 0 };    // home for the cursor
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    // Get the number of character cells in the current buffer.
    if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
    {
      return;
    }

    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    // Fill the entire screen with blanks.
    if( !FillConsoleOutputCharacter( hConsole,        // Handle to console screen buffer
                                    (TCHAR) ' ',     // Character to write to the buffer
                                    dwConSize,       // Number of cells to write
                                    coordScreen,     // Coordinates of first cell
                                    &cCharsWritten ))// Receive number of characters written
    {
      return;
    }

    // Get the current text attribute.
    if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
    {
      return;
    }

    // Set the buffer's attributes accordingly.
    if( !FillConsoleOutputAttribute( hConsole,         // Handle to console screen buffer
                                    csbi.wAttributes, // Character attributes to use
                                    dwConSize,        // Number of cells to set attribute
                                    coordScreen,      // Coordinates of first cell
                                    &cCharsWritten )) // Receive number of characters written
    {
      return;
    }

    // Put the cursor at its home coordinates.
    SetConsoleCursorPosition( hConsole, coordScreen );
}

void Screen::draw(Sprite *sprite)
{
    for(int i = 0; i < sprite->getSpriteGrid().size(); i++)
    {
        COORD coord;
        coord.X = sprite->getPosX();
        coord.Y = sprite->getPosY() + i;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout << sprite->getSpriteGrid().at(i);
    }

}

void Screen::draw(Background *background)
{
    for(int i = background->getCharMap().size()-1; i >= 0; i--)
    {
        COORD coord;
        coord.X = background->getCoord().X;
        coord.Y = Screen::getSize().Bottom-background->getCharMap().size()+background->getCoord().Y + i;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout << background->getCharMap().at(i);
    }
}

void Screen::clear(Sprite *sprite)
{
	for (int i = 0; i < sprite->getLengthY(); i++) {
		for (int j = 0; j < sprite->getLengthX(); j++) {
			COORD coord;
			coord.X = sprite->getPosX() + j;
			coord.Y = sprite->getPosY() + i;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			cout << ' ';
		}
	}
}

void Screen::setCursor(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

SMALL_RECT Screen::getSize()
{
    CONSOLE_SCREEN_BUFFER_INFO *csbi = (CONSOLE_SCREEN_BUFFER_INFO*)malloc(sizeof(CONSOLE_SCREEN_BUFFER_INFO));
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), csbi);
    return csbi->srWindow;
}

void Screen::maximize()
{
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
}
