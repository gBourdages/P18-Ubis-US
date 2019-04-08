#include "Game.h"
#include <QDebug>

Game::Game() {
    setBackgroundBrush(QPixmap("./ressources/SpaceInvadersBg.jpg"));
    player1 = new Ship(500, 500);
    addSprite(player1);
    connect(player1, &Sprites::deleteThis, this, &Display::removeSprites);
}

Game::~Game() {

}





void Game::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
    case Qt::Key_Left:
        player1->move(-10);
        break;
    case Qt::Key_Right:
        player1->move(10);
        break;
    case Qt::Key_Space:
        Projectile* temp;
        temp = player1->shoot();
        connect(temp, &Sprites::deleteThis, this, &Display::removeSprites);
        addSprite(temp);
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

