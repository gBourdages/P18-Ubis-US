#ifndef DEFAULT_H
#define DEFAULT_H
#include "Weapon.h"
#include "AllyBullet.h"

class Default : public Weapon {
public:
    Default();
    ~Default();
    QList<Projectile*>* shoot(unsigned int posx, unsigned int posy);
};

#endif

