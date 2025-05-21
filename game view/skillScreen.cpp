#include "skillScreen.h"

//display skills available when skill is used
//display confirm for gacha and nothing
void SkillScreen::displaySkill(int index, Game* doromon){
if (doromon->getDoro(index)->getMove()== "bAttack"){
        cout << endl ;
        cout <<"---------------------------------------" << endl;
        for ( int i = 0; i < 3; i ++){
            cout << i+1 << ") " << doromon->getDoro(index)->getAtkSkill(i)->getName() << "    " << doromon->getDoro(index)->getAtkSkill(i)->getCurrentCount() << "/" << doromon->getDoro(index)->getAtkSkill(i)->getBaseCount() << "    " 
            << doromon->getDoro(index)->getAtkSkill(i)->getAccuracy()*100 <<"%" << "    Power: "<< doromon->getDoro(index)->getAtkSkill(i)->getPower() << endl;
        }
        cout << "4) Back" << endl;
        cout <<"---------------------------------------" << endl;
        cout << "Pick a Move: ";
    }

else if (doromon->getDoro(index)->getMove()== "aSupport"){
    cout << endl ;
    cout <<"---------------------------------------" << endl;
    for ( int i = 0; i < 3; i ++){
        cout << i+1 << ") " << doromon->getDoro(index)->getSupportSkill(i)->getName() << "    " << doromon->getDoro(index)->getSupportSkill(i)->getCurrentCount() << "/" << doromon->getDoro(index)->getSupportSkill(i)->getBaseCount() << "    " 
        << doromon->getDoro(index)->getSupportSkill(i)->getAccuracy()*100 <<"%" << "    Heal: "<< doromon->getDoro(index)->getSupportSkill(i)->getHeal() << endl;
    }
    cout << "4) Back" << endl;
    cout <<"---------------------------------------" << endl;
    cout << "Pick a Move: ";
    }

else if (doromon->getDoro(index)->getMove()== "cGacha"){
    cout << endl ;
    cout <<"---------------------------------------" << endl;
    cout << "1) Confirm" << endl;
    cout << "4) Back" << endl;
    cout <<"---------------------------------------" << endl;
    cout << "Pick a Move: ";
}

else if (doromon->getDoro(index)->getMove()== "aNothing"){
    cout << endl ;
    cout <<"---------------------------------------" << endl;
    cout << "1) Confirm" << endl;
    cout << "4) Back" << endl;
    cout <<"---------------------------------------" << endl;
    cout << "Pick a Move: ";
    }  
}