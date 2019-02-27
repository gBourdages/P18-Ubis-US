#ifndef DEMO_COMPONENT_H
#define DEMO_COMPONENT_H

#include "Engine.h"

class Component {
protected:
    int posx;
    int posy;
    int hp;
    int speed;

    char texture;

public:
    Component(int posx, int posy, int hp, int speed, char texture) {
        this->posx = posx;
        this->posy = posy;
        this->hp = hp;
        this->speed = speed;
        this->texture = texture;
    }

    virtual void draw(Engine &screen) {
        screen.setPixel(posx, posy, texture);
    }

    void move(int x, int y) {
        posx += x;
        posy += y;
    }

    bool checkCollision(Component c) {
        if (c.posx != posx)
            return false;
        if (c.posy == (posy + speed))
            return true;
        return false;
    }


};

#endif