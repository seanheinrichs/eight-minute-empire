#include "BiddingFacility/BiddingFacilityDriver.h"
#include "Cards/CardsDriver.h"
#include "GameState/GameStateDriver.h"
#include "Map/MapDriver.h"
#include "MapLoader/MapLoaderDriver.h"
#include "Player/PlayerDriver.h"
#include "Map/Map.h"
#include "MapLoader/MapLoader.h"
#include "Cards/Cards.h"
#include "Player/Player.h"
#include "BiddingFacility/BiddingFacility.h"
#include "PlayerMethodsDriver.h"
#include "GameStartupDriver.h"
#include "MainLoop/MainLoop.h"

int main()
{
    //// Assignment 2 Drivers ////

    // Part 1)
    // gameStateDriver();

    // Part 2)
    // gameStartupExample();

    // Part 3 AND 5)
    // mainLoopDriver();

    // Part 4)
    // playerMethodsDriver();

    MapLoader loader;
    Map m = loader.generateMap("assets/map1.map");
    auto r = m.getContinentOwners();

    auto iter = r.begin();
    while (iter != r.end()) {
        std::cout << iter->first << " " << iter->second;
        iter++;
    }
    
    
    return 0;
}