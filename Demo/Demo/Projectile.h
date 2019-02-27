#ifndef DEMO_PROJECTILE_H
#define DEMO_PROJECTILE_H

#include "Component.h"

class Projectile : public Component {
private:
    int type;

protected:

public:
    Projectile(int posx, int posy, int speed) : Component(posx, posy, 0, speed, '|') {

    }

    void draw(Engine &screen) {
        screen.setPixel(posx, posy, texture);
        if(posy)
            posy = posy + speed;

    }

    int getposY() {
        return posy;
    }
};

#endif

