#include "EnemyBullet.h"



EnemyBullet::EnemyBullet(unsigned int posx, unsigned int posy, int speedX, int speedY, unsigned int frameTime, unsigned int ID) : Projectile("Spaceinvaders/ressources/enemyBullet.png", 0.25, posx, posy, speedX, speedY, frameTime, 0, ID)
{
}


EnemyBullet::~EnemyBullet()
{
}
