#ifndef MARIO_H
#define MARIO_H
#include "Sprite.h"

class Mario : public Sprite
{
    public:
        Mario(int lengthX, int lengthY, int posX, int posY);
        ~Mario();
        virtual void update(Level *level) override;
        bool isFalling();
        int getJump();
        void setJump(int jump);
        virtual bool isPossibleMovement(int posX, int posY, Level *level) override;
        void getKeypress();
        int invincible;
        bool outOfBounds(int posX, int posY, Level *level);
    protected:
        bool falling;
        int jump;
    private:
};

#endif // MARIO_H
