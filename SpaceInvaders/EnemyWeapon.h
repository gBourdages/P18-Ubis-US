#ifndef ENEMYWEAPON_H
#define ENEMYWEAPON_H
#include "Weapon.h"
#include "EnemyBullet.h"
class EnemyWeapon : public Weapon {
public:
    EnemyWeapon();
    ~EnemyWeapon();
    QList<Projectile*>* shoot(unsigned int posx, unsigned int posy);
};

#endif

