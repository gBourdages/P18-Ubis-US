#ifndef DEMO_PLAYER_H
#define DEMO_PLAYER_H

#include <list>
#include "Component.h"
#include "Projectile.h"

class Player : public Component {
private:
    std::list<Projectile> list;
    bool popit;
protected:

public:

    Player(int posx, int posy) : Component(posx, posy, 20, 'A') {
        popit = false;
    }

    void shoot() {
        list.push_back(Projectile(posx, posy - 1));
    }

    void draw(Engine &screen) {
        std::list<Projectile>::iterator it = list.begin();
        while (it != list.end()) {
            (*it).draw(screen);
            if ((*it).getposY() < 1)
                popit = true;
            it++;
        }

        if (popit) {
            list.pop_front();
            popit = false;
        }

        screen.setPixel(posx, posy, texture);
    }

};

#endif
