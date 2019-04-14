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
unsigned const int nreg_lect_stat_btn = 0;                                  // fpga -> PC Statut et BTN lus FPGA -> PC
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
	bool comunicationInit = 1; // pour établir communication 1x
  int voiceState;
  int ancCAN0 = 0;
  int ancCAN1 = 0;
  int ancCAN2 = 0;
  int ancCAN3 = 0;
  bool init;

  int A=-1;
  int E =-1;
  int I = -1;
  int O = -1;

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
     else cout << "Statut initial du port de communication = " << port.estOk() << endl << endl;
  }

  int getVoiceState() { return voiceState; }

  void checkVoice()
  {
	  float max0 = 0;
	  float max1 = 0;
	  float max2 = 0;
	  float max3 = 0;

    if (init) {
      int returnVal = 0b00000000;

      // Valeurs ADC brut Hexa à convertir:
      int CAN0 = -1;
      int CAN1 = -1;
      int CAN2 = -1;
      int CAN3 = -1;


	  // valeurs max, trouver le sommet pour avoir bon ratio.


	  // Valeur calibration pour anthonio

//

	  float a1 = 2.6;
	  float a2 = 1;
	  float a3 = 1.1;
	  float a4 = 0.5;

	  float e1 = 1.5;
	  float e2 = 1.1;
	  float e3 = 0.2;
	  float e4 = 1.2;

	  float o1 = 1.5;
	  float o2 = 2;
	  float o3 = 1.3;
	  float o4 = 1.8;

	  float u1 = 0.9;
	  float u2 = 1;
	  float u3 = 1;
	  float u4 = 1.4;


      // Valeur de convertion:
      float ADCItoF = 3.3/255; // == volt / division

      // Valeurs ADC float (v):
      float valCAN0 = -1;
      float valCAN1 = -1;
      float valCAN2 = -1;
      float valCAN3 = -1;

      // Valeurs min max ADC phonème A (v):
      // Détection front:
      int ancPhonA = 0;
      // 0:
      float val0MinA = 0.74;
      float val0MaxA = 1.35;
      // 1:
      float val1MinA = 0.43;
      float val1MaxA = 0.78;
      // 2:
      float val2MinA = 0.43;
      float val2MaxA = 0.78;
      // 3:
      float val3MinA = 0.26;
      float val3MaxA = 0.47;

      // Valeurs min max ADC phonème E (v):
      // Détection front:
      int ancPhonE = 0;

      // 0:
      float val0MinE = 0.74;
      float val0MaxE = 1.35;

      float val1MinE = 0.81;
      float val1MaxE = 1.49;

      float val2MinE = 1.48;
      float val2MaxE = 2.71;

      float val3MinE = 0.74;
      float val3MaxE = 1.35;

      // Valeurs min max ADC phonème O (v):
      // Détection front:
      int ancPhonO = 0;

      // 0:
      float val0MinO = 0.74;
      float val0MaxO = 1.35;

      float val1MinO = 0.13;
      float val1MaxO = 0.25;

      float val2MinO = 0.87;
      float val2MaxO = 1.60;

      float val3MinO = 0.67;
      float val3MaxO = 1.23;

      // Valeurs min max ADC phonème U (v):
      // Détection front:
      int ancPhonU = 0;

      // 0:
      float val0MinU = 0.74;
      float val0MaxU = 1.35;

      float val1MinU = 1.77;
      float val1MaxU = 3.25;

      float val2MinU = 2.66;
      float val2MaxU = 4.87;

      float val3MinU = 2.07;
      float val3MaxU = 3.79;

      // Lecture des cannaux:
      port.lireRegistre(nreg_lect_can0, CAN0);
      port.lireRegistre(nreg_lect_can1, CAN1);
      port.lireRegistre(nreg_lect_can2, CAN2);
      port.lireRegistre(nreg_lect_can3, CAN3);




	  //les valeurs en entrée sont des float, 255 = 3.3v
      // Convertion des valeurs d'entre convertiseur:

      // CANNAL 0:
      // Étape 1 inverser le float:

//// CAN0 = ~CAN0;


	  // Étape 2 calculer l'équivalent en float
	  valCAN0 = CAN0 * ADCItoF;

	  if (comunicationInit){
	  cout << "Communication initialisée pret a écouter " << endl;
	  cout << CAN0 << endl;
	  comunicationInit = 0;
	  }

	 // if (valCAN0 > 0) {
		//  cout << "CAN0 : " << endl;
		//  cout << CAN0 << endl;

		//  cout << "valCAN0 : " << endl;
		//  cout << valCAN0 << endl;
	 // }
      //cout << "valCAN0 : " << endl;
      //cout << valCAN0 << endl;

      // CANNAL 1:
      // Étape 1 inverser le float:
      ////CAN1 = ~CAN1;
      // Étape 2 calculer l'équivalent en float
      valCAN1 = float(CAN1) * ADCItoF;

	  //if (valCAN1 > 0) {
		//  cout << "CAN1 : " << endl;
		//  cout << CAN1 << endl;
		//  cout << "valCAN1 : " << endl;
		//  cout << valCAN1 << endl;
	 // }

      // CANNAL 2:
      // Étape 1 inverser le float:
      ////CAN2 = ~CAN2;
      // Étape 2 calculer l'équivalent en float
      valCAN2 = float(CAN2) * ADCItoF;
	 // if (valCAN2 > 0) {
	//	  cout << "CAN2 : " << endl;
		//  cout << CAN2 << endl;
		//  cout << "valCAN2 : " << endl;
		//  cout << valCAN2 << endl;
	 // }

      // CANNAL 3:
      // Étape 1 inverser le float:
      ////CAN3 = ~CAN3;
      // Étape 2 calculer l'équivalent en float
      valCAN3 = float(CAN3) * ADCItoF;

	  if (valCAN0 > 0) {
		  float r1 = valCAN0 / valCAN0;
		  float r2 = valCAN1 / valCAN0;
		  float r3 = valCAN2 / valCAN0;
		  float r4 = valCAN3 / valCAN0;

		  if (r1 > max0){
			  max0 = r1;
		  }
		  if (r2 > max1) {
			  max1 = r2;
		  }
		  if (r3 > max2) {
			  max2 = r3;
		  }
		  if (r4 > max3) {
			  max3 = r4;
		  }
		 // cout << "	r1 : " << r1 << "	r2 : " << r2 << "	r3 : " << r3 << "	r4 : " << r4 << endl;
	  }

      // Phonème A:
      if ((ancPhonA == 0) && ((valCAN0 >= val0MinA && valCAN0 <= val0MaxA) &&
        (valCAN1 >= val1MinA && valCAN1 <= val1MaxA) &&
        (valCAN2 >= val2MinA && valCAN2 <= val2MaxA) &&
        (valCAN3 >= val3MinA && valCAN3 <= val3MaxA))) {
        ancPhonA = 1;
        returnVal |= PA;
        cout << "PHONEME A\n";
      }
      else if (!((valCAN0 >= val0MinA && valCAN0 <= val0MaxA) &&
        (valCAN1 >= val1MinA && valCAN1 <= val1MaxA) &&
        (valCAN2 >= val2MinA && valCAN2 <= val2MaxA) &&
        (valCAN3 >= val3MinA && valCAN3 <= val3MaxA)))
      {
        ancPhonA = 0;
      }

      // Phonème E:
      if ((ancPhonE == 0) && ((valCAN0 >= val0MinE && valCAN0 <= val0MaxE) &&
        (valCAN1 >= val1MinE && valCAN1 <= val1MaxE) &&
        (valCAN2 >= val2MinE && valCAN2 <= val2MaxE) &&
        (valCAN3 >= val3MinE && valCAN3 <= val3MaxE))) {
        ancPhonE = 1;
        returnVal |= PE;
        cout << "PHONEME E\n";
      }
      else if (!((valCAN0 >= val0MinE && valCAN0 <= val0MaxE) &&
        (valCAN1 >= val1MinE && valCAN1 <= val1MaxE) &&
        (valCAN2 >= val2MinE && valCAN2 <= val2MaxE) &&
        (valCAN3 >= val3MinE && valCAN3 <= val3MaxE)))
      {
        ancPhonE = 0;
      }

      // Phonème O:
      if ((ancPhonO == 0) && ((valCAN0 >= val0MinO && valCAN0 <= val0MaxO) &&
        (valCAN1 >= val1MinO && valCAN1 <= val1MaxO) &&
        (valCAN2 >= val2MinO && valCAN2 <= val2MaxO) &&
        (valCAN3 >= val3MinO && valCAN3 <= val3MaxO))) {
        ancPhonO = 1;
        returnVal |= PO;
        cout << "PHONEME O\n";
      }
      else if (!((valCAN0 >= val0MinO && valCAN0 <= val0MaxO) &&
        (valCAN1 >= val1MinO && valCAN1 <= val1MaxO) &&
        (valCAN2 >= val2MinO && valCAN2 <= val2MaxO) &&
        (valCAN3 >= val3MinO && valCAN3 <= val3MaxO)))
      {
        ancPhonO = 0;
      }

      // Phonème U:
      if ((ancPhonU == 0) && ((valCAN0 >= val0MinU && valCAN0 <= val0MaxU) &&
        (valCAN1 >= val1MinU && valCAN1 <= val1MaxU) &&
        (valCAN2 >= val2MinU && valCAN2 <= val2MaxU) &&
        (valCAN3 >= val3MinU && valCAN3 <= val3MaxU))) {
        ancPhonU = 1;
        returnVal |= PU;
        cout << "PHONEME U\n";
      }
      else if (!((valCAN0 >= val0MinU && valCAN0 <= val0MaxU) &&
        (valCAN1 >= val1MinU && valCAN1 <= val1MaxU) &&
        (valCAN2 >= val2MinU && valCAN2 <= val2MaxU) &&
        (valCAN3 >= val3MinU && valCAN3 <= val3MaxU)))
      {
        ancPhonU = 0;
      }

      voiceState = returnVal;
    }
	//////////////////////////// retour fonction
	if (max0 > 0) {
		cout << "Vf MAX0 : " << max0 << "	MAX1 : " << max1 << "	MAX2 : " << max2 << "	MAX3 : " << max3 << endl;
	}
  }

  float calibA() {
	  int CAN0 = -1;
	  port.lireRegistre(nreg_lect_can0, CAN0);
	  float temp = CAN0 * 3.3 / 255;
	  A = temp;
	  return temp;
  
  }

  float calibE() {
	  int CAN1 = -1;
	  port.lireRegistre(nreg_lect_can1, CAN1);
	  float temp = CAN1 * 3.3 / 255;
	  A = temp;
	  return temp;
  
  
  }

  float calibI() {
	  int CAN2 = -1;
	  port.lireRegistre(nreg_lect_can2, CAN2);
	  float temp = CAN2 * 3.3 / 255;
	  A = temp;
	  return temp;
  
  }

  float calibO() {
	  int CAN3 = -1;
	  port.lireRegistre(nreg_lect_can3, CAN3);
	  float temp = CAN3 * 3.3 / 255;
	  A = temp;
	  return temp;
  }
};

#endif
