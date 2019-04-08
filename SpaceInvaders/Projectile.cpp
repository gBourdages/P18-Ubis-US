#include "Projectile.h"



Projectile::Projectile(const char *picturePath, float s, unsigned int posx, unsigned int posy, int speedX, int speedY, unsigned int frameTime) : Sprites(picturePath, s, posx, posy) {
    this->speedX = speedX;
    this->speedY = speedY;
    time = new QTimer();
    connect(time, SIGNAL(timeout()), this, SLOT(animate()));
    time->start(frameTime);
}

void Projectile::animate() {
    move(speedX, speedY);
}

Projectile::~Projectile() {

}
