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
    void collided();
    
public slots:
    void animate();
    void collide();
};

#endif

