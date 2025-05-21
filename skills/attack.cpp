#include "attack.h"

//Constructor
Attack::Attack(){
}

Attack::Attack(string name, float accuracy, int count, int power):Skill(name, accuracy, count){

    this->power = power;
}

Attack::Attack(string name, float accuracy, int c_count, int b_count, int power):Skill(name, accuracy, c_count, b_count){

    this->power = power;
}

//Getter
int Attack::getPower(){
    return power;
}
