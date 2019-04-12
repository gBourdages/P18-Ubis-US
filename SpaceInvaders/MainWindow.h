#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QPushButton>
#include <QStackedWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QtWidgets>
#include "Game.h"

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

private slots:
  void initHomePage();
  void initOptionsPage();
  void initScoresPage();
  void initCreditsPage();

private:
  // QWidget *widget;
  // QVBoxLayout *layout;

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

  QGroupBox* groupBoxVolume;
  QLabel* optionLabel;
  QLabel* optionLabelV;
  QSlider* volumeSlider;

  QTextEdit* textScores;
  QTextEdit* textCredits;


  

  //  QGraphicsScene* welcomeScene;
  //  QGraphicsView* view;

  QStackedWidget* m_MasterWidget;
  QWidget* m_homePage;
  QWidget* OptionsPageWidget;
  QWidget* ScoresPageWidget;
  QWidget* CreditsPageWidget;
};

#endif
