#include "Map/MapDriver.h"
#include "GameObserverDriver.h"
#include "PlayerStrategies/PlayerStrategiesDriver.h"

int main()
{
    //// Assignment 3 Drivers ////

    // Part 1)
    playerStrategiesDriver();

    // Part 2) and 3)
    gameObserversDriver();

    // Part 4)
    mapSingletonTest();

    return 0;
}