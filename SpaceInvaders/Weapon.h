#ifndef WEAPON_H
#define WEAPON_H
#include "Projectile.h"

class Weapon {
protected:
    int speedX;
    int speedY;
    float scale;
    unsigned int frametime;
    unsigned int ID;
    const char *picturePath;
    unsigned int height;

public:
    Weapon(const char *picturePath, float s, int speedX, int speedY, unsigned int frameTime, unsigned int ID);
    ~Weapon();
    Projectile* shoot(unsigned int posx, unsigned int posy);

};

#endif

