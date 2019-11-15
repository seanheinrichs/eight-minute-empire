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
#include "AfterAction/AfterActionDriver.h"
#include "GameScore/GameScore.h"
#include "GameScore/GameScoreDriver.h"
#include "GameObservers/GameObservers.h"

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

    // Part 5)
    // gameScoreExample();

    GameState state;
    Observable subject;
    auto *phase = new PhaseObserver("phase");

    subject.attach(phase);
    subject.notify(state);
    subject.detach("phase");
    subject.notify(state);
    return 0;
}