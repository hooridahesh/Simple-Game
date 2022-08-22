#include "Item.h"


void Item::draw(int x, int y, COLORREF color) {
    height = 38;
    width = 60;
    for (int i = -width; i < width; i++)
    {
        SetPixel(hdc, x + i / 2, y - height / 4, color);
        SetPixel(hdc, x + i / 2, y + height / 4, color);
    }

    for (int j = -height; j < height; j++)
    {
        SetPixel(hdc, x - width + 45, y + j / 2, color);
        SetPixel(hdc, x + width - 45, y + j / 2, color);
    }
}
int* Item::getWidth() {
    static int arr[3] = { width_item1, width_item2,width_item3 };
    return arr;
}
int* Item::getHeight() {
    static int arr1[3] = { height_item1, height_item1, height_item1 };
    return arr1;
}


