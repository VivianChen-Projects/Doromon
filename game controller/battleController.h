#ifndef BATTLECONTROLLER_H
#define BATTLECONTROLLER_H

#include <iostream>
#include <queue>

#include "../battle view/otherMoveScreen.cpp"
#include "../battle view/orderScreen.cpp"
#include "../battle view/useSkillScreen.cpp"

#include "../game.h"


using namespace std;

class BattleController{
    private:

        bool orderRunning = true;

        OtherMoveScreen other;
        OrderScreen order;
        UseSkillScreen useSkill;

    public:
        void run(Game* start);
};

#endif