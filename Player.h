#ifndef PLAYER_H
#define PLAYET_H
#include <windows.h>
#include "Entity.h"

class Player :virtual public Entity {
protected:
    int width_circle;
    int height_circle;
public:
    Player();
    void drawCircle(int x, int y, int radius, COLORREF color);
};

#endif 

