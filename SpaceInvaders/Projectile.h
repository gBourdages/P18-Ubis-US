#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Sprites.h"

class Projectile : public Sprites {
Q_OBJECT
protected:
    int speedX;
    int speedY;
    QTimer* time;
    bool pauseState;
    unsigned int frameTime;

public:
    Projectile(const char *picturePath, float s, unsigned int posx, unsigned int posy, int speedX, int speedY, unsigned int frameTime,unsigned int rot, unsigned int ID);
    ~Projectile();
    virtual void collided(unsigned int ID) {};
    
public slots:
    void animate();
    void collide();
    void pause();
};

#endif

