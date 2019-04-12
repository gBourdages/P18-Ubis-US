#ifndef GAME_H
#define GAME_H

#include <QKeyEvent>
#include "Display.h"
#include "Ship.h"
#include "Maison.h"
#include "MinionsArray.h"
#include "ControllerFPGA.h"


class Game : public Display {
Q_OBJECT
private:
    Ship* player1;
    MinionsArray* minions;
    ControllerFPGA* fpga;
    QTimer* timefpga;

public:
    Game(ControllerFPGA* fpga);
    ~Game();
    void keyPressEvent(QKeyEvent* event) override;
    
public slots:
    void checkFPGA();

};

#endif

