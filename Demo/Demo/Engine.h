#ifndef ENGINE_H
#define ENGINE_H

#include <Windows.h>
#include <string>

// MAX SIZE 1080P FULL SCREEN = 240 X 63

class Engine {
private:
    int sizex, sizey;
    int length;

    wchar_t* screen;
    wchar_t* consoleTitle;
    WORD* attributes;

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

        screen = new wchar_t[length];
        consoleTitle = new wchar_t[128];
        attributes = new WORD[length];

        hscreen = CreateConsoleScreenBuffer(GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
        SetConsoleActiveScreenBuffer(hscreen);

        /*info.bVisible = false;
        SetConsoleCursorInfo(hscreen, &info);*/

        for (int i = 0; i < length; ++i) {
            screen[i] = ' ';
            attributes[i] = bg;
        }

        ticks = GetTickCount();
        fpsTicks = GetTickCount();
        fps = 0;
    }

    void setPixel(unsigned int x, unsigned int y, char data, WORD c) {
        screen[(sizex * y) + x] = data;
        attributes[(sizex * y) + x] = c;
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
    }

    unsigned long int getTime() {
        return GetTickCount() - ticks;
    }

    void resetTime() {
        ticks = GetTickCount();
    }

};

#endif
