#ifndef ITEM_H
#define ITEM_H
#include <windows.h>
#include "Entity.h"

class Item :virtual public Entity {
protected:
    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;
public:
    Item();
};

#endif
