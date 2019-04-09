#include "MinionsArray.h"



MinionsArray::MinionsArray() {
    array = new QList<Minion*>();
    for (int x = 0; x < 10; x+=1) {
        for (int y = 0; y < 3; y+=1) {
            array->push_back(new Minion(x * 100 * MINIONSCALE+ 1980/10 , y * 100 * MINIONSCALE +1080/3));
        }
    }
}


MinionsArray::~MinionsArray() {

}

QList<Minion*>* MinionsArray::getArray() {
    return array;
}

void MinionsArray::move(int mx) {
    for (QList<Minion*>::iterator it = array->begin(); it != array->end(); ++it) {
        (*it)->move(mx);
    }
}