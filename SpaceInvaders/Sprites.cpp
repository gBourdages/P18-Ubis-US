#include "Sprites.h"
#include <iostream>
#include <QDebug>



Sprites::Sprites(const char *picturePath, float s, unsigned int posx, unsigned int posy) {
    pixmap[1] = QPixmap(picturePath);
    setPixmap(pixmap[1]);
    setScale(s);
    setPos(posx, posy);
}

Sprites::~Sprites() {

}

void Sprites::move(int mx, int my) {
    setPos(x() + mx, y() + my);
    if (x() < -100 || x() > 2020 || y() < -100 || y() > 1200)
        emit this->deleteThis(this);


}
