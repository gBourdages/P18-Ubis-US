#ifndef DEMO_HOUSE_H
#define DEMO_HOUSE_H

#include <list>
#include "Bloc.h"

class House : public Component {
private:

    std::list<Bloc> list;

public:
    House(int posx, int posy, std::list<Component> &list) : Component(posx, posy, 0, 0, '#') {

        list.push_back(Bloc(3 + posx, 0 + posy));
        list.push_back(Bloc(2 + posx, 1 + posy));
        list.push_back(Bloc(3 + posx, 1 + posy));
        list.push_back(Bloc(4 + posx, 1 + posy));
        list.push_back(Bloc(1 + posx, 2 + posy));
        list.push_back(Bloc(3 + posx, 2 + posy));
        list.push_back(Bloc(5 + posx, 2 + posy));
        list.push_back(Bloc(0 + posx, 3 + posy));
        list.push_back(Bloc(1 + posx, 3 + posy));
        list.push_back(Bloc(2 + posx, 3 + posy));
        list.push_back(Bloc(3 + posx, 3 + posy));
        list.push_back(Bloc(4 + posx, 3 + posy));
        list.push_back(Bloc(5 + posx, 3 + posy));
        list.push_back(Bloc(6 + posx, 3 + posy));
        list.push_back(Bloc(1 + posx, 4 + posy));
        list.push_back(Bloc(2 + posx, 4 + posy));
        list.push_back(Bloc(3 + posx, 4 + posy));
        list.push_back(Bloc(4 + posx, 4 + posy));
        list.push_back(Bloc(5 + posx, 4 + posy));
    }

    void draw(Engine &screen) {
        std::list<Bloc>::iterator it = list.begin();
        while (it != list.end()) {
            (*it).draw(screen);
            it++;
        }
    }

};

#endif