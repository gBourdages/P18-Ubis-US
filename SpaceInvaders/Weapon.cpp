#include "Weapon.h"



Weapon::Weapon(const char *picturePath, float s, int speedX, int speedY, unsigned int frameTime, unsigned int ID) {
    this->picturePath = picturePath;
    this->scale = s;
    this->speedX = speedX;
    this->speedY = speedY;
    this->frametime = frameTime;
    this->ID = ID;
    Projectile* loadHeight = new Projectile(picturePath, scale, 0, 0, speedX, speedY, frametime, ID);
    this->height = loadHeight->boundingRect().height() * scale;
    delete loadHeight;
}


Weapon::~Weapon() {

}

Projectile*  Weapon::shoot(unsigned int posx, unsigned int posy) {
    return new Projectile(picturePath, scale, posx, posy - height, speedX, speedY, frametime, ID);

}

