#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Game.h"
#include "Phoneme.h"
#include <QMainWindow>
#include <QMenuBar>
#include <QPushButton>
#include <QStackedWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QtWidgets>

class MenuWindow : public QMainWindow
{
  Q_OBJECT
public:
  MenuWindow(const char* titre = 0);
  ~MenuWindow();
  void Options();
  void calibration();
  void Scores();
  void Play();
  void Credits();
  void Exit();
  void back();
  /////pour camode calib
  void fnA();
  void fnE();
  void fnI();
  void fnO();

  Phoneme A;
  Phoneme E;
  Phoneme I;
  Phoneme O;
  /////pour camode calib


private slots:
  void initHomePage();
  void initOptionsPage();
  void initScoresPage();
  void initCreditsPage();
  QString readScores();
  void printPhoneme(Phoneme p);

private:

	/////pour camode calib
QPushButton* btnA;
QPushButton* btnE;
QPushButton* btnU;
QPushButton* btnO;
/////pour camode calib

  QPushButton* buttonOptions;
  QPushButton* buttonScores;
  QPushButton* buttonPlay;
  QPushButton* buttonCredits;
  QPushButton* buttonExit;

  QPushButton* buttonBackOptions;
  QPushButton* buttonCalibration;
  QPushButton* buttonBackScores;
  QPushButton* buttonBackCredits;

  QLabel* labelExamInvader;
  Game* game;
  ControllerFPGA* fpga;

  QGroupBox* groupBoxVolume;
  QLabel* optionLabel;
  QLabel* optionLabelV;
  QSlider* volumeSlider;

  QTextEdit* textScores;
  QTextEdit* textCredits;

  QStackedWidget* m_MasterWidget;
  QWidget* m_homePage;
  QWidget* OptionsPageWidget;
  QWidget* ScoresPageWidget;
  QWidget* CreditsPageWidget;
  QWidget* CalibPageWidget;
};

#endif
