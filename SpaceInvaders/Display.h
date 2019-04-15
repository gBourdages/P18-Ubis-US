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
    quint64 score;

public:
    Display();
    ~Display();
    

public slots:
    void removeSprites(Sprites* s);
    void addSprite(Sprites *s);
    void scorePlus();

signals:
    void pause();
};

#endif

