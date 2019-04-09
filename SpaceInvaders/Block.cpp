#include "Block.h"

Block::Block(unsigned int posx, unsigned int posy) : Sprites("./ressources/brick.png", BLOCKSCALE, posx, posy, 0, BLOCK) {

}


Block::~Block() {

}

void Block::collided(unsigned int ID) {
    switch (ID) {
    case ENEMYBULLET:
        emit this->deleteThis(this);
        break;
    case ALLYBULLET:
        emit this->deleteThis(this);
    }

}