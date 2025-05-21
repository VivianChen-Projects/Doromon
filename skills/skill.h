#ifndef SKILL_H
#define SKILL_H

#include "../doromon.h"

#include <iostream>
#include <random>

using namespace std;

class Skill{

    protected:
        string name = "Default";
        float accuracy;
        int baseCount;
        int currentCount;


    public:
        Skill();
        Skill(string name, float accuracy, int b_count);
        Skill(string name, float accuracy, int c_count, int b_count);
        
    public:
        string getName();
        float getAccuracy(); 

        int getBaseCount();

        void setCurrentCount(int count);
        int getCurrentCount(); 
};

#endif