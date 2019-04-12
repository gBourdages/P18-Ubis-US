#ifndef MINIONSARRAY_H
#define MINIONSARRAY_H
#define MOUVEMENT 70
#include "Minion.h"
#include <QList>
#include <ctime>
#include <cstdlib>

class MinionsArray : public QObject {
Q_OBJECT
private:
    QList<Minion*>* array;

public:
    MinionsArray();
    ~MinionsArray();
    QList<Minion*>* getArray();
    QTimer* time;
    QTimer* shooting;
    unsigned int direction;
    
public slots:
    void move();
    void removeMinion(Sprites* s);
    void shoot();

signals:
    void addSprites(Sprites* s);
};

#endif