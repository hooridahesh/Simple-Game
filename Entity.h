#ifndef ENTITY_H
#define ENTITY_H
#include <windows.h>


class Entity {
protected:
    int width_rectangel;
    int height_rectangel;
    HWND myconsole = GetConsoleWindow();
    HDC hdc = GetDC(myconsole);
public:
    Entity();
    void drawRectangle(int x, int y, int height, int width, COLORREF color);
};

#endif

