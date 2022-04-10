#ifndef PLAYER_H
#define PLAYET_H
#include "Entity.h"

class Player :public Entity {
private:
    int width_circle = 210;
    int height_circle = 452;
    int radius = 45;
public:

    void draw(int x, int y, COLORREF color);
    int* getWidth();
    int* getHeight();
};

#endif 

