#ifndef GAME_H
#define GAME_H
#include <vector>
#include <string>

class Level;

class Game
{
    public:
        Game();
        virtual ~Game();
        int currentLevel;
        std::vector<Level *> levelVector;
        void clear();
        void draw();
        void update();
        void load(std::string backgroundStr, std::string spriteStr);
        void load(std::string backgroundStr, std::string spriteStr,int levelID);
        bool isOver();
    protected:

    private:
};

#endif // GAME_H
