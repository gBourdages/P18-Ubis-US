#include "Game.h"
#include <QDebug>

Game::Game() {
    setBackgroundBrush(QPixmap("./ressources/SpaceInvadersBg.jpg"));
    player1 = new Ship(500, 900);
    addSprite(player1);
    Maison h(200, 750);
    QList<Block*>* temp;
    temp = h.getMaison();
    for (QList<Block*>::iterator it = temp->begin(); it != temp->end(); ++it) {
        addSprite(*it);
    }
    minions = new MinionsArray();
    QList<Minion*>* temp1;
    temp1 = minions->getArray();
    for (QList<Minion*>::iterator it = temp1->begin(); it != temp1->end(); ++it) {
        addSprite(*it);
    }
}

Game::~Game() {
    delete player1;
}



void Game::keyPressEvent(QKeyEvent* event) {
    QList<Projectile*>* temp;
    switch (event->key()) {
    case Qt::Key_Left:
        player1->move(-10);
        break;
    case Qt::Key_Right:
        player1->move(10);
        break;
    case Qt::Key_Space:
        temp = player1->shoot();
        if(temp) {
            for (QList<Projectile*>::iterator it = temp->begin(); it != temp->end(); ++it) {
                addSprite(*it);
            }
        }
        
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

