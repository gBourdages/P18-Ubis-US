#include "Projectile.h"
#include <QDebug>



Projectile::Projectile(const char *picturePath, float s, unsigned int posx, unsigned int posy, int speedX, int speedY, unsigned int frameTime, unsigned int ID) : Sprites(picturePath, s, posx, posy,50, ID) {
    this->speedX = speedX;
    this->speedY = speedY;
    time = new QTimer();
    connect(time, SIGNAL(timeout()), this, SLOT(animate()));
    connect(time, SIGNAL(timeout()), this, SLOT(collide()));
    time->start(frameTime);
}

void Projectile::animate() {
    move(speedX, speedY);
}

void Projectile::collide() {
    QList<QGraphicsItem*> list = collidingItems();
    if (list.size()) {
        for (QList<QGraphicsItem*>::iterator it = list.begin(); it != list.end(); ++it) {
            Sprites* s = dynamic_cast<Sprites*>(*it);
            s->collided(ID);
            this->collided(ID);
        }
    }


}

void Projectile::collided(unsigned int ID) {
    
}

Projectile::~Projectile() {
    delete time;
}
