#ifndef CONTROLLERFPGA_H
#define CONTROLLERFPGA_H

#include "Phoneme.h"
#include "CommunicationFPGA.h"
#include <iostream>
#include <QTime>
#include <QDebug>

using namespace std;

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
  bool init;

  Phoneme A;
  Phoneme E;
  Phoneme I;
  Phoneme O;

  CommunicationFPGA port; // Instance du port de communication

protected:
public:
  ControllerFPGA()
  {
    init = port.estOk();
    if (!init) {
      cout << port.messageErreur() << endl;
	 }
     else cout << "Statut initial du port de communication = " << port.estOk() << endl << endl;
  }

  Phoneme lireFPGA() {
	  int CAN0 = 0;
	  int CAN1 = 0;
	  int CAN2 = 0;
	  int CAN3 = 0;

	  port.lireRegistre(nreg_lect_can0, CAN0);
	  port.lireRegistre(nreg_lect_can1, CAN1);
	  port.lireRegistre(nreg_lect_can2, CAN2);
	  port.lireRegistre(nreg_lect_can3, CAN3);

	  //float total = CAN0 + CAN1 + CAN2 + CAN3;
	  float total = 255;

	  /*
	  if (CAN0 <= 0 || CAN1 <= 0 || CAN2 <= 0 || CAN3 <= 0) {
		  return { 0, 0, 0, 0 };
	  }
	  */
	  qDebug() << "===";
	  qDebug() << CAN0 << ", " << CAN1 << ", " << CAN2 << ", " << CAN3;
	  qDebug() << "===";

	  Phoneme temp;
	  temp.can0 = CAN0;
	  temp.can1 = CAN1;
	  temp.can2 = CAN2;
	  temp.can3 = CAN3;

	  return temp;
  }

  bool inRange(double a, double b) {
	  if (b == 0) {
		  return false;
	  }

	  const double tolerance = 50.0f;

	  return a >= b - b * tolerance / 100.0f &&
		  a <= b + b * tolerance / 100.0f;
  }

  bool compare(Phoneme val, Phoneme ref) {
	  return inRange(val.can0, ref.can0) &&
		  inRange(val.can1, ref.can1) &&
		  inRange(val.can2, ref.can2) &&
		  inRange(val.can3, ref.can3);
  }
  
  Phon getVoice() {
    Phoneme val = lireFPGA();

    if (val.can0 > A.can0 - 5 && val.can1 >= A.can1 - 5) {
      return Phon::A;
    }
    else if (val.can0 <= I.can0 + 15 && val.can2 >= I.can2 - 5) {
      return Phon::I;
    }


    else if (val.can1 <= O.can1 + 10 && val.can0 > O.can0 - 5) {
      return Phon::O;
    }
    else {
      return Phon::None;
    }
  }

 

  Phoneme calibrate() {
	  QTime time = QTime::currentTime();
	  QTime echantillon = QTime::currentTime();
	  Phoneme total{ 0, 0, 0, 0 };
	  int freq = 20;
	  quint64 counter = 0;
	  
	 while (time.elapsed() < 3000) {
		 while (echantillon.elapsed() < freq) {
		 }

		 Phoneme temp = lireFPGA();
		 total.can0 += temp.can0;
		 total.can1 += temp.can1;
		 total.can2 += temp.can2;
		 total.can3 += temp.can3;

		 counter++;
		 echantillon = QTime::currentTime();
	 }

	 total.can0 /= (double)counter;
	 total.can1 /= (double)counter;
	 total.can2 /= (double)counter;
	 total.can3 /= (double)counter;
	 
	 qDebug() << "==Moyenne==";
	 qDebug() << total.can0 << ", " << total.can1 << ", " << total.can2 << ", " << total.can3;
	 qDebug() << "====";

	 return total;
  }

  Phoneme calibE() {
	  E = calibrate();
	  return E;
  }

  Phoneme calibI() {
	  I = calibrate();
	  return I;
  }

  Phoneme calibO() {
	  O = calibrate();
	  return O;
  }

  Phoneme calibA() {
	  A = calibrate();
	  return A;
  }
};

#endif
