#include "MinionsArray.h"



MinionsArray::MinionsArray() {
    array = new QList<Minion*>();
    for (int x = 0; x < 10; x+=1) {
        for (int y = 0; y < 3; y+=1) {
            array->push_back(new Minion(x * 100 * MINIONSCALE+ 1980/10 , y * 100 * MINIONSCALE +1080/3));
        }
    }
    this->direction = 1;
    time = new QTimer();
    connect(time, SIGNAL(timeout()), this, SLOT(move()));
    time->start(1500);
}


MinionsArray::~MinionsArray() {

}

QList<Minion*>* MinionsArray::getArray() {
    return array;
}

void MinionsArray::move() {
    for (QList<Minion*>::iterator it = array->begin(); it != array->end(); ++it) {
        if((*it))
            (*it)->move(direction * MOUVEMENT);
    }
    this->direction *= -1;
}

void MinionsArray::removeMinion(Sprites* s) {
    Minion* m = dynamic_cast<Minion*>(s);
    this->array->removeOne(m);
}