#ifndef ORDERSCREEN_H
#define ORDERSCREEN_H

#include <iostream>
#include <queue>

#include "../game.h"

using namespace std;

class OrderScreen{
    public:
        void displayOrder(Game* start);
        void askSave();
};

#endif