#include "Game.h"
#include <QDebug>


Game::Game(ControllerFPGA* fpga, QString name) {
	playerName = name;
	score = 0;

    setBackgroundBrush(QPixmap("./ressources/SpaceInvadersBg.jpg"));
    player1 = new Ship(500, 900);
    addSprite(player1);
    
    QList<Block*>* temp;
    Maison a(300, 750);
    temp = a.getMaison();
    for (QList<Block*>::iterator it = temp->begin(); it != temp->end(); ++it) {
        addSprite(*it);
    }

    Maison b(600, 750);
    temp = b.getMaison();
    for (QList<Block*>::iterator it = temp->begin(); it != temp->end(); ++it) {
        addSprite(*it);
    }

    Maison c(900, 750);
    temp = c.getMaison();
    for (QList<Block*>::iterator it = temp->begin(); it != temp->end(); ++it) {
        addSprite(*it);
    }

    Maison d(1200, 750);
    temp = d.getMaison();
    for (QList<Block*>::iterator it = temp->begin(); it != temp->end(); ++it) {
        addSprite(*it);
    }

    Maison e(1500, 750);
    temp = e.getMaison();
    for (QList<Block*>::iterator it = temp->begin(); it != temp->end(); ++it) {
        addSprite(*it);
    }

    minions = new MinionsArray();
    connect(minions, &MinionsArray::addSprites, this, &Display::addSprite);
    QList<Minion*>* temp1;
    temp1 = minions->getArray();
    for (QList<Minion*>::iterator it = temp1->begin(); it != temp1->end(); ++it) {
        connect((*it), &Sprites::deleteThis, minions, &MinionsArray::removeMinion);
        addSprite(*it);
    }
    this->fpga = fpga;
    timefpga = new QTimer();
    connect(timefpga, SIGNAL(timeout()), this, SLOT(checkFPGA()));
    timefpga->start(2);

    timeLaser = new QTimer();
    connect(timeLaser, SIGNAL(timeout()), this, SLOT(laser()));
    timeLaser->start(67000);

    timeShield = new QTimer();
    connect(timeShield, SIGNAL(timeout()), this, SLOT(shield()));
    timeShield->start(15000);


}

Game::~Game()
{
  delete player1;
}

void Game::laser() {
    int randomx = rand() % 1800 - 100;

    addSprite(new PowerUp(POWERUPLASER, randomx, 500));
}

void Game::shield() {
    int randomx = rand() % 1800 - 100;

    addSprite(new PowerUp(POWERUPSHIELD, randomx, 500));
}



void Game::keyPressEvent(QKeyEvent* event) {
    QList<Projectile*>* temp;
    switch (event->key()) {
    case Qt::Key_Left:
      player1->move(-10);
      break;
    case Qt::Key_Right:
      player1->move(10);
      break;
    case Qt::Key_Space:
      temp = player1->shoot();
      if (temp) {
        for (QList<Projectile*>::iterator it = temp->begin(); it != temp->end();
             ++it) {
          addSprite(*it);
        }
      }

      break;
    default:
      QWidget::keyPressEvent(event);
  }
}

void
Game::checkFPGA()
{
  fpga->checkVoice();
  if (fpga->getVoiceState() & PA) {
    // ACTION
  }
  if (fpga->getVoiceState() & PE) {
    // ACTION
  }
  if (fpga->getVoiceState() & PU) {
    // ACTION
  }
  if (fpga->getVoiceState() & PO) {
    // ACTION
  }
}

void Game::closeEvent(QCloseEvent *event)
{
	saveScore();
}

void Game::saveScore() {
	QFile file("scores.txt");
	if (!file.open(QIODevice::Append)) {
		qDebug() << "Couldn't open score file";
		return;
	}
	
	file.write(('\n' + playerName + ' ' + score).toUtf8());
	file.close();
}