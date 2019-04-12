#include "Ship.h"



Ship::Ship(unsigned int posx, unsigned int posy) : Sprites("./ressources/AlexShip.png", 0.25, posx, posy, 0, PLAYER) {
    weapons[0] = new Default();
    weapons[1] = new Laser();
    QSize size = QPixmap("./ressources/shield.png").size();
    pixmap[2] = QPixmap("./ressources/shield.png").scaled(size.width()*scale, size.height()*scale);
    this->life = 5;
    this->shield = 0;
    this->selectedWeapon = 0;
    this->width = boundingRect().width() * 0.25;
    this->canShot = true;
    time = new QTimer();
    connect(time, SIGNAL(timeout()), this, SLOT(canShoot()));
    time->start(250);

    timeLaser = new QTimer();
    connect(timeLaser, SIGNAL(timeout()), this, SLOT(defaultWeapon()));
}


Ship::~Ship() {

}

void Ship::canShoot() {
    this->canShot = true;
}

void Ship::move(int mx) {
    if((0 < x() + mx) && (1918 - boundingRect().width()/4 > x() + mx))
        setPos(x() + mx, y());
}

QList<Projectile*>* Ship::shoot() {
    if (canShot) {
        canShot = false;
        return weapons[selectedWeapon]->shoot(x() + width / 2, y());
    }
    return nullptr;
    
}

void Ship::collided(unsigned int ID) {
    switch (ID) {
        case ENEMYBULLET :
            if (shield) {
                shield -= 1;
                if(!shield)
                    setPixmap(pixmap[1]);
            }
                
            else
                life -= 1;
            break;
        case POWERUPSHIELD :
            shield += 5;
            setPixmap(pixmap[2]);
            break;
        case POWERUPLASER:
            selectedWeapon = 1;
            timeLaser->start(5000);
            break;
        
    }
}

void Ship::defaultWeapon() {
    selectedWeapon = 0;
}


