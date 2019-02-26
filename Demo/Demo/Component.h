#ifndef DEMO_COMPONENT_H
#define DEMO_COMPONENT_H

#include "Engine.h"

class Component {
protected:
    int posx;
    int posy;
    int hp;

    char texture;

public:
    Component(int posx, int posy, int hp, char texture) {
        this->posx = posx;
        this->posy = posy;
        this->hp = hp;
        this->texture = texture;
    }

    virtual void draw(Engine &screen) {
        screen.setPixel(posx, posy, texture);
    }

    void move(int x, int y) {
        posx += x;
        posy += y;
    }
};

#endif