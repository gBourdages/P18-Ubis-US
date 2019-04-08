#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsPixmapItem>
#include "Sprites.h"

class Ship : public Sprites {
Q_OBJECT

public:
    Ship(unsigned int posx, unsigned int posy);
    ~Ship();

public slots:
};

#endif