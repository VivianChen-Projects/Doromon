#ifndef SUPPORT_H
#define SUPPORT_H

#include "skill.h"

class Support:
    public Skill
{
    private:
        int heal;

    public:
        Support();
        Support(string name, float accuracy, int b_count, int heal);
        Support(string name, float accuracy, int c_count, int b_count, int heal);


    public:
        int getHeal();

};

#endif