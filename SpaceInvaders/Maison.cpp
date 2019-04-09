#include "Maison.h"

Maison::Maison(unsigned int posx, unsigned int posy) {
	house = new QList<Block*>();
	
    house->push_back(new Block(2 * 100 * BLOCKSCALE + posx, 0 * 100 * BLOCKSCALE + posy));
    house->push_back(new Block(1 * 100 * BLOCKSCALE + posx, 1 * 100 * BLOCKSCALE + posy));
    house->push_back(new Block(2 * 100 * BLOCKSCALE + posx, 1 * 100 * BLOCKSCALE + posy));
    house->push_back(new Block(3 * 100 * BLOCKSCALE + posx, 1 * 100 * BLOCKSCALE + posy));
    house->push_back(new Block(0 * 100 * BLOCKSCALE + posx, 2 * 100 * BLOCKSCALE + posy));
    house->push_back(new Block(1 * 100 * BLOCKSCALE + posx, 2 * 100 * BLOCKSCALE + posy));
    house->push_back(new Block(2 * 100 * BLOCKSCALE + posx, 2 * 100 * BLOCKSCALE + posy));
    house->push_back(new Block(3 * 100 * BLOCKSCALE + posx, 2 * 100 * BLOCKSCALE + posy));
    house->push_back(new Block(1 * 100 * BLOCKSCALE + posx, 3 * 100 * BLOCKSCALE + posy));
    house->push_back(new Block(2 * 100 * BLOCKSCALE + posx, 3 * 100 * BLOCKSCALE + posy));
    house->push_back(new Block(3 * 100 * BLOCKSCALE + posx, 3 * 100 * BLOCKSCALE + posy));
    house->push_back(new Block(4 * 100 * BLOCKSCALE + posx, 2 * 100 * BLOCKSCALE + posy));

}

Maison::~Maison() {

}

QList<Block*>* Maison::getMaison() {
	return house;
}