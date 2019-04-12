#include "EnemyWeapon.h"



EnemyWeapon::EnemyWeapon() : Weapon("./ressources/poop.png", BULLETSCALE, 0, 1, 10, ENEMYBULLET) {
    Projectile* load = new Projectile(picturePath, BULLETSCALE, 0, 0, speedX, speedY, frametime, 0, ID);
    this->height = load->boundingRect().height();
    this->width = load->boundingRect().width();
    delete load;
}

QList<Projectile*>*  EnemyWeapon::shoot(unsigned int posx, unsigned int posy) {
    Projectile* p = new EnemyBullet(posx - width / 2, posy + height , speedX, speedY, frametime);
    QList<Projectile*>* list = new QList<Projectile*>();
    list->push_back(p);
    return list;
}


EnemyWeapon::~EnemyWeapon() {

}
