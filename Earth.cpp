#include "Earth.h"

void Earth::draw(int x, int y, COLORREF color) {
    for (int i = -600 / 2; i < 600 / 2; i++)
    {
        SetPixel(hdc, x + i, y - 400 / 2, color);
        SetPixel(hdc, x + i, y + 400 / 2, color);
    }
    for (int j = -400 / 2; j < 400 / 2; j++)
    {
        SetPixel(hdc, x - 600 / 2, y + j, color);
        SetPixel(hdc, x + 600 / 2, y + j, color);
    }
}
int* Earth::getWidth() {
    static int arr3[1] = { width_rectangel };
    return arr3;
}
int* Earth::getHeight() {
    static int arr2[1] = { height_rectangel };
    return arr2;
}
