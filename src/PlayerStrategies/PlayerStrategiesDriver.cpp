#include <iostream>

#include "PlayerStrategiesDriver.h"
#include "Player.h"
#include "GameStartup.h"

// Forward Declarations
class Player;
class Cards;

void playerStrategiesDriver()
{
    // setting up the game
    GameState state = GameState(false);
    int firstPlayerIndex = startGame(state);
    int gameLength = state.determineGameLength();
    std::vector<Cards *> topBoard = state.deck->topBoardGenetor(*state.deck);

    // number of game terms limited by number of players
    for (int i = 1; i <= gameLength; i++)
    {

        bool changeStrategy = validateChangeStrategy();

        if (changeStrategy)
        {
            changePlayerStrategy(*state.players);
        }

        std::cout << "Turn " << i << ". " << gameLength - i << " Turns remain." << endl
                  << endl;

        // each player gets to play once per turn
        for (int j = firstPlayerIndex; j < firstPlayerIndex + state.players->size(); j++)
        {

            int turnIndex = j % state.players->size();

            // infrom players on whose turn it is, display current state of the map
            std::cout << state.players->at(turnIndex)->getName()
                      << ", it is now your turn. Here is the current state of the game." << endl
                      << endl;
            state.map->printNodes();

            // action phase
            state.players->at(turnIndex)->getPlayerStrategies()->selectAction(state, turnIndex, topBoard, i);
        }
    }
}
