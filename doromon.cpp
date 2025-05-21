#include "doromon.h"

//Constructor
Doromon::Doromon(){
}

Doromon::Doromon(string name, int index, int b_atk, int b_hp, int b_spd, Attack* atkSkills, Support* supportSkills, Gacha gacha){

    this->name = name;
    this->index = index;
    this->baseAtk = b_atk;
    this->currentAtk = b_atk;
    this->baseHp = b_hp;
    this->currentHp = b_hp;
    this->baseSpd = b_spd;
    this->currentSpd = b_spd;
    this->dealth = 0;
    this->target = 0;
    this->deadWhileMove = 0;
    
    for (int i = 0; i < 3; i++){
        this->atkSkills[i] = *atkSkills;
        this->supportSkills[i] = *supportSkills;
    }

    this->gacha = gacha;
}

Doromon::Doromon(string name, int index, int b_atk, int b_hp, int b_spd, int c_atk, int c_hp, int c_spd, int dead, Attack* atkSkills, Support* supportSkills, Gacha gacha){

    this->name = name;
    this->index = index;
    this->baseAtk = b_atk;
    this->currentAtk = c_atk;
    this->baseHp = b_hp;
    this->currentHp = c_hp;
    this->baseSpd = b_spd;
    this->currentSpd = c_spd;
    this->dealth = 0;
    this->target = 0;
    this->deadWhileMove = dead;
    
    for (int i = 0; i < 3; i++){
        this->atkSkills[i] = *atkSkills;
        this->supportSkills[i] = *supportSkills;
    }

    this->gacha = gacha;
}
//Functions

/*
this function gets called when a doromon used an attack
includes:
    Accuracy Checks
    Hp update
*/
void Doromon::useAttack(Doromon& currentDoro, Doromon& targetDoro){

    /*
        get info current and target doro 

        pick will be initialed with the skill index of the current doro
        accuracy will be initialized with the accuracy of the atk skill chosen by the current doro

        accuracy check will be done by randomizing a float number and then compared
        check if hp will go into the negatives if it did set to 0
    */

    int dealth;
    int pick = currentDoro.getSkillIndex();
    currentDoro.getAtkSkill(pick)->getAccuracy();

    random_device hit;
    uniform_real_distribution<float> acc(0,1);

    float ifHit= ceil(acc(hit)*100)/100;
    currentDoro.setSuccessMove(false);
            
    if (ifHit <= currentDoro.getAtkSkill(pick)->getAccuracy()){
        dealth = (currentDoro.getAtkSkill(pick)->getPower()+currentDoro.getBaseAtk())*2/15;
        targetDoro.setCurrentHp(targetDoro.getCurrentHp()-dealth);
        currentDoro.setDealth(dealth);
        currentDoro.setSuccessMove(true);

        if(targetDoro.getCurrentHp()<=0){
            targetDoro.setCurrentHp(0);
        }
    }
    else
        currentDoro.setSuccessMove(false);

}

/*
this function gets called when a doromon used a heal
includes:
    Accuracy Checks
    Hp update
*/
void Doromon::useSupport(Doromon& currentDoro, Doromon& targetDoro){
    
    /*  
        get info of current and target doro 

        pick will be initialed with the skill index of the current doro
        accuracy will be initialized with the accuracy of the support skill chosen by the current doro

        accuracy check will be done here by randomizing a float number and then compared

        will check if it overheals, if it does set hp to base hp
    */

    int heal;
    int pick = currentDoro.getSkillIndex();

    random_device hit;
    uniform_real_distribution<float> acc(0,1);
    
    float ifHit= ceil(acc(hit)*100)/100;
    currentDoro.setSuccessMove(false);

    if (ifHit <= currentDoro.getSupportSkill(pick)->getAccuracy()){
        heal = (currentDoro.getSupportSkill(pick)->getHeal()+currentDoro.getBaseAtk())*2/15;
        targetDoro.setCurrentHp(targetDoro.getCurrentHp()+heal);
        currentDoro.setDealth(heal);
        currentDoro.setSuccessMove(true);
            if(targetDoro.getCurrentHp()>targetDoro.getBaseHp())
            targetDoro.setCurrentHp(targetDoro.getBaseHp());
    }
    else
        currentDoro.setSuccessMove(false);
}

/*
this function gets called when a doromon used the gacha system
includes:
    Item List
    Updates the item eqquiped
*/
void Doromon::useGacha(Doromon& currentDoro){

    /*
        removes every buff by setting doromon stats to what it used to be (the base of each stat except hp)
        
        randomizes which item to equip
        Gacha("item name", "item description", "stat boosted", "stat boosted mount")
        
        stat boosted:
        1. Atk
        2. Hp
        3. Spd 
    */

    random_device randGacha;
    uniform_int_distribution<int> random(1,4);
    int item = random(randGacha);

    Gacha gacha;

    currentDoro.setCurrentAtk(currentDoro.getBaseAtk());
    currentDoro.setCurrentSpd(currentDoro.getBaseSpd());

    if (item == 1){
        gacha = Gacha("Cola", "A cold cola from the fridge spd+5", 3, 5);
        currentDoro.setGacha(gacha);
    }
    else if (item == 2){
        gacha = Gacha("Chocolate Bar", "A random chocolate bar you brought from home atk+5", 1, 5);
        currentDoro.setGacha(gacha);
    }
    else if (item == 3){
        gacha = Gacha("YT rain sound video", "You had a short nap hp+5", 2, 5);
        currentDoro.setGacha(gacha);
    }
    else if (item == 4){
        gacha = Gacha("Aventurine's Coin", "A merch you bought online atk+10", 1, 10);
        currentDoro.setGacha(gacha);
    }

    if (currentDoro.getGacha()->getStatBoosted()==1){
        currentDoro.setCurrentAtk(currentDoro.getBaseAtk()+currentDoro.getGacha()->getAmountBoosted());
    }
    else if (currentDoro.getGacha()->getStatBoosted()==2){
        currentDoro.setCurrentHp(currentDoro.getCurrentHp()+currentDoro.getGacha()->getAmountBoosted());
        if(currentDoro.getCurrentHp()>currentDoro.getBaseHp())
            currentDoro.setCurrentHp(currentDoro.getBaseHp());
    }
    else if (currentDoro.getGacha()->getStatBoosted()==3){
        currentDoro.setCurrentSpd(currentDoro.getBaseSpd()+currentDoro.getGacha()->getAmountBoosted());
    }
}

//sets player move to dead if theyre dead during the turn order
void Doromon::setDeath(){
    move == "Dead";
}


/*
For sorting the doromons into a priority queue 

Checks the string of the move (like how we search a dictionary)
Order it gets put into the queue:
    aSupport (first priority)
    aNothing (first priority)
    bAttack (second priority)
    cGacha (third priority)

If the same checks speed

A seperate conditional statement for aSupport and aNothing 
As both support or nothing first letter start with a, the second letters will get check if it doesnt have another conditional statement

*/
bool Doromon::operator<(const Doromon &prev)const{

    if ((this->move == "aSupport" && prev.move == "aNothing")||(this->move == "aNothing" && prev.move == "aSupport"))
        return this->currentSpd < prev.currentSpd;
    else if (this->move == prev.move)
        return this->currentSpd < prev.currentSpd;
    else
        return this->move > prev.move;
}

// Setter and Getters
string Doromon::getName(){
    return name;
}

int Doromon::getIndex(){
    return index;
}

void Doromon::setBaseAtk(int atk){
    this->baseAtk = atk;
}

int Doromon::getBaseAtk(){
    return baseAtk;
}

void Doromon::setCurrentAtk(int atk){
    this->currentAtk = atk;
}

int Doromon::getCurrentAtk(){
    return currentAtk;
}

void Doromon::setBaseHp(int hp){
    this->baseHp = hp;
}

int Doromon::getBaseHp(){
    return baseHp;
}

void Doromon::setCurrentHp(int hp){
    this->currentHp = hp;
}

int Doromon::getCurrentHp(){
    return currentHp;
}

void Doromon::setBaseSpd(int spd){
    this->baseSpd = spd;
}

int Doromon::getBaseSpd(){
    return baseSpd;
}

void Doromon::setCurrentSpd(int spd){
    this->currentSpd = spd;
}

int Doromon::getCurrentSpd(){
    return currentSpd;
}

void Doromon::setMove(string move){
    this->move = move;
}

string Doromon::getMove(){
    return move;
}

void Doromon::setSkillIndex(int index){
    this->skillIndex = index;
}

int Doromon::getSkillIndex(){
    return skillIndex;
}

void Doromon::setAtkSkill(int index, Attack* atk){
    this->atkSkills[index] = *atk;
}

Attack* Doromon::getAtkSkill(int index){
    return &atkSkills[index];
}

void Doromon::setSupportSkill(int index, Support* support){
    this->supportSkills[index] = *support;
}

Support* Doromon::getSupportSkill(int index){
    return &supportSkills[index];
}

void Doromon::setGacha(Gacha gacha){
    this->gacha = gacha;
}

Gacha* Doromon::getGacha(){
    return &gacha;
}

void Doromon::setDealth(int Dealth){
    this->dealth = Dealth;
}

int Doromon::getDeatlth(){
    return dealth;
}

void Doromon::setTarget(int Target){
    this->target = Target;
}

int Doromon::getTarget(){
    return target;
}

void Doromon::setSuccessMove(bool success){
    this->successMove = success;
}

bool Doromon::getSuccessMove(){
    return successMove;
}
void Doromon::setDead(int dead){
    this->deadWhileMove = dead;
}

int Doromon::getDead(){
    return deadWhileMove;
}