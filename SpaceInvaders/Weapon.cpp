#include "Weapon.h"



Weapon::Weapon(const char *picturePath, float s, int speedX, int speedY, unsigned int frameTime, unsigned int ID) {
    this->picturePath = picturePath;
    this->scale = s;
    this->speedX = speedX;
    this->speedY = speedY;
    this->frametime = frameTime;
    this->ID = ID;
    this->mode = 1;
    
    
}

Weapon::~Weapon() {

}

QList<Projectile*>*  Weapon::shoot(unsigned int posx, unsigned int posy) {
    Projectile* p = new Projectile(picturePath, scale, posx, posy - height, speedX, speedY, frametime, 0, ID);
    QList<Projectile*>* list = new QList<Projectile*>();
    list->push_back(p);
    return list;
}

void Weapon::setMode(unsigned int m) {
    this->mode = m;
}

