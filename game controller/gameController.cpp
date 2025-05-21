#include "gameController.h"

//controller for the whole game
void GameController::run(int menu, Game* start){
    
    char moveChoice = '0';
    char skillChoice = '0';
    bool countCheck = true;

    start->setTurn(start->getTurn()+1);

    if(!start->getInitialized()){
        start->initializeGame(menu, start);
        start->setInitialized(true);
    }

    while(gameRunning){
        
        game.displayGame(start);

        //move
        for(int i = 0; i < 2; i++){
            if(start->getDoro(i)->getCurrentHp() > 0){
                while(moveRunning){
                    move.displayMove(i, start);
                    cin >> moveChoice;
                    if (moveChoice=='1'||moveChoice=='2'||moveChoice=='3'||moveChoice=='4'){
                        moveRunning = false;
                        switch (moveChoice){
                            case '1':
                                start->setPlayerMove(i, start, 1);
                                break;
                            case '2':
                                start->setPlayerMove(i, start, 2);
                                break;
                            case '3':
                                start->setPlayerMove(i, start, 3);
                                break;
                            case '4':
                                start->setPlayerMove(i, start, 4);
                                break;
                        }
                        
                        //skill
                        while(skillRunning){
                            while(countCheck){
                                skill.displaySkill(i, start); 
                                cin >> skillChoice;
                                if (skillChoice=='1'||skillChoice=='2'||skillChoice=='3'||skillChoice=='4'){
                                    switch (skillChoice){
                                        case '1':
                                            start->setSkillInput(i, start, 1);
                                            countCheck = start->checkCount(i, start, 1);
                                            if (countCheck){
                                                invalid.noCount();
                                                countCheck = true;
                                            }
                                            else
                                                countCheck = false;
                                            break;
                                        case '2':
                                            start->setSkillInput(i, start, 2);
                                            countCheck = start->checkCount(i, start, 2);
                                            if (countCheck){
                                                invalid.noCount();
                                                countCheck = true;
                                            }
                                            else
                                                countCheck = false;
                                            break;
                                        case '3':
                                            start->setSkillInput(i, start, 3);
                                            countCheck = start->checkCount(i, start, 3);
                                            if (countCheck){
                                                invalid.noCount();
                                                countCheck = true;
                                            }
                                            else
                                                countCheck = false;
                                            break;
                                        case '4':
                                            start->setSkillInput(i, start, 4);
                                            countCheck = false;
                                            i--;
                                            break;
                                        }
                                    }
                                    else
                                        invalid.wrongInputFourChoices();
                                }
                            skillRunning = false;
                            }
                            skillRunning = true;
                            countCheck = true;
                        }
                    else{
                        invalid.wrongInputFourChoices();
                        moveRunning = true;
                    }
                }
            }
            else
                start->getDoro(i)->setDeath();
        moveRunning = true;
        }
    gameRunning = false;
    }
    gameRunning = true;


}

//controller for win screen
void GameController::checkWin(Game* start){
    start->checkWinningCondition(start);
    if (start->getWinner() != 0){
        win.displayWinner(start);
    }
}