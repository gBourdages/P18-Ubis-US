#ifndef DEMO_COMPONENT_H
#define DEMO_COMPONENT_H

#include "Engine.h"

class Component {
protected:
    int posx;
    int posy;
    int hp;
    int speed;
    WORD color;

    char texture;

public:
    Component(int posx, int posy, int hp, int speed, char texture) {
        this->posx = posx;
        this->posy = posy;
        this->hp = hp;
        this->speed = speed;
        this->texture = texture;
        color = NULL;
    }

    virtual void draw(Engine &screen) {
        if (color == NULL)
            screen.setPixel(posx, posy, texture);
        else
            screen.setPixel(posx, posy, texture, color);
        
    }

    void setTexture(char texture) {
        this->texture = texture;
    }

    void setColor(WORD c) {
        color = c;
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