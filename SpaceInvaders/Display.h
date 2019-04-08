#ifndef DISPLAY_H
#define DISPLAY_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVBoxLayout>
#include "Sprites.h"

class Display : public QGraphicsView {
Q_OBJECT
protected:

    QGraphicsScene* scene;

public:
    Display();
    ~Display();
    void addSprite(Sprites *s);

public slots:
    void removeSprites(Sprites* s);
};

#endif

