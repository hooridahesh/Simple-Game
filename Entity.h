#ifndef ENTITY_H
#define ENTITY_H
#include <windows.h>


class Entity {
protected:
    HWND myconsole = GetConsoleWindow();
    HDC hdc = GetDC(myconsole);
    COLORREF color;
public:
    virtual void draw(int x, int y, COLORREF color) = 0;       //Pure Virtual Functions
    virtual int* getWidth() = 0;
    virtual int* getHeight() = 0;
};

#endif

