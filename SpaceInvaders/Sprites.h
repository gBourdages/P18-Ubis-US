#ifndef SPRITES_H
#define SPRITES_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QMap>
#include <QTimer>
#define PLAYER 1
#define MINION 2
#define ALLYBULLET 3
#define ENEMYBULLET 4
#define POWERUPSHIELD 5
#define POWERUPLASER 8
#define ALLYLASER 6
#define BLOCK 7


class Sprites : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
protected:
    QMap<int, QPixmap> pixmap;
    unsigned int ID;
    float scale;

public:
    Sprites(const char *picturePath, float s, unsigned int posx, unsigned int posy, int rot, unsigned int ID);
    ~Sprites();
    void move(int mx, int my);
    virtual void collided(unsigned int ID) {}
    void addPixmap(const char *picturePath, int ID);
    unsigned int getID();

public slots:

signals:
    void deleteThis(Sprites*);

};

#endif