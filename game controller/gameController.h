#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <iostream>

#include "../game view/gameScreen.cpp"
#include "../game view/moveScreen.cpp"
#include "../game view/skillScreen.cpp"
#include "../game view/invalidScreen.cpp"
#include "../game view/winnerScreen.cpp"

#include "../game.h"

using namespace std;

class GameController{
    private:
        bool gameRunning = true;
        bool moveRunning = true;
        bool skillRunning = true;

        GameScreen game;
        MoveScreen move;
        SkillScreen skill;
        InvalidScreen invalid;
        WinnerScreen win;

    public:
        void run(int menu, Game* start);
        void checkWin(Game* start);
};

#endif