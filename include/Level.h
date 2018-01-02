#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include <string>

class Sprite;
class Background;
class Mario;

class Level
{
    public:
        Level(std::string backgroundStr, std::string spriteStr);
        virtual ~Level();
        Background *background;
        Mario *mario;
        std::vector<Sprite *> spriteVector;
        static int lives;
        bool finished;
        bool dead;
    protected:

    private:

};

#endif // LEVEL_H
