#include "Minion.h"



Minion::Minion(unsigned int posx, unsigned int posy) : Sprites("./ressources/enemy.png", MINIONSCALE, posx, posy, 0, MINION) {
    this->life = 2;
    this->width = boundingRect().width() * 0.25;
    weapon = new EnemyWeapon();
}


Minion::~Minion() {
}

void Minion::move(int mx) {
    if ((0 < x() + mx) && (1918 - boundingRect().width() / 4 > x() + mx))
        setPos(x() + mx, y());
}

Projectile* Minion::shoot() {

        return weapon->shoot(x() + width / 2, y());

}

void Minion::collided(unsigned int id) {
    switch (id) {
    case ALLYBULLET:
        this->life -= 1;
        if (!life)
            emit this->deleteThis(this);
        break;
    case ALLYLASER:
        this->life -= 1;
        if (!life)
            emit this->deleteThis(this);
        break;
    }
}