#ifndef DEMO_BLOC_H
#define DEMO_BLOC_H

#include "Component.h"

#define BLOCHP 1

class Bloc : public Component {
private:
public:
    Bloc(int posx, int posy) : Component(posx, posy, BLOCHP, '#') {

    }


};

#endif