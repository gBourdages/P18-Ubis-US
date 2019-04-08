#include "Game.h"

Game::Game() {
    setBackgroundBrush(QPixmap("./ressources/SpaceInvadersBg.jpg"));
    player1 = new Ship(500, 500);
    addSprite(player1);

    tst = new Projectile("./ressources/bullet.png", 0.1, 500, 700, 0, -1, 2);
    addSprite(tst);
}

void Game::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
    case Qt::Key_Left:
        player1->move(-10,0);
        break;
    case Qt::Key_Right:
        player1->move(10, 0);
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

Game::~Game() {
}
