#include "Entity.h"

Entity::Entity() {
    width_rectangel = 450;
    height_rectangel = 300;
}
void Entity::drawRectangle(int x, int y, int height, int width, COLORREF color) {
    for (int i = -width / 2; i < width / 2; i++)
    {
        SetPixel(hdc, x + i, y - height / 2, color);
        SetPixel(hdc, x + i, y + height / 2, color);
    }
    for (int j = -height / 2; j < height / 2; j++)
    {
        SetPixel(hdc, x - width / 2, y + j, color);
        SetPixel(hdc, x + width / 2, y + j, color);
    }
}
