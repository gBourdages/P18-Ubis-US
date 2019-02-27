#ifndef DEMO_PROJECTILE_H
#define DEMO_PROJECTILE_H

#include "Component.h"

class Projectile : public Component {
private:
    int type;

protected:

public:
    Projectile(int posx, int posy) : Component(posx, posy, 0, '|') {

    }

    void draw(Engine &screen) {
        screen.setPixel(posx, posy, texture);
        if(posy)
            posy -= 1;
    }

    int getposY() {
        return posy;
    }
};

#endif

