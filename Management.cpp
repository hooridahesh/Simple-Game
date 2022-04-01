#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Management.h"

using namespace std;

void Management::run() {

    int i = 0;
    while (1) {

        cout << "Get 15 items to win ";

        if (_kbhit() && _getch() == 'd') {
            width_circle += 50;
        }
        else if (_kbhit() && _getch() == 'a') {
            width_circle -= 50;
        }

        drawCircle(width_circle, height_circle, 45, RGB(255, 0, 0));
        drawRectangle(x1, y1, 30, 50, RGB(255, 255, 0));
        drawRectangle(x2, y2, 38, 60, RGB(192, 192, 192));
        drawRectangle(x3, y3, 48, 20, RGB(111, 49, 152));
        drawRectangle(width_rectangel, height_rectangel, 400, 550, RGB(0, 255, 0));

        Sleep(500);

        y1 += 17;
        y2 += 25;
        y3 += 12;

        system("cls");

        if (y1 >= 397 && (width_circle >= 232 - 45 && width_circle <= 232 + 45)) {
            y1 = 125;
            i++;
        }
        else if (y2 >= 396 && (width_circle >= 450 - 45 && width_circle <= 450 + 45)) {
            y2 = 146;
            i++;
        }
        else if (y3 >= 387 && (width_circle >= 650 - 45 && width_circle <= 650 + 45)) {
            y3 = 135;
            i++;
        }
        else if (i == 15) {
            cout << "You won =))" << endl;
            break;
        }
        else if (y1 >= 485) {
            cout << "gameover" << endl;
            break;
        }
        else if (y2 >= 486) {
            cout << "gameover" << endl;
            break;
        }
        else if (y3 >= 475) {
            cout << "gameover" << endl;
            break;
        }
    }
}
