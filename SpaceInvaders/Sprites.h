#ifndef SPRITES_H
#define SPRITES_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QMap>
#include <QTimer>

class Sprites : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
protected:
    QMap<int, QPixmap> pixmap;


public:
    Sprites(const char *picturePath, float s, unsigned int posx, unsigned int posy);
    ~Sprites();
    void move(int mx, int my);
    virtual void collided() {}

public slots:
};

#endif