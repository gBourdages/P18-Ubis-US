#ifndef DEMO_CONTROLLERFPGA_H
#define DEMO_CONTROLLERFPGA_H

#include <Windows.h>
#include "CommunicationFPGA.h"

#define A 0b00000001 
#define E 0b00000010
#define I 0b00000100
#define O 0b00001000

class ControllerFPGA {
private:
    int voiceState;

protected:

public:

    ControllerFPGA() {
        voiceState = 0b00000000;
    }

    int getVoiceState() {
        return voiceState;
    }

    void checkVoice() {
        int returnVal = 0b00000000;
        

        if (true) {
            returnVal |= A;
        }

        if (true) {
            returnVal |= E;
        }

        if (true) {
            returnVal |= I;
        }

        if (true) {
            returnVal |= O;
        }

        voiceState = returnVal;
    }
};

#endif