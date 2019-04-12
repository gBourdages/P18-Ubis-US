#ifndef DEMO_PLAYER_H
#define DEMO_PLAYER_H

#include <list>
#include "Component.h"
#include "Projectile.h"
#include "Game.h"

class Player : public Component {
private:
    std::list<Projectile> list;
    bool boxOn;
protected:

public:

    Player(int posx, int posy) : Component(posx, posy, 20, 0, 'A') {
        boxOn = false;
    }

    void box() {
        if (boxOn)
            boxOn = false;
        else
            boxOn = true;
    }

    void shoot() {
        list.push_back(Projectile(posx, posy - 1, -1));
    }

    bool checkCollision(Game &g) {
        std::list<Projectile>::iterator it = list.begin();
        while (it != list.end()) {
            if (g.checkCollisions(*it)) {
                it = list.erase(it);
            }
            else
                it++;
        }
        return false;
    }

    void draw(Engine &screen) {
        std::list<Projectile>::iterator it = list.begin();
        while (it != list.end()) {
            (*it).draw(screen);
            if ((*it).getposY() < 1)
                it = list.erase(it);
            else
                it++;
        }
        screen.setPixel(posx, posy, texture);
        if (boxOn) {
            screen.setPixel(posx, posy -1, '_', FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            screen.setPixel(posx + 1, posy -1, '_', FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            screen.setPixel(posx - 1, posy -1, '_', FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            screen.setPixel(posx - 1, posy, '|', FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            screen.setPixel(posx + 1, posy, '|', FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        }
    }

};

#endif
