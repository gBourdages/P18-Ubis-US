#include "AllyBullet.h"



AllyBullet::AllyBullet(unsigned int posx, unsigned int posy, int speedX, int speedY, unsigned int frameTime) : Projectile("./ressources/bullet.png", BULLETSCALE, posx, posy, speedX, speedY, frameTime, 0, ALLYBULLET) {

}

void AllyBullet::collided(unsigned int id) {
    switch (id) {
    case ENEMYBULLET:
        emit this->deleteThis(this);
        break;
    case MINION:
        emit this->deleteThis(this);
        break;
    case BLOCK:
        emit this->deleteThis(this);
        break;
    }
}


AllyBullet::~AllyBullet() {

}
