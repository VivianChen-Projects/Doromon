#include "orderScreen.h"

//display the order of doromon by popping queue
void OrderScreen::displayOrder(Game* start){

    Doromon* currentDoro;
    
    while (!start->getQueue()->empty()) {
        currentDoro = start->getQueue()->top();
        start->getQueue()->pop();
        cout << currentDoro->getName() <<": " <<currentDoro->getMove()<< " | Atk of Doromon: " << currentDoro->getCurrentAtk() << " | Speed of Doromon: " << currentDoro->getCurrentSpd() << endl;
    }
    cout <<"---------------------------------------" << endl;
}

//ask the user if they want to save or continue
void OrderScreen::askSave(){
    cout << endl <<"---------------------------------------" << endl;
    cout << "Would You Like to Save?" << endl;
    cout << "1) Save and Exit" << endl << "4) Continue " << endl << "Select: ";
}