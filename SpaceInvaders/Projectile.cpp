#include "Projectile.h"
#include <QDebug>
#include <QTime>



Projectile::Projectile(const char *picturePath, float s, unsigned int posx, unsigned int posy, int speedX, int speedY, unsigned int frameTime, unsigned int rot, unsigned int ID) : Sprites(picturePath, s, posx, posy, rot, ID) {
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
    QTime time = QTime::currentTime();
    QList<QGraphicsItem*> list = collidingItems(Qt::IntersectsItemBoundingRect);
    qDebug() << time.elapsed();
    if (list.size()) {
        unsigned int id;
        for (QList<QGraphicsItem*>::iterator it = list.begin(); it != list.end(); ++it) {
            Sprites* s = dynamic_cast<Sprites*>(*it);
            id = s->getID();
            s->collided(this->ID);
        }
        this->collided(id);
    }
}


Projectile::~Projectile() {
    delete time;
}
