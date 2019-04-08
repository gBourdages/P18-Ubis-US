#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsPixmapItem>
#include "Sprites.h"
#include "Weapon.h"


class Ship : public Sprites {
Q_OBJECT
private:
    Weapon* one;
public:
    Ship(unsigned int posx, unsigned int posy);
    ~Ship();
    void move(int mx);
    Projectile* shoot();

public slots:
};

#endif