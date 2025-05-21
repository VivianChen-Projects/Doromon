#include "moveScreen.h"

//display moves
void MoveScreen::displayMove(int index, Game* doromon){
        cout <<"---------------------------------------" << endl;
        cout << endl << doromon->getDoro(index)->getName() << "'s Turn" << endl;
        cout << endl <<"Moves Available" << endl;
        cout << "1) Attack" << endl;
        cout << "2) Support" << endl;
        cout << "3) Gacha" << endl;
        cout << "4) Do Nothing" << endl;
        cout << endl << "Pick a Move: ";
}