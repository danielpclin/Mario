#ifndef FLAG_H
#define FLAG_H

#include <Sprite.h>


class Flag : public Sprite
{
    public:
        Flag(int lengthX, int lengthY, int posX, int posY);
        virtual ~Flag();
        void update(Level *level) override;
    protected:

    private:
};

#endif // FLAG_H
