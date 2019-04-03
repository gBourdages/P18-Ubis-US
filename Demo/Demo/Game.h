#ifndef DEMO_GAME_H
#define DEMO_GAME_H

#include <list>

#include "House.h"
#include "Projectile.h"
#include "Display.h"

class Game {
private:
    std::list<Component> notMovingList;
    std::list<Component> minionsList;
    std::list<Projectile> projectileList;
    bool minionMode;

public:
    Game() {
        House house1(25, 50, notMovingList);
        House house2(50, 50, notMovingList);
        House house3(75, 50, notMovingList);
        House house4(100, 50, notMovingList);
        House house5(125, 50, notMovingList);
        House house6(150, 50, notMovingList);
        House house7(175, 50, notMovingList);
        House house8(200, 50, notMovingList);

        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 10; ++j) {
                minionsList.push_back(Component(20 + (2 * i), 10 + j, 1, 0, 'S'));
            }
        }

        minionMode = false;
    }

    int getShootTime() {
        if (minionMode)
            return 80;
        else
            return 300;
    }

    void shoot(int posx) {
        projectileList.push_back(Projectile(posx, 20, 1));
        if (minionMode)
            projectileList.back().setColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
            
    }

    bool checkProjectileCollision() {
        std::list<Projectile>::iterator it = projectileList.begin();
        while (it != projectileList.end()) {
            if (checkCollisions(*it)) {
                it = projectileList.erase(it);
            }
            else
                it++;
        }
        return false;
    }

    bool checkCollisions(Component c) {
        std::list<Component>::iterator it = notMovingList.begin();
        while (it != notMovingList.end()) {
            if ((*it).checkCollision(c)) {
                it = notMovingList.erase(it);
                return true;
            }
            else
                it++;
        }

        it = minionsList.begin();
        while (it != minionsList.end()) {
            if ((*it).checkCollision(c)) {
                it = minionsList.erase(it);
                return true;
            }
            else
                it++;
        }

        std::list<Projectile>::iterator it1 = projectileList.begin();
        while (it1 != projectileList.end()) {
            if ((*it1).checkCollision(c)) {
                it1 = projectileList.erase(it1);
                return true;
            }
            else
                it1++;
        }

        return false;
    }

    void draw(Engine &s) {
        std::list<Component>::iterator it = notMovingList.begin();
        while (it != notMovingList.end()) {
            (*it).draw(s);
            it++;
        }

        it = minionsList.begin();
        while (it != minionsList.end()) {
            (*it).draw(s);
            it++;
        }

        std::list<Projectile>::iterator it1 = projectileList.begin();
        while (it1 != projectileList.end()) {
            (*it1).draw(s);
            if ((*it1).getposY() > 61)
                it1 = projectileList.erase(it1);
            else
                it1++;
        }
    }

    void moveMinions(int l) {
        std::list<Component>::iterator it = minionsList.begin();
        while (it != minionsList.end()) {
            (*it).move(l, 0);
            it++;
        }
    }

    void minionsBeast() {
        if (!minionMode) {
            for (std::list<Component>::iterator it = minionsList.begin(); it != minionsList.end(); ++it)
                it->setTexture('M');
            minionMode = true;
        }
        else {
            for (std::list<Component>::iterator it = minionsList.begin(); it != minionsList.end(); ++it)
                it->setTexture('S');
            minionMode = false;
        }
        
    }


};

#endif