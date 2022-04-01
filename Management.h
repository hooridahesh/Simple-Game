#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include "Player.h"
#include "Item.h"

class Management :public Player, public Item {
public:
    void run();
};

#endif
