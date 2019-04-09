#include "Default.h"

Default::Default() : Weapon("./ressources/bullet.png", 0.1, 0, -10, 10, ALLYBULLET) {

}

QList<Projectile*>*  Default::shoot(unsigned int posx, unsigned int posy) {
    Projectile* p = new AllyBullet(posx, posy - height, speedX, speedY, frametime);
    QList<Projectile*>* list = new QList<Projectile*>();
    list->push_back(p);
    return list;
}

Default::~Default() {

}
