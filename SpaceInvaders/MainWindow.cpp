#include "MainWindow.h"
#include <QtWidgets>

MenuWindow::MenuWindow(const char* titre)
{
    fpga = new ControllerFPGA;
  // init main window
  setWindowTitle(tr(titre));
  setMinimumSize(200, 150);
  setFixedSize(800, 600);
  //resize(200, 150);

    m_MasterWidget = new QStackedWidget;

    initHomePage();
    initOptionsPage();
    initScoresPage();
    initCreditsPage();

    /*
    QPixmap bkgnd("BackgroundBlackHole.jpg");
    // bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    m_homePage->setPalette(palette);
    */

  // init pages
  


  m_MasterWidget->addWidget(m_homePage);
  m_MasterWidget->addWidget(OptionsPageWidget);
  m_MasterWidget->addWidget(ScoresPageWidget);
  m_MasterWidget->addWidget(CreditsPageWidget);
  

  setCentralWidget(m_MasterWidget);
  
  //  setLayout(layout);

  //  QPixmap bkgnd(":/BackgroundMenu.jpg");
  //  // bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
  //  QPalette palette;
  //  palette.setBrush(QPalette::Background, bkgnd);
  //  m_MasterWidget->setPalette(palette);

  //  welcomeScene = new QGraphicsScene();
  //  welcomeScene->addPixmap(bkgnd.scaled(100, 100));

  //  view = new QGraphicsView(welcomeScene);
  //  setCentralWidget(view);
  /*
  widget = new QWidget;
  setCentralWidget(widget);
  */

  // QGraphicsScene* scene;
  // scene->setBackgroundBrush(QPixmap("./ressources/BackgroundMenu.jpg"));

  /*
  // Cr�ation des Widgets
  button0 = new QPushButton("Options", this);
  button1 = new QPushButton("Scores", this);
  button2 = new QPushButton("Play", this);
  button3 = new QPushButton("Credits", this);
  button4 = new QPushButton("Exit", this);
  // Cr�ation des liens
  connect(button0, &QPushButton::clicked, this, &MenuWindow::Options);
  connect(button1, &QPushButton::clicked, this, &MenuWindow::Scores);
  connect(button2, &QPushButton::clicked, this, &MenuWindow::Play);
  connect(button3, &QPushButton::clicked, this, &MenuWindow::Credits);
  connect(button4, &QPushButton::clicked, this, &MenuWindow::Exit);

  // Cr�ation du layout
  QGridLayout *layout = new QGridLayout;
  layout = new QGridLayout;
  layout->addWidget(button0, 0, 0, 1, 1);
  layout->addWidget(button1, 0, 1, 1, 1);
  layout->addWidget(button2, 1, 0, 1, 0);
  layout->addWidget(button3, 2, 0, 1, 1);
  layout->addWidget(button4, 2, 1, 1, 1);


  widget->setLayout(layout);
  */
}

MenuWindow::~MenuWindow() {}

void
MenuWindow::initHomePage()
{
  m_homePage = new QWidget;


  // Cr�ation des Widgets
  labelExamInvader = new QLabel("Exam Invader", this);
  labelExamInvader->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
  buttonOptions = new QPushButton("Options", this);
  buttonScores = new QPushButton("Scores", this);
  buttonPlay = new QPushButton("Jouer", this);
  buttonCredits = new QPushButton("Crédits", this);
  buttonExit = new QPushButton("Quitter", this);
  // Cr�ation des liens
  connect(buttonOptions, &QPushButton::clicked, this, &MenuWindow::Options);
  connect(buttonScores, &QPushButton::clicked, this, &MenuWindow::Scores);
  connect(buttonPlay, &QPushButton::clicked, this, &MenuWindow::Play);
  connect(buttonCredits, &QPushButton::clicked, this, &MenuWindow::Credits);
  connect(buttonExit, &QPushButton::clicked, this, &MenuWindow::Exit);

  // Cr�ation du layout
  QGridLayout* layout = new QGridLayout;
  layout = new QGridLayout;

  
  layout->addWidget(labelExamInvader, 1, 1, 1, 2);
  layout->addWidget(buttonOptions,    2, 1, 1, 1);
  layout->addWidget(buttonScores,     2, 2, 1, 1);
  layout->addWidget(buttonPlay,       3, 1, 1, 2);
  layout->addWidget(buttonCredits,    4, 1, 1, 1);
  layout->addWidget(buttonExit,       4, 2, 1, 1);

  m_homePage->setLayout(layout);
}

void
MenuWindow::back()
{
  m_MasterWidget->setCurrentIndex(0);
}

void
MenuWindow::initOptionsPage()
{
  OptionsPageWidget = new QWidget;


  QGroupBox *groupBox = new QGroupBox(tr("Volume:"));
  
  optionLabel = new QLabel("Options:", this);
  optionLabel->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
  optionLabelV = new QLabel(" ", this);

  volumeSlider = new QSlider(Qt::Horizontal, this);
  buttonBackOptions = new QPushButton("Retour", this);
  buttonCalibration = new QPushButton("Calibration", this);

  connect(buttonBackOptions, &QPushButton::clicked, this, &MenuWindow::back);
  connect(buttonCalibration, &QPushButton::clicked, this, &MenuWindow::calibration);

  //groupBoxVolume = new QGroupBox("Volume");
  
  QVBoxLayout *vbox = new QVBoxLayout;

  //vbox->addWidget(optionLabelV);
  vbox->addWidget(volumeSlider);
  groupBox->setLayout(vbox);

  /*
  QGridLayout* layout = new QGridLayout;
  layout = new QGridLayout;

  layout->addWidget(vbox, 1, 1, 1, 1);
  layout->addWidget(buttonBackOptions, 2, 1, 1, 1);
  */

  QGridLayout* layout = new QGridLayout;
  layout->addWidget(optionLabelV, 0, 1);
  layout->addWidget(optionLabelV, 1, 1);
  layout->addWidget(optionLabelV, 2, 1);
  layout->addWidget(optionLabelV, 3, 1);
  layout->addWidget(optionLabelV, 4, 1);
  layout->addWidget(optionLabelV, 5, 1);
  layout->addWidget(optionLabelV, 6, 1);
  layout->addWidget(optionLabelV, 7, 1);
  layout->addWidget(optionLabel, 8, 1);
  layout->addWidget(groupBox, 9, 1);
  layout->addWidget(buttonCalibration, 10, 1);
  layout->addWidget(buttonBackOptions, 11, 1);
  

  OptionsPageWidget->setLayout(layout);

  // CODE SAM:

  /*
  OptionsPageWidget = new QWidget;
  QGroupBox *groupBox = new QGroupBox(tr("Exclusive Radio Buttons"));
  QRadioButton *radio1 = new QRadioButton(tr("&Radio button 1"));
  QRadioButton *radio2 = new QRadioButton(tr("R&adio button 2"));
  QRadioButton *radio3 = new QRadioButton(tr("Ra&dio button 3"));
  radio1->setChecked(true);

  QVBoxLayout *vbox = new QVBoxLayout;
  vbox->addWidget(radio1);
  vbox->addWidget(radio2);
  vbox->addWidget(radio3);
  vbox->addStretch(1);
  groupBox->setLayout(vbox);

  QGridLayout *grid = new QGridLayout;
  grid->addWidget(groupBox, 0, 0);
  OptionsPageWidget->setLayout(grid);
  */
  
  
}

void
MenuWindow::calibration()
{
  QMessageBox msgBox;
  msgBox.setText("Calibration");
  msgBox.setInformativeText("Vous avez appuyé sur le bouton calibration, pour calibrer les phonèmes.");
  msgBox.setStandardButtons(QMessageBox::Ok);
  msgBox.setDefaultButton(QMessageBox::Ok);
  int ret = msgBox.exec();
}

void
MenuWindow::Options()
{  
  m_MasterWidget->setCurrentIndex(1);
}

void
MenuWindow::initScoresPage()
{
  ScoresPageWidget = new QWidget;

  buttonBackScores = new QPushButton("Retour", this);
  textScores = new QTextEdit("Les scores des joueurs seront affiché ici.");                   // ALLER LIRE UN FICHEIR TEXTE AVEC LES SCORES.
  textScores->setDisabled(true);

  connect(buttonBackScores, &QPushButton::clicked, this, &MenuWindow::back);

  QGridLayout* layout = new QGridLayout;
  layout = new QGridLayout;

  layout->addWidget(textScores, 1, 1, 1, 1);
  layout->addWidget(buttonBackScores, 2, 1, 1, 1);
  


  ScoresPageWidget->setLayout(layout);
}

void
MenuWindow::Scores()
{
  m_MasterWidget->setCurrentIndex(2);
}


void
MenuWindow::Play() {
  QMessageBox msgBox;
  msgBox.setText("Jouer");
  msgBox.setInformativeText("Vous avez appuyé sur le bouton jouer.");
  msgBox.setStandardButtons(QMessageBox::Ok);
  msgBox.setDefaultButton(QMessageBox::Ok);
  int ret = msgBox.exec();


  game = new Game(fpga);

  game->show();
}

void
MenuWindow::initCreditsPage() {
  CreditsPageWidget = new QWidget;

  buttonBackCredits = new QPushButton("Retour", this);
  textCredits = new QTextEdit("Les créateurs de cette application sont:  Philippe Bernard-Lévesque: BERP2810; Gabriel Bourdages: BOUG2341; Samuel Cyr: CYRS2502; Hantz-Carly F. Vius: VIUH2801");                   // ALLER LIRE UN FICHEIR TEXTE AVEC LES SCORES.
  textCredits->setDisabled(true);

  connect(buttonBackCredits, &QPushButton::clicked, this, &MenuWindow::back);

  QGridLayout* layout = new QGridLayout;
  layout = new QGridLayout;

  layout->addWidget(textCredits, 1, 1, 1, 1);
  layout->addWidget(buttonBackCredits, 2, 1, 1, 1);



  CreditsPageWidget->setLayout(layout);
}

void
MenuWindow::Credits()
{
  m_MasterWidget->setCurrentIndex(3);
}

void
MenuWindow::Exit()
{
  QMessageBox msgBox;
  msgBox.setText("Quitter");
  msgBox.setInformativeText("Bye bye :)");
  msgBox.setStandardButtons(QMessageBox::Ok);
  msgBox.setDefaultButton(QMessageBox::Ok);
  int ret = msgBox.exec();

  close();
}
