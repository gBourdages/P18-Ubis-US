#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Sprites.h"

class Projectile : public Sprites {
Q_OBJECT
protected:
    int speedX;
    int speedY;
    QTimer* time;

public:
    Projectile(const char *picturePath, float s, unsigned int posx, unsigned int posy, int speedX, int speedY, unsigned int frameTime);
    ~Projectile();
    
public slots:
    void animate();
};

#endif

