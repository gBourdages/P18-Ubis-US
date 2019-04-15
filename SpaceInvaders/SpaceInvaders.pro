TEMPLATE     = vcapp
TARGET       = SpaceInvaders
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     += Ship.h Display.h Projectile.h Sprites.h Game.h Weapon.h Default.h AllyBullet.h AllyLaser.h EnemyBullet.h Laser.h Block.h Maison.h Minion.h EnemyWeapon.h MinionsArray.h MainWindow.h CommunicationFPGA.h ControllerFPGA.h PowerUp.h Phoneme.h
SOURCES     += SpaceInvaders.cpp Ship.cpp Display.cpp Projectile.cpp Sprites.cpp Game.cpp Weapon.cpp Default.cpp AllyBullet.cpp AllyLaser.cpp EnemyBullet.cpp Laser.cpp Block.cpp Maison.cpp Minion.cpp EnemyWeapon.cpp MinionsArray.cpp MainWindow.cpp PowerUp.cpp
INCLUDEPATH += 
LIBS	      += CommunicationFPGA.lib
QT += widgets
