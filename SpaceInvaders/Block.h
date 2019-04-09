#ifndef BLOCK_H
#define BLOCK_H
#define BLOCKSCALE 0.3
#include "Sprites.h"

class Block : public Sprites {
Q_OBJECT

public:
	Block(unsigned int posx, unsigned int posy);
	~Block();
	int life;
	void collided(unsigned int ID);
};
#endif

