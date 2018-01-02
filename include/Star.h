#ifndef STAR_H
#define STAR_H

#include <Sprite.h>


class Star : public Sprite
{
    public:
        Star(int lengthX, int lengthY, int posX, int posY);
        virtual ~Star();
        void update(Level *level) override;

    protected:

    private:
};

#endif // STAR_H
