#include "Default.h"

Default::Default() : Weapon("./ressources/bullet.png", BULLETSCALE, 0, -10, 10, ALLYBULLET) {
    Projectile* load = new Projectile(picturePath, BULLETSCALE, 0, 0, speedX, speedY, frametime, 0, ID);
    this->height = load->boundingRect().height() * BULLETSCALE;
    this->width = load->boundingRect().width() * BULLETSCALE;
    delete load;
}

QList<Projectile*>*  Default::shoot(unsigned int posx, unsigned int posy) {
    Projectile* p = new AllyBullet(posx - width / 2, posy - height, speedX, speedY, frametime);
    QList<Projectile*>* list = new QList<Projectile*>();
    list->push_back(p);
    return list;
}

Default::~Default() {

}
