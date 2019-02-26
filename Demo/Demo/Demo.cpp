#include "pch.h"

#include "Display.h"
#include "House.h"
#include "Engine.h"
#include "Player.h"

int main() {

    Engine engine(240, 63, BACKGROUND_GREEN | BACKGROUND_RED);
    engine.cadre('#', FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

    Player p(50, 50);

    bool state = false;
    int keyState;

    while (true) {
        if (engine.getTime() > 15) {
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

            p.draw(engine);
            engine.draw();
            engine.resetTime();
                
        }
    }
        
    /*bool game = true;

    Display screen;
    screen.cadre('H');
    House house1(5, 5);
    house1.draw(screen);
    screen.setPixel(230, 60, '@');
    screen.refresh();

    while (game) {

    }*/
}

