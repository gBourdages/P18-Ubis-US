#include "pch.h"

#include <time.h>
#include "Display.h"
#include "House.h"
#include "Engine.h"
#include "Player.h"
#include "Game.h"
#include "ControllerFPGA.h"

int main() {

    Engine engine(240, 63, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    engine.cadre('#', FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    bool dlc = true;

    ControllerFPGA voiceIn;

    Player p(50, 60);

    Game g;

    Timer minionsMoveT;
    int minionsMove = 7;

    Timer minionsShoot;
    srand(time(NULL));

    bool state = false;
    int keyState;
    bool run = true;

    while (true) {
        if (!run) {
            keyState = engine.checkKey();
            if (keyState & ESC) {
                run = !run;
                while (engine.getTime() < 1000) {}
            }
            if (voiceIn.getVoiceState() & O) {
                //ACTION
                run = !run;
                while (engine.getTime() < 1000) {}
            }
            
        }

        if (engine.getTime() > 16 && run) {
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
            if ((keyState & M) && dlc) {
                g.minionsBeast();
            }
            if ((keyState & B) && dlc) {
                p.box();
            }
            if (keyState & ESC) {
                run = !run;
            }

            //CONTROL WITH VOICE
            voiceIn.checkVoice();
            if ((voiceIn.getVoiceState() & A) && dlc) {
                //ACTION
                p.box();
            }
            if ((voiceIn.getVoiceState() & E) && dlc) {
                //ACTION
                g.minionsBeast();

            }
            if (voiceIn.getVoiceState() & I) {
                //ACTION
                p.shoot();
            }
            if (voiceIn.getVoiceState() & O) {
                //ACTION
                run = !run;
            }

                



            p.checkCollision(g);
            g.checkProjectileCollision();
            g.draw(engine);
            p.draw(engine);
            engine.draw();
            
                
            if (minionsMoveT.getTime() > 1000) {
                g.moveMinions(minionsMove);
                minionsMove *= -1;
                minionsMoveT.reset();
            }

            if (minionsShoot.getTime() > g.getShootTime()) {
                g.shoot(rand() % 200 + 25);
                minionsShoot.reset();
            }
            engine.resetTime();
        }
    }
}

