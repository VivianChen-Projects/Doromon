#ifndef DOROMON_H
#define DOROMON_H

#include "skills/attack.h" 
#include "skills/support.h" 
#include "gacha.h"

#include <iostream>
#include <random>

using namespace std;

class Doromon{

    private:
        string name;
        int index;
        int baseAtk;
        int currentAtk;
        int baseHp;
        int currentHp;
        int baseSpd;
        int currentSpd;
        string move;
        int skillIndex;
        int dealth;
        int target;
        bool successMove;
        int deadWhileMove;

        Attack atkSkills[3];
        Support supportSkills[3];

        Gacha gacha;


    public:
        Doromon();
        Doromon(string name, int index, int b_atk, int b_hp, int b_spd, Attack* atkSkills, Support* supportSkills, Gacha gacha);
        Doromon(string name, int index, int b_atk, int b_hp, int b_spd, int c_atk, int c_hp, int c_spd, int dead, Attack* atkSkills, Support* supportSkills, Gacha gacha);

    public:
        void useAttack(Doromon& playerDoro, Doromon& targetDoro);
        void useSupport(Doromon& playerDoro, Doromon& targetDoro);
        void useGacha(Doromon& playerDoro);
        void setDeath();
        bool operator<(const Doromon &move)const;

    public:
        string getName();
        int getIndex();
        
        void setBaseAtk(int atk);
        int getBaseAtk();
        void setCurrentAtk(int atk);
        int getCurrentAtk();

        void setBaseHp(int hp);
        int getBaseHp();
        void setCurrentHp(int hp);
        int getCurrentHp();

        void setBaseSpd(int spd);
        int getBaseSpd();
        void setCurrentSpd(int spd);
        int getCurrentSpd();

        void setMove(string move);
        string getMove();

        void setSkillIndex(int index);
        int getSkillIndex();

        void setAtkSkill(int index, Attack* atk);
        Attack* getAtkSkill(int index);
        void setSupportSkill(int index, Support* support);
        Support* getSupportSkill(int index);

        void setGacha(Gacha gacha);
        Gacha* getGacha();

        void setDealth(int dealth);
        int getDeatlth();

        void setTarget(int target);
        int getTarget();

        void setSuccessMove(bool success);
        bool getSuccessMove();

        
        void setDead(int dead);
        int getDead();

};

//for priority queue to compare the object and not address
struct DoromonComparator {
    bool operator()(Doromon* left, Doromon* right) const {
        return *left < *right;
    }
};


#endif