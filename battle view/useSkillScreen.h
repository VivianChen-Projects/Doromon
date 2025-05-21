#ifndef USESKILLSCREEN_H
#define USESKILLSCREEN_H

#include <iostream>
#include <queue>

#include "../doromon.h"

using namespace std;

class UseSkillScreen{
    public:
        void displaySkillHit(Doromon* currentDoro, Doromon* targetDoro);
        void displaySkillMiss(Doromon* currentDoro);
};

#endif