#ifndef ITEM_H
#define ITEM_H
#include "Entity.h"

class Item :public Entity {
private:
    int height;
    int width;
    int width_item1 = 482;
    int height_item1 = 135;
    int width_item2 = 220;
    int height_item2 = 125;
    int width_item3 = 659;
    int height_item3 = 135;

public:
    void draw(int x, int y, COLORREF color);
    int* getWidth();
    int* getHeight();
};

#endif
