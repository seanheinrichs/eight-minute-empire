#include "GameEngineDriver.h"
#include "GameEngine.h"

void gameEngineDriver()
{
    GameEngine * gameEngine = new GameEngine();
    bool isTournamentGame = gameEngine->selectGameMode();

    if (isTournamentGame)
    {
        gameEngine->tournamentGame();
    }
    else
    {
        gameEngine->singleGame();
    }
}



