#ifndef GACHA_H
#define GACHA_H

#include <iostream>

using namespace std;

class Gacha{

    private:
        string name;
        string description;
        int statBoosted = 0;
        int amountBoosted = 0;

    public:
        Gacha();
        Gacha(string name, string description, int statBoosted, int amountBoosted);
    
    public:

        string getName();
        string getDescription();
        int getStatBoosted();
        int getAmountBoosted();

};

#endif