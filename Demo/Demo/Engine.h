#ifndef ENGINE_H
#define ENGINE_H

#include <Windows.h>
#include <string>

#define SPACE 0b00000001
#define LEFT 0b00000010
#define RIGHT 0b00000100

// MAX SIZE 1080P FULL SCREEN = 240 X 63

class Engine {
private:
    int sizex, sizey;
    int length;
    bool cadreOn;

    wchar_t* screen;
    wchar_t* consoleTitle;
    WORD* attributes;

    WORD defaultBG;

    HANDLE hscreen;
    DWORD written;

    unsigned long int ticks;
    unsigned long int fpsTicks;
    unsigned int fps;
    //CONSOLE_CURSOR_INFO info;

    
protected:

public:
    Engine(int sizex, int sizey, WORD bg) {
        this->sizex = sizex;
        this->sizey = sizey;
        this->length = sizex * sizey;
        defaultBG = bg;
        cadreOn = false;

        screen = new wchar_t[length];
        consoleTitle = new wchar_t[128];
        attributes = new WORD[length];

        hscreen = CreateConsoleScreenBuffer(GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
        SetConsoleActiveScreenBuffer(hscreen);

        /*info.bVisible = false;
        SetConsoleCursorInfo(hscreen, &info);*/

        for (int i = 0; i < length; ++i) {
            screen[i] = ' ';
            attributes[i] = defaultBG;
        }

        ticks = GetTickCount();
        fpsTicks = GetTickCount();
        fps = 0;
    }

    void setPixel(unsigned int x, unsigned int y, char data, WORD c) {
        screen[(sizex * y) + x] = data;
        attributes[(sizex * y) + x] = c;
    }

    void setPixel(unsigned int x, unsigned int y, char data) {
        screen[(sizex * y) + x] = data;
    }

    void cadre(char d, WORD c) {
        for (int i = 0; i < sizey; ++i) {
            setPixel(0, i, d, c);
            setPixel(sizex - 1, i, d, c);
        }

        for (int i = 0; i < sizex; ++i) {
            setPixel(i, 0, d, c);
            setPixel(i, sizey - 1, d, c);
        }
        cadreOn = true;
    }

    void cadre(bool state) {
        cadreOn = state;
    }

    void clean() {
        if (cadreOn) {
            for (int i = 1; i < (sizex - 1); ++i) {
                for (int j = 1; j < (sizey - 1); ++j) {
                    setPixel(i, j, ' ', defaultBG);
                }
            }
        }
        else {
            for (int i = 0; i < length; ++i) {
                screen[i] = ' ';
                attributes[i] = defaultBG;
            }
        }
    }

    void draw() {
        WriteConsoleOutputAttribute(hscreen, attributes, length, { 0, 0 }, &written);
        WriteConsoleOutputCharacter(hscreen, screen, length, {0, 0}, &written);
        fps++;
        if (GetTickCount() - fpsTicks >= 1000) {
            swprintf_s(consoleTitle, 128, L"%d", fps);
            SetConsoleTitle(consoleTitle);
            fpsTicks = GetTickCount();
            fps = 0;
        }
        clean();
    }

    unsigned long int getTime() {
        return GetTickCount() - ticks;
    }

    void resetTime() {
        ticks = GetTickCount();
    }

    int checkKey() {

        int returnVal = 0b00000000;

        if (GetAsyncKeyState(VK_SPACE))
            returnVal |= SPACE;

        if (GetAsyncKeyState(VK_LEFT))
            returnVal |= LEFT;

        if (GetAsyncKeyState(VK_RIGHT))
            returnVal |= RIGHT;

        return returnVal;
    }

};

#endif
