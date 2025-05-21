#include <iostream>
#include <queue>
#include <random>

#include "game controller/menuController.cpp"
#include "game controller/gameController.cpp"
#include "game controller/battleController.cpp"

#include "doromon.cpp"
#include "gacha.cpp"
#include "game.cpp"
#include "skills/attack.cpp"
#include "skills/support.cpp"
#include "skills/skill.cpp"

using namespace std;

//Starts game
int  main (){

    Game start;
    MenuController menu;
    GameController game;
    BattleController battle;

    //asks player if new/load/exit game
    int menuOut = menu.run();
    
    //1-new 2-load 3-exit
    if(menuOut == 1 || menuOut == 2){

        while(start.getRun()){
            game.run(menuOut, &start);
            battle.run(&start);

            if(start.getRun())
                game.checkWin(&start);
        }
    }

}