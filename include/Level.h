#ifndef LEVEL_H
#define LEVEL_H
#include <vector>

class Sprite;
class Background;
class Mario;

class Level
{
    public:
        Level();
        virtual ~Level();
        Background *background;
        Mario *mario;
        std::vector<Sprite *> spriteVector;
    protected:

    private:
};

#endif // LEVEL_H
