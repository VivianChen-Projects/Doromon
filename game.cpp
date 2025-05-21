#include "game.h"

/*
Initializes the game
Include:
    initialization of player and enemy doromon
    New Game:
        randomizes skill and stats
        skill randomizer is called for skill
    Load:
        load calls the load function
    
*/
void Game::initializeGame(int menu, Game* start){
   
    if(menu == 1){

        random_device stat;
        uniform_int_distribution<int> randStat(50,75);

        Gacha gacha = Gacha("Nothing", "None Equipped", 0, 0);
        Attack atkDefault = Attack("Default", 0.00, 0, 0);
        Support supportDefault = Support("Default", 0.00, 0, 0);

        Doromon playerDoro1 = Doromon("Player Doro1", 1, randStat(stat), 75, randStat(stat), &atkDefault, &supportDefault, gacha);
        Doromon playerDoro2 = Doromon("Player Doro2", 2, randStat(stat), 75, randStat(stat), &atkDefault, &supportDefault, gacha);
        Doromon enemyDoro1 = Doromon("Enemy Doro1", 3, randStat(stat), 100, randStat(stat), &atkDefault, &supportDefault, gacha);
        Doromon enemyDoro2 = Doromon("Enemy Doro2", 4, randStat(stat), 100, randStat(stat), &atkDefault, &supportDefault, gacha);


        for (int i = 0; i < 3; i++){
            randomizeSkill(i, &playerDoro1);
            randomizeSkill(i, &playerDoro2);
            randomizeSkill(i, &enemyDoro1);
            randomizeSkill(i, &enemyDoro2);
            
        }

        Doromon* Doro[4];
        Doro[0] = &playerDoro1;
        Doro[1] = &playerDoro2;
        Doro[2] = &enemyDoro1;
        Doro[3] = &enemyDoro2;

        start->setDoro(Doro);
    }  

    else if (menu == 2){
        loadData(start);
    }

}

/*
Randomizes Skill
Includes:
    Checks if skill duplicate 
        if not, initialize that skill in the specified index
*/
void Game::randomizeSkill(int index, Doromon* doro){

    random_device skill;
    uniform_int_distribution<int> randskill(1,4);
    int end = 0;

    while (end != 1){
        int random = randskill(skill);
        if (random==1){
            for (int check = 0; check < 3; check ++){

            }
            if(doro->getSupportSkill(0)->getName() =="Warm Cocoa" || doro->getSupportSkill(1)->getName() =="Warm Cocoa" || doro->getSupportSkill(2)->getName() == "Warm Cocoa")
                end = 0;
            else{
                Support WeakHeal = Support("Warm Cocoa", 0.75, 20, 30);
                doro->setSupportSkill(index, &WeakHeal);
                end ++;
            }
        }
        else if (random==2){
            if(doro->getSupportSkill(0)->getName() =="Sweet Madame" || doro->getSupportSkill(1)->getName() =="Sweet Madame" || doro->getSupportSkill(2)->getName() =="Sweet Madame")
                end = 0;
            else{
                Support MidHeal = Support("Sweet Madame", 0.70, 15, 60);
                doro->setSupportSkill(index, &MidHeal);
                end ++;
            }
        }
        else if (random==3){
            if(doro->getSupportSkill(0)->getName() =="Karaoke Time" || doro->getSupportSkill(1)->getName() =="Karaoke Time" || doro->getSupportSkill(2)->getName() =="Karaoke Time")
                end = 0;
            else{
                Support StrongHeal = Support("Karaoke Time", 0.65, 10, 90);
                doro->setSupportSkill(index, &StrongHeal);
                end ++;
            }
        }
        else if (random==4){
            if(doro->getSupportSkill(0)->getName() =="BL Recommendation Session" || doro->getSupportSkill(1)->getName() =="BL Recommendation Session" || doro->getSupportSkill(2)->getName() =="BL Recommendation Session")
                end = 0;
            else{
                Support OPHeal = Support("BL Recommendation Session", 0.50, 5, 140);
                doro->setSupportSkill(index, &OPHeal);
                end ++;
            }
        }
    }

    end = 0; 

    while (end != 1){
        int random = randskill(skill);
        if (random==1){
            if(doro->getAtkSkill(0)->getName() =="Pillow Fight" || doro->getAtkSkill(1)->getName() =="Pillow Fight" || doro->getAtkSkill(2)->getName() == "Pillow Fight")
                end = 0;
            else{
                Attack WeakAttack = Attack("Pillow Fight", 0.75, 20, 30);
                doro->setAtkSkill(index, &WeakAttack);
                end ++;
            }
        }
        else if (random==2){
            if(doro->getAtkSkill(0)->getName() =="Egg in Microwave" || doro->getAtkSkill(1)->getName() =="Egg in Microwave" || doro->getAtkSkill(2)->getName() == "Egg in Microwave")
                end = 0;
            else{
                Attack MidAttack = Attack("Egg in Microwave", 0.70, 15, 60);
                doro->setAtkSkill(index, &MidAttack);
                end ++;
            }
        }
        else if (random==3){
            if(doro->getAtkSkill(0)->getName() =="Coke with Mentos" || doro->getAtkSkill(1)->getName() =="Coke with Mentos" || doro->getAtkSkill(2)->getName() == "Coke with Mentos")
                end = 0;
            else{
                Attack StrongAttack = Attack("Coke with Mentos", 0.65, 10, 90);
                doro->setAtkSkill(index, &StrongAttack);
                end ++;
            }
        }
        else if (random==4){
            if(doro->getAtkSkill(0)->getName() =="Trauma Dump" || doro->getAtkSkill(1)->getName() =="Trauma Dump" || doro->getAtkSkill(2)->getName() == "Trauma Dump")
                end = 0;
            else{
                Attack OPAttack = Attack("Trauma Dump", 0.50, 5, 140);
                doro->setAtkSkill(index, &OPAttack);
                end ++;
            }
        }
    }
}

/*
Sets Player Move Action
Include:
    checks if doro is dead to set move to Dead
    randomizes enemy move and skill index
*/
void Game::setPlayerMove(int index, Game* doromon, int playerMove){
    random_device move;
    uniform_int_distribution<int> randMove(1,11);
    uniform_int_distribution<int> randSkillIndex(0,2);
    
    int moveChoice = 0;
    int skillIndex = 0;
    int stop = 0;

    for (int i = 0; i < 2; i++){
        moveChoice = randMove(move);
        if (doromon->getDoro(i+2)->getCurrentHp() > 0){
            if (moveChoice == 1 ||moveChoice == 2||moveChoice == 3||moveChoice == 4){
                doromon->getDoro(i+2)->setMove("bAttack");
                while (stop != 1){
                    skillIndex = randSkillIndex(move);
                    if (doromon->getDoro(i+2)->getAtkSkill(skillIndex)->getCurrentCount() > 0){
                        doromon->getDoro(i+2)->setSkillIndex(skillIndex);
                        doromon->getDoro(i+2)->getAtkSkill(skillIndex)->setCurrentCount(doromon->getDoro(i+2)->getAtkSkill(skillIndex)->getCurrentCount()-1);
                        stop++;
                    }
                }
                
            }
            else if (moveChoice == 5||moveChoice == 6||moveChoice == 7||moveChoice == 8){
                doromon->getDoro(i+2)->setMove("aSupport");
                while (stop != 1){
                    skillIndex = randSkillIndex(move);
                    if (doromon->getDoro(i+2)->getSupportSkill(skillIndex)->getCurrentCount() > 0){
                        doromon->getDoro(i+2)->setSkillIndex(skillIndex);
                        doromon->getDoro(i+2)->getSupportSkill(skillIndex)->setCurrentCount(doromon->getDoro(i+2)->getSupportSkill(skillIndex)->getCurrentCount()-1);
                        stop++;
                    }
                }
            }
            else if (moveChoice == 9 ||moveChoice == 10)
                doromon->getDoro(i+2)->setMove("cGacha");
            else if (moveChoice == 11)
                doromon->getDoro(i+2)->setMove("aNothing");
        }
        else
            doromon->getDoro(i+2)->setMove("Dead");
        stop = 0;
    }
    
    if(doromon->getDoro(index)->getCurrentHp() <= 0){
        doromon->getDoro(index)->setMove("Dead");
    }
    else{

        if (playerMove == 1)
            doromon->getDoro(index)->setMove("bAttack");
        else if (playerMove == 2)
            doromon->getDoro(index)->setMove("aSupport");
        else if (playerMove == 3)
            doromon->getDoro(index)->setMove("cGacha");
        else if (playerMove == 4)
            doromon->getDoro(index)->setMove("aNothing");
    }

}

/*
Set the skill the Doromon took
Include:
    setting which skill index the player choose to do
*/
void Game::setSkillInput(int index, Game* doromon, int move){
    int skillIndex;

    if(doromon->getDoro(index)->getMove()=="bAttack"){
                
        if (move == '1'){
            skillIndex = 0;
        }
        else if (move == '2'){
            skillIndex = 1;
        }
        else if (move == '3'){
            skillIndex = 2;
        }
        else if (move == '4'){
            skillIndex = 3;
        }
    }

    else if (doromon->getDoro(index)->getMove()== "aSupport"){
        if (move == '1'){
            skillIndex = 0;
        }
        else if (move == '2'){
            skillIndex = 1;
        }
        else if (move == '3'){
            skillIndex = 2;
        }
        else if (move == '4'){
            skillIndex = 3;
        }
    }

    else if (doromon->getDoro(index)->getMove()== "cGacha"){
        if (move == '1'){
            skillIndex = 0;
        }
        else if (move == '4'){
            skillIndex = 3;
        }
    }

    else if (doromon->getDoro(index)->getMove()== "aNothing"){
        if (move == '1'){
            skillIndex = 0;
        }
        else if (move == '4'){
            skillIndex = 3;
        }               
    }
    doromon->getDoro(index)->setSkillIndex(skillIndex);
}

/*
Check the skill's count
    if skill has 0 count return true
    if skill has count, sets the new count,sets the final skill index the player choose, and return false
*/
bool Game::checkCount(int index, Game* doromon, int skillIndex){
    skillIndex --; 
    if(doromon->getDoro(index)->getMove() == "bAttack"){
        if (doromon->getDoro(index)->getAtkSkill(skillIndex)->getCurrentCount() > 0){
            doromon->getDoro(index)->setSkillIndex(skillIndex);
            doromon->getDoro(index)->getAtkSkill(skillIndex)->setCurrentCount(doromon->getDoro(index)->getAtkSkill(skillIndex)->getCurrentCount()-1);
            return false;
        }
        else
            return true;
    }
    else if(doromon->getDoro(index)->getMove() == "aSupport") {
        if (doromon->getDoro(index)->getSupportSkill(skillIndex)->getCurrentCount() > 0){
            doromon->getDoro(index)->setSkillIndex(skillIndex);
            doromon->getDoro(index)->getSupportSkill(skillIndex)->setCurrentCount(doromon->getDoro(index)->getSupportSkill(skillIndex)->getCurrentCount()-1);
            return false;
        }
        else
            return true;
    } 
    else    return false;

}

/*
Arrange all doro moves
Includes:
    priority queue to check which doromon goes first
    then sets the priority queue in Game
*/
void Game::proccessTurnOrder(Game* doromon){
    priority_queue<Doromon*, vector<Doromon*>, DoromonComparator> order;
    for (int i=0; i<4; i++){
        order.push(&doromon->Doro[i]);
    }

    setQueue(order);
}

/*
Process all doro moves
Includes:
    Randomize target
    process/do the move the current doro chose
*/
void Game::proccessDoroMoves(Game* doromon, Doromon* currentDoro){
    random_device select;
    uniform_int_distribution<int> randomAlly(0,1);
    uniform_int_distribution<int> randomEnemy(2,3);
    int hit;

    if((currentDoro->getIndex() == 1 ||currentDoro->getIndex() == 2) && doromon->getDoro(2)->getCurrentHp() > 0 && doromon->getDoro(3)->getCurrentHp() > 0)
        hit = randomEnemy(select);
    else if ((currentDoro->getIndex() == 1 ||currentDoro->getIndex() == 2) && doromon->getDoro(2)->getCurrentHp() > 0 && doromon->getDoro(3)->getCurrentHp() <= 0)
        hit = 2;
    else if ((currentDoro->getIndex() == 1 ||currentDoro->getIndex() == 2) && doromon->getDoro(2)->getCurrentHp() <= 0 && doromon->getDoro(3)->getCurrentHp() > 0)
        hit = 3;
    else if ((currentDoro->getIndex() == 3 ||currentDoro->getIndex() == 4)&& doromon->getDoro(0)->getCurrentHp() > 0 && doromon->getDoro(1)->getCurrentHp() > 0)
        hit = randomAlly(select);
    else if ((currentDoro->getIndex() == 3 ||currentDoro->getIndex() == 4) && doromon->getDoro(0)->getCurrentHp() > 0 && doromon->getDoro(1)->getCurrentHp() <= 0)
        hit = 0;
    else if ((currentDoro->getIndex() == 3 ||currentDoro->getIndex() == 4) && doromon->getDoro(0)->getCurrentHp() <= 0 && doromon->getDoro(1)->getCurrentHp() > 0)
        hit = 1;
    
    if (currentDoro->getIndex() == 1){
        if (doromon->getDoro(0)->getCurrentHp() > 0){
            if(doromon->getDoro(0)->getMove() == "aSupport"){
                hit = 0;
                doromon->getDoro(0)->setTarget(hit);
                doromon->getDoro(0)->useSupport(doromon->Doro[0], doromon->Doro[hit]);
            }
            else if(doromon->getDoro(0)->getMove() == "bAttack"){
                doromon->getDoro(0)->setTarget(hit);
                doromon->getDoro(0)->useAttack(doromon->Doro[0], doromon->Doro[hit]);
            }
            else if(doromon->getDoro(0)->getMove() == "cGacha"){
                doromon->getDoro(0)->useGacha(doromon->Doro[0]);
            }
        }
        else {
            if(doromon->getDoro(0)->getDead() == 0)
                doromon->getDoro(0)->setMove("died");
            else if (doromon->getDoro(0)->getDead() == 1)
                doromon->getDoro(0)->setMove("Dead");

            doromon->getDoro(0)->setDead(1);
        }
    }
    else if (currentDoro->getIndex() == 2){
        if (doromon->getDoro(1)->getCurrentHp() > 0){
            if(doromon->getDoro(1)->getMove() == "aSupport"){
                hit = 1;
                doromon->getDoro(1)->setTarget(hit);
                doromon->getDoro(1)->useSupport(doromon->Doro[1], doromon->Doro[hit]);
            }
            else if(doromon->getDoro(1)->getMove() == "bAttack"){
                doromon->getDoro(1)->setTarget(hit);
                doromon->getDoro(1)->useAttack(doromon->Doro[1], doromon->Doro[hit]);
            }
            else if(doromon->getDoro(1)->getMove() == "cGacha"){
                doromon->getDoro(1)->useGacha(doromon->Doro[1]);
            }
        } 
        else {
            if(doromon->getDoro(1)->getDead() == 0)
                doromon->getDoro(1)->setMove("died");
            else if (doromon->getDoro(1)->getDead() == 1)
                doromon->getDoro(1)->setMove("Dead");
                
            doromon->getDoro(1)->setDead(1);
        }
    }
    else if (currentDoro->getIndex() == 3){
        if (doromon->getDoro(2)->getCurrentHp() > 0){
            if(doromon->getDoro(2)->getMove() == "aSupport"){
                hit = 2;
                doromon->getDoro(2)->setTarget(hit);
                doromon->getDoro(2)->useSupport(doromon->Doro[2], doromon->Doro[hit]);
            }
            else if(doromon->getDoro(2)->getMove() == "bAttack"){
                doromon->getDoro(2)->setTarget(hit);
                doromon->getDoro(2)->useAttack(doromon->Doro[2], doromon->Doro[hit]);
            }
            else if(doromon->getDoro(2)->getMove() == "cGacha"){
                doromon->getDoro(2)->useGacha(doromon->Doro[2]);
            }
        }
        else {
            if(doromon->getDoro(2)->getDead() == 0)
                doromon->getDoro(2)->setMove("died");
            else if (doromon->getDoro(2)->getDead() == 1)
                doromon->getDoro(2)->setMove("Dead");
                
            doromon->getDoro(2)->setDead(1);
        }
    }
    else if (currentDoro->getIndex() == 4){
        if (doromon->getDoro(3)->getCurrentHp() > 0){
            if(doromon->getDoro(3)->getMove() == "aSupport"){
                hit = 3;
                doromon->getDoro(3)->setTarget(hit);
                doromon->getDoro(3)->useSupport(doromon->Doro[3], doromon->Doro[hit]);
            }
            else if(doromon->getDoro(3)->getMove() == "bAttack"){
                doromon->getDoro(3)->setTarget(hit);
                doromon->getDoro(3)->useAttack(doromon->Doro[3], doromon->Doro[hit]);
            }
            else if(doromon->getDoro(3)->getMove() == "cGacha"){
                doromon->getDoro(3)->useGacha(doromon->Doro[3]);
            }
        }
        else {
            if(doromon->getDoro(3)->getDead() == 0)
                doromon->getDoro(3)->setMove("died");
            else if (doromon->getDoro(3)->getDead() == 1)
                doromon->getDoro(3)->setMove("Dead");
                
            doromon->getDoro(3)->setDead(1);
        }
    }
}

/*
Check Save input
Includes:
    if player saved or continue, return false
        if player saved then calls save function
        if not does nothing
    otherwise return true
*/
bool Game::confirmSave(Game* start, int save){
    if(save == 1){
        start->saveData(start);
        start->setRun(false);
        return false;
    }
    else if (save == 4){
        return false;
    }
    else
        return true;
}

/*
Saves the Data of the game
Saves:
    Game:
        turn
    doromon:
        doromon index, name, current and base hp, current and base stk, current and base spd
    skill:
        doromon index, 1 or 2 (1-atk, 2-sup), skill index, name, power/heal, accuracy, current and base count
    item:
        doromon index, name, description, stat boosted, amount boosted
*/
void Game::saveData(Game* start){

    ofstream game("CSV/game.csv");
    game << start->getTurn()+1 << ","  <<start->getWinner();
    game.close();

    ofstream doromon("CSV/doromon.csv");
    for (int i = 0; i < 4; i++){
    doromon << start->getDoro(i)->getIndex() << ",";
    doromon << start->getDoro(i)->getName() << ",";
    doromon << start->getDoro(i)->getCurrentHp() << ",";
    doromon << start->getDoro(i)->getBaseHp() << ",";
    doromon << start->getDoro(i)->getCurrentAtk() << ",";
    doromon << start->getDoro(i)->getBaseAtk() << ",";
    doromon << start->getDoro(i)->getCurrentSpd() << ",";
    doromon << start->getDoro(i)->getBaseSpd() << ",";
    doromon << start->getDoro(i)->getDead();
    doromon <<endl;
    }
    doromon.close();

    ofstream skill("CSV/skill.csv");
    for (int i = 0; i < 4; i++){
        for (int j =0; j < 3; j++){
            skill << start->getDoro(i)->getIndex() << ",1," << j <<",";
            skill << start->getDoro(i)->getAtkSkill(j)->getName() << ",";
            skill << start->getDoro(i)->getAtkSkill(j)->getPower() << ",";
            skill << start->getDoro(i)->getAtkSkill(j)->getAccuracy() << ",";
            skill << start->getDoro(i)->getAtkSkill(j)->getCurrentCount() << ",";
            skill << start->getDoro(i)->getAtkSkill(j)->getBaseCount();
            skill <<endl;
        }
        for (int j =0; j < 3; j++){
            skill << start->getDoro(i)->getIndex() << ",2," << j <<",";
            skill << start->getDoro(i)->getSupportSkill(j)->getName() << ",";
            skill << start->getDoro(i)->getSupportSkill(j)->getHeal() << ",";
            skill << start->getDoro(i)->getSupportSkill(j)->getAccuracy() << ",";
            skill << start->getDoro(i)->getSupportSkill(j)->getCurrentCount() << ",";
            skill << start->getDoro(i)->getSupportSkill(j)->getBaseCount();
            skill <<endl;
        }
    }
    skill.close();

    ofstream item("CSV/item.csv");
    for(int i = 0; i < 4; i ++){
        item << start->getDoro(i)->getIndex() << "," ;
        item << start->getDoro(i)->getGacha()->getName() << ",";
        item << start->getDoro(i)->getGacha()->getDescription() << ",";
        item << start->getDoro(i)->getGacha()->getStatBoosted() << ",";
        item << start->getDoro(i)->getGacha()->getAmountBoosted();
        item << endl;
    }
    item.close();
}

/*
Loads the data from all CSV if player chose to load
*/
void Game::loadData(Game* start){

    //Defaults

    Gacha gachaDefault = Gacha("Nothing", "None Equipped", 0, 0);
    Attack atkDefault = Attack("Default", 0.00, 0, 0);
    Support supportDefault = Support("Default", 0.00, 0, 0);

    Doromon tempAllDoro[4];
    Doromon* finalDoro[4];

    //Containers for later use

    Attack atk1[3];
    Attack atk2[3];
    Attack atk3[3];
    Attack atk4[3];
    Support sup1[3];
    Support sup2[3];
    Support sup3[3];
    Support sup4[3];

    Gacha allItems[4];

    //open game csv, get and set turn number
    ifstream game("CSV/game.csv");
    stringstream gameBuffer;
    gameBuffer << game.rdbuf();
    string allGame = gameBuffer.str();
    
    vector<string> allGameLines;
    string gameLines;

    while(getline(gameBuffer, gameLines, '\n')){
        allGameLines.push_back(gameLines);
    }

    int turn;
    int winner;

    string txt;

    for (int i = 0; i < (int)allGameLines.size(); i++){
        
        stringstream lineBuffer(allGameLines[i]);
        int column=0;

        while(getline(lineBuffer, txt, ',')){
            switch(column){
                case 0:
                    turn = stoi(txt);
                    column++;
                    break;
                    break;
                case 1:
                    winner = stoi(txt);
                    column++;
                    break;
            }
        }
        start->setTurn(turn);
        start->setWinner(winner);
    }
    game.close();

    //open skill csv
    ifstream skill("CSV/skill.csv");
    stringstream skillBuffer;
    skillBuffer << skill.rdbuf();
    string allSkill = skillBuffer.str();

    vector<string> allSkillLines;
    string skillLines;

    while(getline(skillBuffer, skillLines, '\n')){
        allSkillLines.push_back(skillLines);
    }

    int doroIndex;
    int skillType;
    int skillIndex;
    string skillName;
    int power;
    float accuracy;
    int c_count;
    int b_count;

    for (int i = 0; i < (int)allSkillLines.size(); i++){
        
        stringstream lineBuffer(allSkillLines[i]);
        int column=0;

        while(getline(lineBuffer, txt, ',')){
            switch(column){
                case 0:
                    doroIndex = stoi(txt);
                    column++;
                    break;
                case 1:
                    skillType = stoi(txt);
                    column++;
                    break;
                case 2:
                    skillIndex = stoi(txt);
                    column++;
                    break;
                case 3:
                    skillName = txt;
                    column++;
                    break;
                case 4:
                    power = stoi(txt);
                    column++;
                    break;
                case 5:
                    accuracy = stof(txt);
                    column++;
                    break;
                case 6:
                    c_count = stoi(txt);
                    column++;
                    break;
                case 7:
                    b_count = stoi(txt);
                    column++;
                    break;
                
            }
        }
        //checks skill type if 1 - atk, if 2 - support
        if(skillType == 1){
            Attack atk = Attack(skillName, accuracy, c_count, b_count, power);
            //checks which doro has that skill then set it in one of the arrays for that doromon
            switch(doroIndex){
                case 1:
                    atk1[skillIndex] = atk;
                    break;
                case 2:
                    atk2[skillIndex] = atk;
                    break;
                case 3:
                    atk3[skillIndex] = atk;
                    break;
                case 4:
                    atk4[skillIndex] = atk;
                    break;
            }
        }
        else if (skillType == 2){
            Support sup = Support(skillName, accuracy, c_count, b_count, power);
            switch(doroIndex){
                case 1:
                    sup1[skillIndex] = sup;
                    break;
                case 2:
                    sup2[skillIndex] = sup;
                    break;
                case 3:
                    sup3[skillIndex] = sup;
                    break;
                case 4:
                    sup4[skillIndex] = sup;
                    break;
            }
        }
    }

    skill.close();

    //open gacha csv and input all item into one array
    ifstream gacha("CSV/item.csv");
    stringstream gachaBuffer;
    gachaBuffer << gacha.rdbuf();
    string allGacha = gachaBuffer.str();

    vector<string> allGachaLines;
    string gachaLines;

    while(getline(gachaBuffer, gachaLines, '\n')){
        allGachaLines.push_back(gachaLines);
    }

    string gachaName;
    string description;
    int statBoosted;
    int amountBoosted;

    for (int i = 0; i < (int)allGachaLines.size(); i++){
        
        stringstream lineBuffer(allGachaLines[i]);
        int column=0;

        while(getline(lineBuffer, txt, ',')){
            switch(column){
                case 0:
                    doroIndex = stoi(txt);
                    column++;
                    break;
                case 1:
                    gachaName = txt;
                    column++;
                    break;
                case 2:
                    description = txt;
                    column++;
                    break;
                case 3:
                    statBoosted = stoi(txt);
                    column++;
                    break;
                case 4:
                    amountBoosted = stoi(txt);
                    column++;
                    break;
            }
        }
        
        Gacha item = Gacha(gachaName, description, statBoosted, amountBoosted);
        allItems[doroIndex-1] = item;
    }
    gacha.close();

    //open doromon csv and stores all into a temp doromon array
    ifstream doromon("CSV/doromon.csv");
    stringstream doroBuffer;
    doroBuffer << doromon.rdbuf();
    string allDoromon = doroBuffer.str();

    vector<string> allDoromonLines;
    string doromonLines;

    while(getline(doroBuffer, doromonLines, '\n')){
        allDoromonLines.push_back(doromonLines);
    }

    string doroName;
    int c_hp;
    int b_hp;
    int c_atk;
    int b_atk;
    int c_spd;
    int b_spd;
    int dead;

    for (int i = 0; i < (int)allDoromonLines.size(); i++){
        
        stringstream lineBuffer(allDoromonLines[i]);
        int column=0;

        while(getline(lineBuffer, txt, ',')){
            switch(column){
                case 0:
                    doroIndex = stoi(txt);
                    column++;
                    break;
                case 1:
                    doroName = txt;
                    column++;
                    break;
                case 2:
                    c_hp = stoi(txt);
                    column++;
                    break;
                case 3:
                    b_hp = stoi(txt);
                    column++;
                    break;
                case 4:
                    c_atk = stoi(txt);
                    column++;
                    break;
                case 5:
                    b_atk = stoi(txt);
                    column++;
                    break;
                case 6:
                    c_spd = stoi(txt);
                    column++;
                    break;
                case 7:
                    b_spd = stoi(txt);
                    column++;
                    break;
                 case 8:
                    dead = stoi(txt);
                    column++;
                    break;
            }
        }
        
        Doromon doro = Doromon(doroName, doroIndex, b_atk, b_hp, b_spd, c_atk, c_hp, c_spd, dead, &atkDefault, &supportDefault, gachaDefault);
        
        tempAllDoro[doroIndex-1] = doro;
    }

    doromon.close();

    //set atk and sup skill of all doromon
    for(int i = 0; i < 3; i++){
        tempAllDoro[0].setAtkSkill(i, &atk1[i]);
        tempAllDoro[1].setAtkSkill(i, &atk2[i]);
        tempAllDoro[2].setAtkSkill(i, &atk3[i]);
        tempAllDoro[3].setAtkSkill(i, &atk4[i]);

        tempAllDoro[0].setSupportSkill(i, &sup1[i]);
        tempAllDoro[1].setSupportSkill(i, &sup2[i]);
        tempAllDoro[2].setSupportSkill(i, &sup3[i]);
        tempAllDoro[3].setSupportSkill(i, &sup4[i]);

    }

    for(int i = 0; i < 4; i++){
        tempAllDoro[i].setGacha(allItems[i]);
    }

    //copies the data of temp array into the final array
    finalDoro[0] = &tempAllDoro[0];
    finalDoro[1] = &tempAllDoro[1];
    finalDoro[2] = &tempAllDoro[2];
    finalDoro[3] = &tempAllDoro[3];

    start->setDoro(finalDoro);
}

/*
Checks winning condition
Includes: 
    checking hp and returns 1 if player won, 2 if enemy won, 3 if no winner
*/
void Game::checkWinningCondition(Game* doromon){
    if (doromon->getDoro(0)->getCurrentHp()==0 && doromon->getDoro(1)->getCurrentHp()==0){
        doromon->setRun(false);
        doromon->setWinner(2);
    }
    else if (doromon->getDoro(2)->getCurrentHp()==0 && doromon->getDoro(3)->getCurrentHp()==0){
        doromon->setRun(false);
        doromon->setWinner(1);
    }
}


//Setters and Getters
void Game::setDoro(Doromon *doro[]){
    for (int i=0; i<4; i++){
        this->Doro[i] = *doro[i];
    }
}

Doromon* Game::getDoro(int index){
    return &Doro[index];
}

void Game::setTurn(int turn){
    this->turn = turn;
}

int Game::getTurn(){
    return turn;
}

void Game::setRun(bool end){
    this->run = end;
}

bool Game::getRun(){
    return run;
}

void Game::setInitialized(bool initialize){
    this->initialized = initialize;
}

bool Game::getInitialized(){
    return initialized;
}

void Game::setWinner(int Winner){
    this->winner = Winner;
}

int Game::getWinner(){
    return winner;
}

void Game::setQueue(priority_queue<Doromon*, vector<Doromon*>, DoromonComparator> TurnOrder){
    this->turnOrder = TurnOrder;
}

priority_queue<Doromon*, vector<Doromon*>, DoromonComparator>*  Game::getQueue(){
    return &turnOrder;
}
