#include "Laser.h"



Laser::Laser() : Weapon("./ressources/laser.png", LASERSCALE, 0, -20, 10, ALLYLASER) {
    Projectile* load = new Projectile(picturePath, LASERSCALE, 0, 0, speedX, speedY, frametime, 0, ID);
    this->height = load->boundingRect().height() * LASERSCALE;
    this->width = load->boundingRect().width() * LASERSCALE;
    delete load;
}

QList<Projectile*>*  Laser::shoot(unsigned int posx, unsigned int posy) {
    Projectile* p = new AllyLaser(posx - width/2, posy - height, speedX, speedY, frametime);
    QList<Projectile*>* list = new QList<Projectile*>();
    list->push_back(p);
    return list;
}


Laser::~Laser() {

}
