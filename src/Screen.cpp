#include "Screen.h"
#include <iomanip>


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

void Screen::draw(Sprite *sprite, Level *level, int color)
{
    if(sprite->invisible==true){
        return;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    if(sprite->getPosX()-level->background->getCoord().X>=0&&level->background->getCoord().X+getSize().Right-sprite->getPosX()-sprite->getLengthX()+1>=0){
        for(int i = 0; i < (int)sprite->getSpriteGrid().size(); i++)
        {
            COORD coord;
            coord.X = sprite->getPosX() - level->background->getCoord().X;
            coord.Y = sprite->getPosY() + i;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout << sprite->getSpriteGrid().at(i);
        }
    }
}

void Screen::draw(int posX, int posY, string str, int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    COORD coord;
    coord.X = posX;
    coord.Y = posY;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << str;
}

void Screen::draw(Background *background, int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    for(int i = 0; i < background->getCharMap().size(); i++)
    {
        COORD coord;
        coord.X = 0;
        coord.Y = background->getCoord().Y + i;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout << background->getCharMap().at(i).substr(background->getCoord().X,Screen::getSize().Right+1);
    }
}

void Screen::clear(Sprite *sprite , Level *level, int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    if(sprite->getPosX()-level->background->getCoord().X>=0&&level->background->getCoord().X+getSize().Right-sprite->getPosX()-sprite->getLengthX()+1>=0){
        for(int i = 0; i < (int)sprite->getSpriteGrid().size(); i++)
        {
            COORD coord;
            coord.X = sprite->getPosX() - level->background->getCoord().X;
            coord.Y = sprite->getPosY() + i;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout << setw(sprite->getSpriteGrid().at(i).size()) << "";
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
