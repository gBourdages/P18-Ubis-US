#ifndef MINIONSARRAY_H
#define MINIONSARRAY_H
#include "Minion.h"
#include <QList>

class MinionsArray {
private:
    QList<Minion*>* array;

public:
    MinionsArray();
    ~MinionsArray();
    QList<Minion*>* getArray();
    void move(int mx);
};

#endif