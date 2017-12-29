#ifndef GOOMBA_H
#define GOOMBA_H
#include "Sprite.h"

class Goomba : public Sprite
{
    public:
        Goomba(int lengthX, int lengthY, int posX, int posY);
        virtual ~Goomba();
        void update(Level *level) override;
    protected:

    private:
        void reverseSpeed();
        int counter;
};

#endif // GOOMBA_H
