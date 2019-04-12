#ifndef GAME_H
#define GAME_H

#include <QKeyEvent>
#include "Display.h"
#include "Ship.h"
#include "Maison.h"
#include "MinionsArray.h"


class Game : public Display {
Q_OBJECT
private:
    Ship* player1;
    MinionsArray* minions;


public:
    Game();
    ~Game();
    void keyPressEvent(QKeyEvent* event) override;

public slots:

};

#endif

