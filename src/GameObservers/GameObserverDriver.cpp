#include "GameObserverDriver.h"
#include "MainLoop.h"
#include <iostream>

void gameObserversDriver()
{
    std::cout << "This driver will display the observers by running an actual game" << std::endl;
    std::cout << "At the end of each turn the gamephase willl be updated and new statistics will be displayed\n"
              << std::endl;

    mainLoopDriver();
}