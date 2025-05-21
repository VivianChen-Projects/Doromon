#include "winnerScreen.h"

//display winner
void WinnerScreen::displayWinner(Game* doromon){
    
    cout  << endl << "---------------------------------------" << endl;
    cout << endl << "Finished Game in " << doromon->getTurn()+1 <<" Turns" << endl;
    if (doromon->getWinner() == 1)
        cout <<"Congratulation! Player Wins!" << endl;
    else if (doromon->getWinner() == 2)
        cout <<"Unfortunately, Enemy Wins" << endl;
    cout << "---------------------------------------";
    cout << endl << "Made by: Vivian Angel H. Chen" << endl << "Submitted to: Sir JR Cala";
}