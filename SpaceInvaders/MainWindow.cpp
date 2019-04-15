#include "MainWindow.h"
#include <QtWidgets>

MenuWindow::MenuWindow(const char* titre)
{
  fpga = new ControllerFPGA;
  // init main window
  setWindowTitle(tr(titre));
  setMinimumSize(200, 150);
  setFixedSize(800, 600);

  m_MasterWidget = new QStackedWidget;

  initHomePage();
  initOptionsPage();
  initScoresPage();
  initCreditsPage();

  // init pages

  m_MasterWidget->addWidget(m_homeView);
  m_MasterWidget->addWidget(OptionsPageWidget);
  m_MasterWidget->addWidget(ScoresPageWidget);
  m_MasterWidget->addWidget(CreditsPageWidget);

  setCentralWidget(m_MasterWidget);
}

MenuWindow::~MenuWindow() {}

void
MenuWindow::initHomePage()
{
	m_homeScene = new QGraphicsScene();
	m_homeScene->setSceneRect(this->rect());

	Button* play = new Button(":/Ressources2/play.png",
		":/Ressources2/play_hovered.png",
		{ 200, 100 },
		{ m_homeScene->width() / 2 - 100, 0 });

	Button* options = new Button(":/Ressources2/options.png",
		":/Ressources2/options_hovered.png",
		{ 200, 100 },
		{ m_homeScene->width() / 2 - 100, 110 });

	Button* scores = new Button(":/Ressources2/scores.png",
		":/Ressources2/scores_hovered.png",
		{ 200, 100 },
		{ m_homeScene->width() / 2 - 100, 220 });

	Button* credits = new Button(":/Ressources2/credits.png",
		":/Ressources2/credits_hovered.png",
		{ 200, 100 },
		{ m_homeScene->width() / 2 - 100, 330 });

	Button* exit = new Button(":/Ressources2/exit.png",
		":/Ressources2/exit_hovered.png",
		{ 200, 100 },
		{ m_homeScene->width() / 2 - 100, 440 });

	m_homeScene->addItem(play);
	m_homeScene->addItem(exit);
	m_homeScene->addItem(options);
	m_homeScene->addItem(scores);
	m_homeScene->addItem(credits);

	connect(play, &Button::clicked, this, &MenuWindow::Play);
	connect(exit, &Button::clicked, this, &MenuWindow::Exit);
	connect(options, &Button::clicked, this, &MenuWindow::Options);
	connect(credits, &Button::clicked, this, &MenuWindow::Credits);
	connect(scores, &Button::clicked, this, &MenuWindow::Scores);

	m_homeView = new QGraphicsView(m_homeScene);
	m_homeView->setAlignment(Qt::AlignCenter);
	m_homeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	m_homeView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
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

  QGroupBox* groupBox = new QGroupBox(tr("Volume:"));

  optionLabel = new QLabel("Options:", this);
  optionLabel->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
  optionLabelV = new QLabel(" ", this);

  volumeSlider = new QSlider(Qt::Horizontal, this);
  buttonBackOptions = new QPushButton("Retour", this);
  buttonCalibration = new QPushButton("Calibration", this);

  connect(buttonBackOptions, &QPushButton::clicked, this, &MenuWindow::back);
  connect(
    buttonCalibration, &QPushButton::clicked, this, &MenuWindow::calibration);

  QVBoxLayout* vbox = new QVBoxLayout;

  vbox->addWidget(volumeSlider);
  groupBox->setLayout(vbox);

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
}

void
MenuWindow::calibration()
{
 // QMessageBox msgBox;
  //msgBox.setText("Calibration");
 // msgBox.setInformativeText(
  //  "Vous avez appuyé sur le bouton calibration, pour calibrer les phonèmes.");
  //msgBox.setStandardButtons(QMessageBox::Ok);
 // msgBox.setDefaultButton(QMessageBox::Ok);
  //int ret = msgBox.exec();
	CalibPageWidget = new QWidget;

  btnA = new QPushButton("btnA", this);
  btnE = new QPushButton("btnE", this);
  btnU = new QPushButton("btnU", this);
  btnO = new QPushButton("btnO", this);


  //connect(buttonBackCredits, &QPushButton::clicked, this, &MenuWindow::back);

  QGridLayout* layout = new QGridLayout;
  layout = new QGridLayout;
  layout->addWidget(btnA, 1, 1, 1, 1);
  connect(btnA, &QPushButton::clicked, this, &MenuWindow::fnA);
  layout->addWidget(btnE, 1, 2, 1, 1);
  connect(btnE, &QPushButton::clicked, this, &MenuWindow::fnE);
  layout->addWidget(btnU, 2, 3, 1, 1);
  connect(btnU, &QPushButton::clicked, this, &MenuWindow::fnI);
  layout->addWidget(btnO, 2, 4, 1, 1);
  connect(btnO, &QPushButton::clicked, this, &MenuWindow::fnO);
  CalibPageWidget->setLayout(layout);
  CalibPageWidget->show();
  
  /// ajoutter les appels a la calibration. ajoutter bouttons A O E U 

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

  textScores = new QTextEdit("Scores");
  textScores->setDisabled(true);

  auto scores = readScores().split("\n");
  scores.removeAll("");
  if (scores.length() > 0) {
    for (auto score : scores) {
      textScores->append(score);
    }
  } else {
    textScores->append("Aucun score n'a été encore enregistré");
  }

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
MenuWindow::Play()
{
	bool ok;
	QString text;

	while (!ok || text.isEmpty()) {
		text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
			tr("Entrez votre pseudonyme:"), QLineEdit::Normal,
			QDir::home().dirName(), &ok);
	}

  game = new Game(fpga, text);

  game->show();
}

void
MenuWindow::initCreditsPage()
{
  CreditsPageWidget = new QWidget;

  buttonBackCredits = new QPushButton("Retour", this);
  textCredits = new QTextEdit(
    "Les créateurs de cette application sont:  Philippe Bernard-Lévesque: "
    "BERP2810; Gabriel Bourdages: BOUG2341; Samuel Cyr: CYRS2502; Hantz-Carly "
    "F. Vius: VIUH2801");
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

QString
MenuWindow::readScores()
{
  QFile file("scores.txt");
  if (!file.open(QIODevice::ReadOnly)) {
    qDebug() << "Didn't find file";
    return {};
  }
  return file.readAll();
}

void MenuWindow::printPhoneme(Phoneme p)
{
	qDebug() << p.can0 << ", "
		<< p.can1 << ", "
		<< p.can2 << ", "
		<< p.can3 << "\n";
}

void
MenuWindow::fnA(){
	A = fpga->calibA();
	qDebug() << "Calib A: ";
	printPhoneme(A);
}
void
MenuWindow::fnE() {

	E = fpga->calibE();
	qDebug() << "Calib E: ";
	printPhoneme(E);
}
void
MenuWindow::fnI() {
	I = fpga->calibI();
	qDebug() << "Calib I: ";
	printPhoneme(I);
}
void
MenuWindow::fnO() {
	O = fpga->calibO();
	qDebug() << "Calib O: ";
	printPhoneme(O);
}
