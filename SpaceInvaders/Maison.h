#ifndef MAISON_H
#define MAISON_H
#include "Block.h"
#include <QList>


class Maison {
private:
    QList<Block*>* house;
public:
	Maison(unsigned int posx, unsigned int posy);
	~Maison();
	QList<Block*>* getMaison();
	





};

#endif