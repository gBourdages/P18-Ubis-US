#include "AllyLaser.h"



AllyLaser::AllyLaser(unsigned int posx, unsigned int posy, int speedX, int speedY, unsigned int frameTime) : Projectile("./ressources/laser.png", 1, posx, posy, speedX, speedY, frameTime, 0, ALLYLASER) {

}

void AllyLaser::collided(unsigned int ID) {

}

AllyLaser::~AllyLaser()
{
}
