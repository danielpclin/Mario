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
        void draw();
        void update();
        void load(std::string str);
    protected:

    private:
};

#endif // GAME_H
