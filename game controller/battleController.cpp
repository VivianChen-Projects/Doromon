#include "battleController.h"

//controller for battle
void BattleController::run(Game* start){

    int save = 0;
    Doromon* current;
    start->proccessTurnOrder(start);
    order.displayOrder(start);
    start->proccessTurnOrder(start);

    while(!start->getQueue()->empty()){
        current = start->getQueue()->top();
        int i = current->getIndex()-1;
        start->getQueue()->pop();

        start->proccessDoroMoves(start, current);
        if(current->getMove() == "aSupport" || current->getMove() == "bAttack"){
            if(current->getSuccessMove()){
                useSkill.displaySkillHit(start->getDoro(i), start->getDoro(start->getDoro(i)->getTarget()));
            }
            else if (!current->getSuccessMove())
                useSkill.displaySkillMiss(start->getDoro(i));
        }
        else{
            other.displayOther(*current);
            if (current->getMove() == "died")
                current->setDeath();
        }

        i++;
    }
    while(orderRunning){
        order.askSave();
        cin >> save;
        orderRunning = start->confirmSave(start, save);

    }
    orderRunning = true;

}