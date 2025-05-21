#include "gacha.h"

//Constructor
Gacha::Gacha(){
}

Gacha::Gacha(string name, string description, int statBoosted, int amountBoosted){
    this->name = name;
    this->description = description;
    this->statBoosted = statBoosted;
    this->amountBoosted = amountBoosted;
}

//Setters and Getters
string Gacha::getName(){
    return name;
}

string Gacha::getDescription(){
    return description;
}

int Gacha::getStatBoosted(){
    return statBoosted;
}

int Gacha::getAmountBoosted(){
    return amountBoosted;
}