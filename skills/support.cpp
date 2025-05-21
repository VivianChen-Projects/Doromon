#include "support.h"

//Constructor
Support::Support(){
}

Support::Support(string name, float accuracy, int count, int heal):Skill(name, accuracy, count){
    this->heal = heal;
}

Support::Support(string name, float accuracy, int c_count, int b_count, int power):Skill(name, accuracy, c_count, b_count){
    this->heal = heal;
}

//Getter
int Support::getHeal(){
    return heal;
}
