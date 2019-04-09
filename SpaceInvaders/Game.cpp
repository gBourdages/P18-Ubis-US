#include "Game.h"
#include <QDebug>

Game::Game() {
    setBackgroundBrush(QPixmap("./ressources/SpaceInvadersBg.jpg"));
    player1 = new Ship(500, 500);
    addSprite(player1);
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
        for (QList<Projectile*>::iterator it = temp->begin(); it != temp->end(); ++it) {
            addSprite(*it);
        }
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

