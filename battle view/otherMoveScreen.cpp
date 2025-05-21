#include "otherMoveScreen.h"

//display when player did not choose atk and sup
void OtherMoveScreen::displayOther(Doromon currentDoro){
    
    if (currentDoro.getMove()=="aNothing"){
        cout << currentDoro.getName() <<" Did Nothing " << endl << endl;
    }
    else if (currentDoro.getMove()=="cGacha"){
        cout << currentDoro.getName() << " Spinned Gacha And Got ";
        cout << currentDoro.getGacha()->getName() << endl << endl;
    }
    //display when doromon died in the middle of the turn order
    else if(currentDoro.getMove()=="died"){
        cout << currentDoro.getName() << " Died Before Being Able To Perform Move " << endl << endl;
    }
    //display when doromon is dead
    else if(currentDoro.getMove()=="Dead"){
        cout << currentDoro.getName() << " is Dead " << endl << endl;
    }
}