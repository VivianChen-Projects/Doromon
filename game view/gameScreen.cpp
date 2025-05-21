#include "gameScreen.h"

//display all doro data and turn order
void GameScreen::displayGame(Game* doromon){

    cout <<"---------------------------------------" << endl;
    cout << "             Turn " << doromon->getTurn() << endl;
    cout << doromon->getDoro(2)->getName() <<"           " <<doromon->getDoro(3)->getName() << endl;
    cout << "HP: " << doromon->getDoro(2)->getCurrentHp() << "/" << doromon->getDoro(2)->getBaseHp() << "           "
    << "HP: " << doromon->getDoro(3)->getCurrentHp() << "/" << doromon->getDoro(3)->getBaseHp() << endl << endl; 
    cout << doromon->getDoro(2)->getName() <<"'s Item: "<< doromon->getDoro(2)->getGacha()->getName()<< endl;
    cout <<"Description: " << doromon->getDoro(2)->getGacha()->getDescription() << endl << endl;
    cout << doromon->getDoro(3)->getName() <<"'s Item: "<< doromon->getDoro(3)->getGacha()->getName()<< endl;
    cout <<"Description: " << doromon->getDoro(3)->getGacha()->getDescription() << endl << endl;

    cout << doromon->getDoro(0)->getName() <<"          " <<doromon->getDoro(1)->getName() << endl;
    cout << "HP: " << doromon->getDoro(0)->getCurrentHp() << "/" << doromon->getDoro(0)->getBaseHp() << "           "
    << "HP: " << doromon->getDoro(1)->getCurrentHp() << "/" << doromon->getDoro(1)->getBaseHp() << endl << endl;
    cout << doromon->getDoro(0)->getName() <<"'s Item: "<< doromon->getDoro(0)->getGacha()->getName() <<endl;
    cout <<"Description: " << doromon->getDoro(0)->getGacha()->getDescription() << endl << endl;
    cout << doromon->getDoro(1)->getName() <<"'s Item: "<< doromon->getDoro(1)->getGacha()->getName()<< endl;
    cout <<"Description: " << doromon->getDoro(1)->getGacha()->getDescription() << endl << endl;
    
}