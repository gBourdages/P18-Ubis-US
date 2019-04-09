#include "Laser.h"



Laser::Laser() : Weapon("./ressources/laser.png", 0.01, 0, -50, 10, ALLYLASER) {
    Projectile* loadHeight = new Projectile(picturePath, 0.01, 0, 0, speedX, speedY, frametime, 0, ID);
    this->height = loadHeight->boundingRect().height() * scale;
    delete loadHeight;
}

QList<Projectile*>*  Laser::shoot(unsigned int posx, unsigned int posy) {
    Projectile* p = new AllyLaser(posx, posy - height, speedX, speedY, frametime);
    QList<Projectile*>* list = new QList<Projectile*>();
    list->push_back(p);
    return list;
}


Laser::~Laser() {

}
