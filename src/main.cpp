#include "Map/MapDriver.h"
#include "GameObserverDriver.h"
#include "PlayerStrategies/PlayerStrategiesDriver.h"
#include "Map/Map.h"

int main()
{
    //// Assignment 3 Drivers ////

    // Part 1)
    playerStrategiesDriver();

    // Clear state between drivers
    Map::resetMapInstance();

    // Part 2) and 3)
    gameObserversDriver();

    // Clear state between drivers
    Map::resetMapInstance();

    // Part 4)
    mapSingletonTest();

    return 0;
}