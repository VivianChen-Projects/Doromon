#include "useSkillScreen.h"

//display when skill hits the target
void UseSkillScreen::displaySkillHit(Doromon* currentDoro, Doromon* targetDoro){

    int pick = currentDoro->getSkillIndex();

    if (currentDoro->getMove()=="aSupport"){
        cout << currentDoro->getName() <<" Used " << currentDoro->getSupportSkill(pick)->getName() << " On Itself!" << endl;
        cout << currentDoro->getName() <<" Was Healed " << currentDoro->getDeatlth() <<" hp" << endl << endl;
    }
    else if (currentDoro->getMove()=="bAttack"){
        cout << currentDoro->getName() <<" Used " << currentDoro->getAtkSkill(pick)->getName() << " On " << targetDoro->getName();
        cout << endl <<"Dealth " << currentDoro->getDeatlth() <<" to " << targetDoro->getName() << endl << endl;
    }
}

//display when skill missed the target
void UseSkillScreen::displaySkillMiss(Doromon* currentDoro){

    int pick = currentDoro->getSkillIndex();

    if (currentDoro->getMove()=="aSupport"){
        cout << currentDoro->getName() <<" Used " << currentDoro->getSupportSkill(pick)->getName()<< " And Missed Its Heal" << endl << endl;
    }
    else if (currentDoro->getMove()=="bAttack"){
        cout << currentDoro->getName() <<" Used " << currentDoro->getAtkSkill(pick)->getName()<< " And Missed Its Attack" << endl << endl;
    }
}