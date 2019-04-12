#ifndef POWERUP_H
#define POWERUP_H
#include "Projectile.h"

class PowerUp : public Projectile {
public:
    PowerUp(unsigned int type, unsigned int posx, unsigned int posy);
    ~PowerUp();
    void collided(unsigned int id);
};

#endif

