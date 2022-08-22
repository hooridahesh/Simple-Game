#ifndef EARTH_H
#define EARTH_H
#include "Entity.h"

class Earth : public Entity {
private:
    int width_rectangel = 300;
    int height_rectangel = 450;
public:

    void draw(int x, int y, COLORREF color);
    int* getWidth();
    int* getHeight();
};

#endif 

