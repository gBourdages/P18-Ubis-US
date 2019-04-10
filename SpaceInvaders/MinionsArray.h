#ifndef MINIONSARRAY_H
#define MINIONSARRAY_H
#define MOUVEMENT 30
#include "Minion.h"
#include <QList>

class MinionsArray : public QObject {
Q_OBJECT
private:
    QList<Minion*>* array;

public:
    MinionsArray();
    ~MinionsArray();
    QList<Minion*>* getArray();
    QTimer* time;
    unsigned int direction;
    
public slots:
    void move();
    void removeMinion(Sprites* s);
};

#endif