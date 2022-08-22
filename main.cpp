#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Earth.h"
#include "Player.h"
#include "Item.h"

using namespace std;


int makeRandom() {
    int arr[8] = { 355,565,285,635,425,215,495,705 };
    int xx;
    srand(time(0));
    xx = rand() % 5;
    return arr[xx];

}

int main() {

    Entity* entity;
    Entity* player;
    Entity* item;
    Entity* earth;
    Earth e;
    Player p;
    Item i;
    ULONGLONG TimeElapsed = 0;
    ULONGLONG timeToElapseForNextUpdate = 0;
    ULONGLONG timeNow = 0, timePrevious = 0;
    int x1, x2, x3;
    bool flag1 = true, flag2 = true, flag3 = true, b1 = false, b2 = false, b3 = false;
    x1 = makeRandom();
    x2 = makeRandom();
    x3 = makeRandom();
    int score = 0;
    int x = 0;

    while (1) {

        TimeElapsed = timeNow - timePrevious;
        timePrevious = timeNow;
        timeNow = GetTickCount64();

        system("Color 03");
        cout << "Get 8 items to win " << endl << endl;
        cout << "Your current score : " << x<<endl;

        earth = &e;
        player = &p;
        item = &i;

        int* eh = earth->getHeight();
        int* ew = earth->getWidth();
        int* ih = item->getHeight();
        int* pw = player->getWidth();
        int* ph = player->getHeight();

        ih[0] += 12;                         //move item
        ih[1] += 18;
        ih[2] += 15;

        if (_kbhit()) {                       //move player
            if (pw[0]>150 && pw[0]<780) {
                switch (_getch()) {
                case 'd':
                    pw[0] += 50;
                    break;
                case 'a':
                    pw[0] -= 50;
                    break;
                }
            }
        }

        earth->draw(eh[0], ew[0], RGB(0, 255, 0));
        player->draw(pw[0], ph[0], RGB(255, 0, 0));

        if (flag1 && flag2 && flag3) {
            if (flag1) {
                while (1) {
                    x1 = makeRandom();
                    if (x1 != x3 && x2 != x1) {
                        break;
                    }
                }
                flag1 = false;
            }
            if (flag2) {
                while (1) {
                    x2 = makeRandom();
                    if (x1 != x2 && x2 != x3) {
                        break;
                    }
                }
                flag2 = false;
            }
            if (flag3) {
                while (1) {
                    x3 = makeRandom();
                    if (x1 != x3 && x2 != x3) {
                        break;
                    }
                }
                flag3 = false;
            }
        }

        item->draw(x1, ih[0], RGB(192, 192, 192));
        item->draw(x2, ih[1], RGB(255, 255, 0));
        item->draw(x3, ih[2], RGB(111, 49, 152));

        if (ih[0] >= ph[0] - 56 && (pw[0] >= x1 - 45 && pw[0] <= x1 + 45)) {
            ih[0] = 135;
            //b1 = true;
            flag1 = true;
            score++;
            x = score;   
        }
        if (ih[1] >= ph[0] - 60 && (pw[0] >= x2 - 45 && pw[0] <= x2 + 45)) {
            ih[1] = 125;
            //b2 = true;
            flag2 = true;
            score++;
            x = score;
        }
        if (ih[2] >= ph[0] - 60 && (pw[0] >= x3 - 45 && pw[0] <= x3 + 45)) {
            ih[2] = 135;
            //b1 = true;
            flag3 = true;
            score++;
            x = score;
        }
        else if (score == 8) {
            system("cls");
            system("Color 02");
            cout << "You won =))" << endl<<endl;
            break;
        }
        else if (ih[0] >= 485) {
            system("cls");
            system("Color 04");
            cout << "gameover" << endl<<endl;
            break;
        }
        else if (ih[1] >= 486) {
            system("cls");
            system("Color 04");
            cout << "gameover" << endl<<endl;
            break;
        }
        else if (ih[2] >= 475) {
            system("cls");
            system("Color 04");
            cout << "gameover" << endl<<endl;
            break;
        }

        Sleep(80);

        system("cls");
    }

}
