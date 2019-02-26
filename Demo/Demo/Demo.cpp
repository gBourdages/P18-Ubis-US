#include "pch.h"

#include "Display.h"
#include "House.h"
#include "Engine.h"

int main() {

    Engine engine(240, 63, BACKGROUND_GREEN | BACKGROUND_RED);

    engine.setPixel(25, 25, '@', FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
    engine.cadre('#', FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);


    while (true) {
        if (engine.getTime() > 33) {
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

