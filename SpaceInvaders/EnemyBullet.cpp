#include "EnemyBullet.h"



EnemyBullet::EnemyBullet(unsigned int posx, unsigned int posy, int speedX, int speedY, unsigned int frameTime) : Projectile("./ressources/poop.png", BULLETSCALE, posx, posy, speedX, speedY, frameTime, 180, ENEMYBULLET) {

}

void EnemyBullet::collided(unsigned int id) {
    switch (id) {
    case ALLYBULLET:
        emit this->deleteThis(this);
        break;
    case MINION:
        emit this->deleteThis(this);
        break;
    case BLOCK:
        emit this->deleteThis(this);
        break;
    case PLAYER:
        emit this->deleteThis(this);
        break;
    }
}

EnemyBullet::~EnemyBullet() {

}
