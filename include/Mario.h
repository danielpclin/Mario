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
    protected:
        bool falling;
        int jump;
    private:
        void getKeypress();
};

#endif // MARIO_H
