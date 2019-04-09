#include "AllyBullet.h"



AllyBullet::AllyBullet(unsigned int posx, unsigned int posy, int speedX, int speedY, unsigned int frameTime) : Projectile("./ressources/bullet.png", 0.25, posx, posy, speedX, speedY, frameTime, 0, ALLYBULLET) {

}

void AllyBullet::collided(unsigned int ID) {
    switch (ID) {
    case ENEMYBULLET:
        emit deleteThis(this);
        break;
    case MINION:
        emit deleteThis(this);
        break;
    }
}


AllyBullet::~AllyBullet() {

}
