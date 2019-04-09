#ifndef WEAPON_H
#define WEAPON_H
#include "Projectile.h"

#define BURST = 1;
#define AUTO = 2;
#define TRIPLE = 3;

class Weapon {
protected:
    int speedX;
    int speedY;
    float scale;
    unsigned int frametime;
    unsigned int ID;
    unsigned int mode;
    const char *picturePath;
    unsigned int height;

public:
    Weapon(const char *picturePath, float s, int speedX, int speedY, unsigned int frameTime, unsigned int ID);
    ~Weapon();
    virtual QList<Projectile*>* shoot(unsigned int posx, unsigned int posy);
    void setMode(unsigned int m);

};

#endif

