#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include"../game view/menuScreen.cpp"

#include <iostream>
using namespace std;

class MenuController{
    private:
        bool running = true;
        MenuScreen menu;

    public:
        int run();
};

#endif