#ifndef CONTROLLERFPGA_H
#define CONTROLLERFPGA_H

#include <iostream>
#include "CommunicationFPGA.h"


using namespace std;

#define A 0b00000001 
#define E 0b00000010
#define I 0b00000100
#define O 0b00001000

// numeros de registres correspondants pour les echanges FPGA <-> PC ... 
unsigned const int nreg_lect_stat_btn = 0; // fpga -> PC Statut et BTN lus FPGA -> PC 
unsigned const int nreg_lect_swt = 1; // fpga -> PC SWT lus FPGA -> PC 
unsigned const int nreg_lect_cmpt_t = 2; // fpga -> PC compteur temps FPGA -> PC 
unsigned const int nreg_lect_can0 = 3; // fpga -> PC canal 0 lus FPGA -> PC 
unsigned const int nreg_lect_can1 = 4; // fpga -> PC canal 1 lus FPGA -> PC 
unsigned const int nreg_lect_can2 = 5; // fpga -> PC canal 2 lus FPGA -> PC 
unsigned const int nreg_lect_can3 = 6; // fpga -> PC canal 3 lus FPGA -> PC 
unsigned const int nreg_ecri_aff7sg0 = 7; // PC -> fpga (octet 0 aff.7 seg.) 
unsigned const int nreg_ecri_aff7sg1 = 8; // PC -> fpga (octet 1 aff.7 seg.) 
unsigned const int nreg_ecri_aff7dot = 9; // PC -> fpga (donnees dot-points) 
unsigned const int nreg_ecri_led = 10; // PC -> fpga (donnees leds)


class ControllerFPGA {
private:
    int voiceState;
    int ancCAN0 = 0;
    int ancCAN1 = 0;
    int ancCAN2 = 0;
    int ancCAN3 = 0;
    bool init;
    CommunicationFPGA port; // Instance du port de communication

protected:

public:

    ControllerFPGA() {
        voiceState = 0b00000000;
        init = port.estOk();
        if (!init) { cout << port.messageErreur() << endl; }
        //else cout << "Statut initial du port de communication = " << port.estOk() << endl << endl;
    }

    int getVoiceState() {
        return voiceState;
    }

    void checkVoice() {
        if (init) {
            int returnVal = 0b00000000;

            int CAN0 = -1;
            int CAN1 = -1;
            int CAN2 = -1;
            int CAN3 = -1;




            port.lireRegistre(nreg_lect_can0, CAN0);

            port.lireRegistre(nreg_lect_can1, CAN1);

            port.lireRegistre(nreg_lect_can2, CAN2);

            port.lireRegistre(nreg_lect_can3, CAN3);


            if (CAN0 >= 0x60 && ancCAN0 < 0x60) {
                ancCAN0 = CAN0;
                returnVal |= A;
            }
            else if (CAN0 < 0x60) {
                ancCAN0 = 0;
            }

            if (CAN1 >= 0x60 && ancCAN1 < 0x60) {
                ancCAN1 = CAN1;
                returnVal |= E;
            }
            else if (CAN1 < 0x60) {
                ancCAN1 = 0;
            }

            if (CAN2 >= 0x60 && ancCAN2 < 0x60) {
                ancCAN2 = CAN2;
                returnVal |= I;
            }
            else if (CAN2 < 0x60) {
                ancCAN2 = 0;
            }

            if (CAN3 >= 0x60 && ancCAN3 < 0x60) {
                ancCAN3 = CAN3;
                returnVal |= O;
            }
            else if (CAN3 < 0x60) {
                ancCAN3 = 0;
            }

            voiceState = returnVal;
        }
    }

    void calibA() {

    }

    void calibE() {

    }

    void calibI() {

    }

    void calibO() {

    }
};

#endif