#include "PowerUp.h"



PowerUp::PowerUp(unsigned int type, unsigned int posx, unsigned int posy) : Projectile("./ressources/pod.png", 1, posx, posy, 0, 1, 10, 0, type) {

}


PowerUp::~PowerUp() {

}

void PowerUp::collided(unsigned int id) {
    switch (id) {
    case PLAYER:
        emit this->deleteThis(this);
        break;
    }
}
