#ifndef ALLYBULLET_H
#define ALLYBULLET_H
#define BULLETSCALE 0.05

#include "Projectile.h"
class AllyBullet :
	public Projectile
{
public:
	AllyBullet(unsigned int posx, unsigned int posy, int speedX, int speedY, unsigned int frameTime);
	~AllyBullet();
    void collided(unsigned int ID);

};

#endif