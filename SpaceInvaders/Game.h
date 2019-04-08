#ifndef GAME_H
#define GAME_H

#include <QKeyEvent>
#include "Display.h"
#include "Ship.h"
#include "Projectile.h"

class Game : public Display {
Q_OBJECT
private:
    Ship* player1;
    Projectile* tst;

public:
    Game();
    ~Game();
    void keyPressEvent(QKeyEvent* event) override;
};

#endif
