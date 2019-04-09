#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsPixmapItem>
#include "Sprites.h"
#include "Default.h"
#include "Laser.h"


class Ship : public Sprites {
Q_OBJECT
private:
    Weapon* weapons[3];
    unsigned int selectedWeapon;
    unsigned int shield;
    unsigned int life;

public:
    Ship(unsigned int posx, unsigned int posy);
    ~Ship();
    void move(int mx);
    QList<Projectile*>* shoot();
    void collided(unsigned int ID);

public slots:
};

#endif