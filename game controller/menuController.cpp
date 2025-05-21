#include "menuController.h"

int MenuController::run(){
    int ret = 0;

    while(running){
        menu.display();

        cin>> ret;

        if (ret==1||ret==2||ret==3){
            running = false;
        }
    }
    return ret;
}