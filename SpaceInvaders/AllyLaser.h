#ifndef ALLYLASER_H
#define ALLYLASER_H

#include "Projectile.h"
class AllyLaser : public Projectile {
public:
	AllyLaser(unsigned int posx, unsigned int posy, int speedX, int speedY, unsigned int frameTime);
	~AllyLaser();
    void collided(unsigned int ID);
};

#endif

