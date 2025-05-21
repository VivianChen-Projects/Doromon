#ifndef MOVESCREEN_H
#define MOVESCREEN_H

#include <iostream>

#include "../game.h"

using namespace std;

class MoveScreen{
    public:
        void displayMove(int index, Game* doromon);
};

#endif