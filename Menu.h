#pragma once
#ifndef MENU_H_
#define MENU_H_
#include "CourseManager.h"

class Menu
{
private:
    CourseManager manager;

public:
    void run();
    void showMenu();
    void handleInput(int choice);
};

#endif