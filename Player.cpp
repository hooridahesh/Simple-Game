#include <iostream>
#include "Player.h"


void Player::draw(int x, int y, COLORREF color) {
    double pi = 2 * acos(0.0);
    for (double theta = 0; theta < 2 * pi; theta += .001) {
        SetPixel(hdc, x - radius * cos(theta), y - radius * sin(theta), color);
    }
}

int* Player::getWidth() {
    static int arr3[1] = { width_circle };
    return arr3;
}
int* Player::getHeight() {
    static int arr2[1] = { height_circle };
    return arr2;
}
