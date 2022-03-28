#include <iostream>
#include <windows.h>
#include <conio.h>
//#include <vector>

using namespace std;

class Entity {
protected:
    int width_rectangel;
    int height_rectangel;
    HWND myconsole = GetConsoleWindow();
    HDC hdc = GetDC(myconsole);
public:
    Entity();
    void drawRectangle(int x, int y, int height, int width, COLORREF color);
};

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

class Player :public Entity {
protected:
    int width_circle;
    int height_circle;
public:
    Player() {
        width_circle = 227;
        height_circle = 452;
    }
    void drawCircle(int x, int y, int radius, COLORREF color);
};

void Player::drawCircle(int x, int y, int radius, COLORREF color) {
    double pi = 2 * acos(0.0);
    for (double theta = 0; theta < 2 * pi; theta += .001) {
        SetPixel(hdc, x - radius * cos(theta), y - radius * sin(theta), color);
    }
}

class Item :public Player {
protected:
    //vector <int> First = {220,125};
    int x1 = 220;
    int y1 = 125;
    int x2 = 482;
    int y2 = 146;
    int x3 = 659;
    int y3 = 135;
public:
    void run();
};

void Item::run() {

    bool flag1 = false, flag2 = false, flag3 = false;

    while (1) {

        cout << "Collected items: ";

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

        if (flag1 == false) {
            //x1 += 0;
            y1 += 17;
        }

        if (flag2 == false) {
            //x2 += 0;
            y2 += 30;
        }

        if (flag3 == false) {
            //x3 += 0;
            y3 += 12;
        }

        system("cls");

        if (y1 >= 397 && (width_circle >= 232 - 45 && width_circle <= 232 + 45)) {
            //First.~vector();
            //First.clear();
            x1 = 35;
            y1 = 45;
            flag1 = true;
        }
        else if (y2 >= 400 && (width_circle >= 450 - 45 && width_circle <= 450 + 45)) {
            x2 = 45;
            y2 = 95;
            flag2 = true;
        }
        else if (y3 >= 387 && (width_circle >= 650 - 45 && width_circle <= 650 + 45)) {
            x3 = 32;
            y3 = 150;
            flag3 = true;
        }
        else if (flag1 == true && flag2 == true && flag3 == true) {
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

int main() {
    Item s;
    s.run();
    return 0;
}