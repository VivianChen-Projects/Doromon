#include "invalidScreen.h"


//display when choices is not with 1,2,3,4
void InvalidScreen::wrongInputFourChoices(){
    cout <<"---------------------------------------" << endl;
    cout << "Wrong Input. Please Input 1, 2, 3, or 4" << endl;
}

//display when choices is not with 1,4
void InvalidScreen::wrongInputTwoChoices(){
    cout <<"---------------------------------------" << endl;
    cout << "Wrong Input. Please Input 1 or 4 " << endl;
}

//display when skill has no count
void InvalidScreen::noCount(){
    cout <<"---------------------------------------" << endl;
    cout << "Cannot Select Move. Skill performable count is 0" << endl;
}