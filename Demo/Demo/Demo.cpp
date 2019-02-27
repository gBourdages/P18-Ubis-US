#include "pch.h"

#include <time.h>
#include "Display.h"
#include "House.h"
#include "Engine.h"
#include "Player.h"
#include "Game.h"

int main() {

    Engine engine(240, 63, BACKGROUND_GREEN | BACKGROUND_RED);
    engine.cadre('#', FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

    Player p(50, 60);

    Game g;

    Timer minionsMoveT;
    int minionsMove = 7;

    Timer minionsShoot;
    srand(time(NULL));

    bool state = false;
    int keyState;

    while (true) {
        if (engine.getTime() > 16) {
            keyState = engine.checkKey();

            if (keyState & SPACE) {
                p.shoot();
            }
            if (keyState & LEFT) {
                p.move(-1, 0);
            }
            if (keyState & RIGHT) {
                p.move(1, 0);
            }


            p.checkCollision(g);
            g.checkProjectileCollision();
            g.draw(engine);
            p.draw(engine);
            engine.draw();
            engine.resetTime();
                
        }
        if (minionsMoveT.getTime() > 1000) {
            g.moveMinions(minionsMove);
            minionsMove *= -1;
            minionsMoveT.reset();
        }

        if (minionsShoot.getTime() > 100) {
            g.shoot(rand() % 200 + 25);
            minionsShoot.reset();
        }

    }
}

