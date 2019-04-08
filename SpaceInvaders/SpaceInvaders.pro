TEMPLATE     = vcapp
TARGET       = SpaceInvaders
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     += Ship.h Display.h Projectile.h Sprites.h Game.h Weapon.h
SOURCES     += SpaceInvaders.cpp Ship.cpp Display.cpp Projectile.cpp Sprites.cpp Game.cpp Weapon.cpp
INCLUDEPATH += 
LIBS	      += 
QT += widgets
