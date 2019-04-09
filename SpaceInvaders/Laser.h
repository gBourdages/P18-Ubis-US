#ifndef LASER_H
#define LASER_H
#include "Weapon.h"
#include "AllyLaser.h"
class Laser : public Weapon {
public:
    Laser();
    ~Laser();
    QList<Projectile*>* shoot(unsigned int posx, unsigned int posy);
};

#endif