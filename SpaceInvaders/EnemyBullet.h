#pragma once
#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include "Projectile.h"
class EnemyBullet :
	public Projectile
{
public:
	EnemyBullet(unsigned int posx, unsigned int posy, int speedX, int speedY, unsigned int frameTime, unsigned int ID);
	~EnemyBullet();
};
#endif

