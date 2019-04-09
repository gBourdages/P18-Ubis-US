#pragma once
#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#define BULLETSCALE 0.05
#include "Projectile.h"
class EnemyBullet : public Projectile {
public:
	EnemyBullet(unsigned int posx, unsigned int posy, int speedX, int speedY, unsigned int frameTime);
	~EnemyBullet();
    void collided(unsigned int ID);
};
#endif

