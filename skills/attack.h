#ifndef ATTACK_H
#define ATTACK_H

#include "skill.h"

class Attack:
    public Skill
{
    private:
        int power;

    public:
        Attack();
        Attack(string name, float accuracy, int b_count, int power);
        Attack(string name, float accuracy, int c_count, int b_count, int power);      

    public:
        int getPower();
    
};

#endif