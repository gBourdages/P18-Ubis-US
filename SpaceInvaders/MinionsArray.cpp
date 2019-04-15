#include "MinionsArray.h"



MinionsArray::MinionsArray() {
    array = new QList<Minion*>();
    for (int x = 1; x <= 13; ++x) {
        for (int y = 1; y <= 3; ++y) {
            array->push_back(new Minion(x * (1900/13) - 130 , 125 * y - 50));
        }
    }
    this->direction = 1;
    time = new QTimer();
    connect(time, SIGNAL(timeout()), this, SLOT(move()));
    time->start(1500);

    shooting = new QTimer();
    connect(shooting, SIGNAL(timeout()), this, SLOT(shoot()));
    shooting->start(800);
    srand(std::time(0));
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

void MinionsArray::shoot() {
    int random;
    if (array->size() && array->size() - 1) {
        random = rand() % (array->size() - 1);
        addSprites(dynamic_cast<Sprites*>(array->at(random)->shoot()));
    }
    /*
    int i = 0;
    for (QList<Minion*>::iterator it = array->begin(); it != array->end(); ++it) {
        if (i == random) {
            addSprites(dynamic_cast<Sprites*>((*it)->shoot()));    
        }
        i++;
    }
    */
}