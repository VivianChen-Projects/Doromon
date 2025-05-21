#include "skill.h"

//Constructor
Skill::Skill(){
}

Skill::Skill(string name, float accuracy, int b_count){
    this->name = name;
    this->accuracy = accuracy;
    this->baseCount = b_count;
    this->currentCount = b_count;
}

Skill::Skill(string name, float accuracy, int c_count, int b_count){
    this->name = name;
    this->accuracy = accuracy;
    this->baseCount = b_count;
    this->currentCount = c_count;
}

//Setters and Getters
string Skill::getName(){
    return name;
}

float Skill::getAccuracy(){
    return accuracy;
}

int Skill::getBaseCount(){
    return baseCount;
}

void Skill::setCurrentCount(int count){
    this->currentCount = count;
}

int Skill::getCurrentCount(){
    return currentCount;
}
