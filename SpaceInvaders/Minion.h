#ifndef MINION_H
#define MINION_H
#define MINIONSCALE 1
#define MINIONOFFSET 
#include "Sprites.h"
#include "EnemyWeapon.h"
class Minion : public Sprites {
private:
    Weapon* weapon;
    unsigned int life;
    unsigned int width;
public:
    Minion(unsigned int posx, unsigned int posy);
    ~Minion();
    void move(int mx);
    Projectile* shoot();
    void collided(unsigned int ID);
};

#endif

