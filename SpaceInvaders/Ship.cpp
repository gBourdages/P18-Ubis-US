#include "Ship.h"



Ship::Ship(unsigned int posx, unsigned int posy) : Sprites("./ressources/AlexShip.png", 0.25, posx, posy, 0, PLAYER) {
    weapons[0] = new Default();
    weapons[1] = new Laser();
    this->life = 5;
    this->shield = 0;
    this->selectedWeapon = 1;
}


Ship::~Ship() {

}

void Ship::move(int mx) {
    if((0 < x() + mx) && (1918 - boundingRect().width()/4 > x() + mx))
        setPos(x() + mx, y());
}

QList<Projectile*>* Ship::shoot() {
    return weapons[selectedWeapon]->shoot(x(), y());
}

void Ship::collided(unsigned int ID) {
    switch (ID) {
        case ENEMYBULLET :
            if (shield)
                shield -= 1;
            else
                life -= 1;
            break;
        case POWERUP :
            shield += 5;
    }
}


