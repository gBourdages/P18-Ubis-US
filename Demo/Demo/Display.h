#ifndef DEMO_DISPLAY_H
#define DEMO_DISPLAY_H

#include <iostream>

#define SIZEX 231
#define SIZEY 61

class Display {
protected:
    char screen[(SIZEX)* SIZEY];
    unsigned int totalSize;

public:

    Display() {
        totalSize = (SIZEX)* SIZEY;
        for (int i = 0; i < totalSize; ++i)
            screen[i] = ' ';

        for (int i = 0; i < SIZEY; ++i)
            screen[(i * SIZEX) + SIZEX] = '\n';
        
    }

    void setPixel(unsigned int x, unsigned int y, char data) {
        screen[(SIZEX * y) + x] = data;
    }

    void refresh() {
        std::cout << screen;
    }

    void blanc() {
        for (int i = 0; i < totalSize; ++i)
            screen[i] = ' ';

        for (int i = 0; i < SIZEY; ++i) {
            screen[(i * SIZEX) + SIZEX] = '\n';
        }
    }

    void cadre(char c) {
        for (int i = 1; i < SIZEY; ++i) {
            setPixel(1, i, c);
            setPixel(SIZEX - 1, i, c);
        }

        for (int i = 1; i < SIZEX; ++i) {
            setPixel(i, 1, c);
            setPixel(i, SIZEY - 1, c);
        }
    }
};

#endif
