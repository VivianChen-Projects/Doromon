#ifndef GAME_H
#define GAME_H

#include "doromon.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>

using namespace std;

class Game{

    private:
        Doromon Doro[4];
        int turn = 0;
        bool run = true;
        bool initialized = false;
        int winner = 0;
        priority_queue<Doromon*, vector<Doromon*>, DoromonComparator> turnOrder;

    public:
        void initializeGame(int menu, Game* doromon);
        void randomizeSkill(int index, Doromon* doro);
        void setPlayerMove(int index, Game* doromon, int playerMove);
        void resetAllMove(Game* doromon);
        void setSkillInput(int index, Game* doromon, int move);
        bool checkCount(int index, Game* dormon, int skillIndex);
        void proccessTurnOrder(Game* doromon);
        void proccessDoroMoves(Game* doromon, Doromon* currentDoro);
        bool confirmSave(Game* start, int save);
        void saveData(Game* start);
        void loadData(Game* start);
        void checkWinningCondition(Game* doromon);

    public:
        void setDoro(Doromon *doro[]);
        Doromon* getDoro(int index);
        void setTurn(int turn);
        int getTurn();
        void setRun(bool end);
        bool getRun();
        void setWinner(int Winner);
        int getWinner();
        void setInitialized(bool initialize);
        bool getInitialized();
        void setQueue(priority_queue<Doromon*, vector<Doromon*>, DoromonComparator> TurnOrder);
        priority_queue<Doromon*, vector<Doromon*>, DoromonComparator>* getQueue();


};

#endif