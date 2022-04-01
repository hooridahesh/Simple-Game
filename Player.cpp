#include <iostream>
#include "Player.h"


Player::Player() {
    width_circle = 227;
    height_circle = 452;
}

void Player::drawCircle(int x, int y, int radius, COLORREF color) {
    double pi = 2 * acos(0.0);
    for (double theta = 0; theta < 2 * pi; theta += .001) {
        SetPixel(hdc, x - radius * cos(theta), y - radius * sin(theta), color);
    }
}
