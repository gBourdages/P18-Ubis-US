#ifndef CONTROLLERFPGA_H
#define CONTROLLERFPGA_H

#include "CommunicationFPGA.h"
#include <iostream>

using namespace std;

#define PA 0b00000001
#define PE 0b00000010
#define PO 0b00000100
#define PU 0b00001000

// numeros de registres correspondants pour les echanges FPGA <-> PC ...
unsigned const int nreg_lect_stat_btn =
  0;                                  // fpga -> PC Statut et BTN lus FPGA -> PC
unsigned const int nreg_lect_swt = 1; // fpga -> PC SWT lus FPGA -> PC
unsigned const int nreg_lect_cmpt_t = 2; // fpga -> PC compteur temps FPGA -> PC
unsigned const int nreg_lect_can0 = 3;   // fpga -> PC canal 0 lus FPGA -> PC
unsigned const int nreg_lect_can1 = 4;   // fpga -> PC canal 1 lus FPGA -> PC
unsigned const int nreg_lect_can2 = 5;   // fpga -> PC canal 2 lus FPGA -> PC
unsigned const int nreg_lect_can3 = 6;   // fpga -> PC canal 3 lus FPGA -> PC
unsigned const int nreg_ecri_aff7sg0 = 7; // PC -> fpga (octet 0 aff.7 seg.)
unsigned const int nreg_ecri_aff7sg1 = 8; // PC -> fpga (octet 1 aff.7 seg.)
unsigned const int nreg_ecri_aff7dot = 9; // PC -> fpga (donnees dot-points)
unsigned const int nreg_ecri_led = 10;    // PC -> fpga (donnees leds)

class ControllerFPGA
{
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
  ControllerFPGA()
  {
    voiceState = 0b00000000;
    init = port.estOk();
    if (!init) {
      cout << port.messageErreur() << endl;
    }
    // else cout << "Statut initial du port de communication = " << port.estOk()
    // << endl << endl;
  }

  int getVoiceState() { return voiceState; }

  void checkVoice()
  {
    if (init) {
      int returnVal = 0b00000000;

      // Valeurs ADC brut Hexa à convertir:
      int CAN0 = -1;
      int CAN1 = -1;
      int CAN2 = -1;
      int CAN3 = -1;

      // Valeur de convertion:
      float ADCItoF = 3.3 / 255;

      // Valeurs ADC float (v):
      float valCAN0 = -1;
      float valCAN1 = -1;
      float valCAN2 = -1;
      float valCAN3 = -1;

      // Valeurs min max ADC phonème A (v):
      // Détection front:
      int ancPhonA = 0;
      // 0:
      float val0MinA = 2.00;
      float val0MaxA = 3.65;
      // 1:
      float val1MinA = 0.46;
      float val1MaxA = 0.85;
      // 2:
      float val2MinA = 1.37;
      float val2MaxA = 2.50;
      // 3:
      float val3MinA = 0.70;
      float val3MaxA = 1.29;

      // Valeurs min max ADC phonème E (v):
      // Détection front:
      int ancPhonE = 0;

      // 0:
      float val0MinE = 0.55;
      float val0MaxE = 1.01;

      float val1MinE = 1.37;
      float val1MaxE = 2.50;

      float val2MinE = 0.85;
      float val2MaxE = 1.56;

      float val3MinE = 0.55;
      float val3MaxE = 1.01;

      // Valeurs min max ADC phonème O (v):
      // Détection front:
      int ancPhonO = 0;

      // 0:
      float val0MinO = 1.11;
      float val0MaxO = 2.03;

      float val1MinO = 0.00;
      float val1MaxO = 1.00;

      float val2MinO = 0.11;
      float val2MaxO = 0.20;

      float val3MinO = 0.18;
      float val3MaxO = 0.34;

      // Valeurs min max ADC phonème U (v):
      // Détection front:
      int ancPhonU = 0;

      // 0:
      float val0MinU = 0.15;
      float val0MaxU = 0.27;

      float val1MinU = 0.41;
      float val1MaxU = 0.74;

      float val2MinU = 0.70;
      float val2MaxU = 1.29;

      float val3MinU = 1.13;
      float val3MaxU = 2.06;

      // Lecture des cannaux:
      port.lireRegistre(nreg_lect_can0, CAN0);
      port.lireRegistre(nreg_lect_can1, CAN1);
      port.lireRegistre(nreg_lect_can2, CAN2);
      port.lireRegistre(nreg_lect_can3, CAN3);

      // Convertion des valeurs d'entre convertiseur:

      // CANNAL 0:
      // Étape 1 inverser le float:
      CAN0 = ~CAN0;
      // Étape 2 calculer l'équivalent en float
      valCAN0 = float(CAN0) * ADCItoF;

      // CANNAL 1:
      // Étape 1 inverser le float:
      CAN1 = ~CAN1;
      // Étape 2 calculer l'équivalent en float
      valCAN1 = float(CAN1) * ADCItoF;

      // CANNAL 2:
      // Étape 1 inverser le float:
      CAN2 = ~CAN2;
      // Étape 2 calculer l'équivalent en float
      valCAN2 = float(CAN2) * ADCItoF;

      // CANNAL 3:
      // Étape 1 inverser le float:
      CAN3 = ~CAN3;
      // Étape 2 calculer l'équivalent en float
      valCAN3 = float(CAN3) * ADCItoF;

      // Phonème A:
      if ((ancPhonA == 0) && ((valCAN0 >= val0MinA && valCAN0 <= val0MaxA) &&
                              (valCAN1 >= val1MinA && valCAN1 <= val1MaxA) &&
                              (valCAN2 >= val2MinA && valCAN2 <= val2MaxA) &&
                              (valCAN3 >= val3MinA && valCAN3 <= val3MaxA))) {
        ancPhonA = 1;
        returnVal |= PA;
      } else {
        ancPhonA = 0;
      }

      // Phonème E:
      if ((ancPhonE == 0) && ((valCAN0 >= val0MinE && valCAN0 <= val0MaxE) &&
                              (valCAN1 >= val1MinE && valCAN1 <= val1MaxE) &&
                              (valCAN2 >= val2MinE && valCAN2 <= val2MaxE) &&
                              (valCAN3 >= val3MinE && valCAN3 <= val3MaxE))) {
        ancPhonE = 1;
        returnVal |= PE;
      } else {
        ancPhonE = 0;
      }

      // Phonème O:
      if ((ancPhonO == 0) && ((valCAN0 >= val0MinO && valCAN0 <= val0MaxO) &&
                              (valCAN1 >= val1MinO && valCAN1 <= val1MaxO) &&
                              (valCAN2 >= val2MinO && valCAN2 <= val2MaxO) &&
                              (valCAN3 >= val3MinO && valCAN3 <= val3MaxO))) {
        ancPhonO = 1;
        returnVal |= PO;
      } else {
        ancPhonO = 0;
      }

      // Phonème U:
      if ((ancPhonU == 0) && ((valCAN0 >= val0MinU && valCAN0 <= val0MaxU) &&
                              (valCAN1 >= val1MinU && valCAN1 <= val1MaxU) &&
                              (valCAN2 >= val2MinU && valCAN2 <= val2MaxU) &&
                              (valCAN3 >= val3MinU && valCAN3 <= val3MaxU))) {
        ancPhonU = 1;
        returnVal |= PU;
      } else {
        ancPhonU = 0;
      }

      /*
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
      */

      voiceState = returnVal;
    }
  }

  void calibA() {}

  void calibE() {}

  void calibI() {}

  void calibO() {}
};

#endif
