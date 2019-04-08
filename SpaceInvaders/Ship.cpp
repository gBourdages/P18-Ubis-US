#include "Ship.h"



Ship::Ship(unsigned int posx, unsigned int posy) : Sprites("./ressources/AlexShip.png", 0.25, posx, posy) {
    one = new Weapon("./ressources/bullet.png", 0.1, 0, -1, 3);
}


Ship::~Ship() {

}

void Ship::move(int mx) {
    if((0 < x() + mx) && (1918 - boundingRect().width()/4 > x() + mx))
        setPos(x() + mx, y());
}

Projectile* Ship::shoot() {
    return one->shoot(x(), y());
}


