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
#include "GameScore/GameScore.h"
#include "GameScore/GameScoreDriver.h"

int main()
{
    std::cout << "Please see main.cpp and uncomment functions to show Map and "
                 "map file rejections\n\n";
    ///// MapDriver Examples /////

    // valid map creation
    // validMapExample();

    // valid map with no players
    // mapWithNoPlayersExample();

    // rejection of invalid map data
    // uncomment sections below to cause program to fail
    // valid map with no players
    // mapWithNoPlayersExample();

    // invalidRegionMapExample();
    // invalidContinentMapExample();
    // invalidOwnerMapExample();
    // invalidConnectionsMapExample();
    // invalidStartMapExample();

    ///// MapLoaderDriver Examples /////

    // valid file read and map creation example
    // validMapFileExamples();

    // rejection of invalid map file
    // uncomment sections below to cause program to fail

    // void invalidContinentFileExample();
    // void noPlayersInFileExample();
    // void invalidConnectionInFileExample();
    // void missingDelitimerInFileExample();
    // graphNotConnectedInFileExample();

    ///// CardsDriver Examples /////
    // cardsDriverExamples();

    ///// PlayerDriver Examples /////
    // PlayerDriver();

    ///// BiddingFacility Examples /////
    // BiddingFacilityDriver();

    //// Game Start Example ////
    // gameStateDriver();

    //// BiddingFacility Examples ////
    // BiddingFacilityDriver();

    // PlayerMethodsDriver();

    // Startup Phase Example
//    gameStartupExample();

    //// Game Score Example ////
    gameScoreExample( );


    return 0;
}