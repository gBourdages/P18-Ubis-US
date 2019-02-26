#ifndef DEMO_GAME_H
#define DEMO_GAME_H

#include <list>

#include "House.h"
#include "Display.h"

class Game {
private:
    std::list<Component> componentList;
    Display screen;

public:
    Game() {
        House house1();
    }


};

#endif