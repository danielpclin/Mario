#ifndef MARIO_H
#define MARIO_H

#include <Sprite.h>


class Mario : public Sprite
{
    public:
        Mario(int lengthX, int lengthY, int posX, int posY);
        ~Mario();
        void update();
        bool isFalling();
        int getJump();
        void setJump(int jump);
    protected:
        bool falling;
        int jump;
    private:
};

#endif // MARIO_H
