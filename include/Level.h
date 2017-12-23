#ifndef LEVEL_H
#define LEVEL_H
#include "Background.h"
#include <vector>
#include "Sprite.h"

class Sprite;
class Background;

class Level
{
    public:
        Level();
        virtual ~Level();
        Background *background;
        std::vector<Sprite *> spriteVector;
    protected:

    private:
};

#endif // LEVEL_H
