#include "Sprites.h"
#include <iostream>
#include <QDebug>



Sprites::Sprites(const char *picturePath, float s, unsigned int posx, unsigned int posy, int rot, unsigned int ID) {
    pixmap[1] = QPixmap(picturePath);
    setPixmap(pixmap[1]);
    setScale(s);
    setRotation(rot);
    setPos(posx, posy);
    this->ID = ID;
}

Sprites::~Sprites() {

}

void Sprites::move(int mx, int my) {
    setPos(x() + mx, y() + my);
    if (x() < -100 || x() > 2020 || y() < -100 || y() > 1200)
        emit this->deleteThis(this);


}
