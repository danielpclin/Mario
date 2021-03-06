#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <vector>
#include <windows.h>
#include <string>

class Level;

class Background
{
    public:
        Background();
        Background(std::vector<std::string>);
        ~Background();

        std::vector<std::string> getCharMap();
        void setCoord(COORD);
        void setCharMap(std::vector<std::string>);
        COORD getCoord();
        void update(Level *level);
    protected:

    private:
        std::vector<std::string> charMap;
        COORD backgroundCoord;
};

#endif // BACKGROUND_H
