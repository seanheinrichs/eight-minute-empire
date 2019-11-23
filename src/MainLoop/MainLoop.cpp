#include "MainLoop.h"
#include "GameState.h"
#include "GameStartup.h"
#include <iostream>

void mainLoopDriver()
{

    // setting up the game
    GameState state = GameState(false);
    int firstPlayerIndex = startGame(state);
    int gameLength = state.determineGameLength();
    std::vector<Cards *> topBoard = state.deck->topBoardGenetor(*state.deck);

    // number of game terms limited by number of players
    for (int i = 1; i <= gameLength; i++)
    {

        std::cout << "Turn " << i << ". " << gameLength - i << " Turns remain." << endl
                  << endl;

        // each player gets to play once per turn
        for (int j = firstPlayerIndex; j < firstPlayerIndex + state.players->size(); j++)
        {

            int turnIndex = j % state.players->size();

            // infrom players on whose turn it is, display current state of the map
            std::cout << state.players->at(turnIndex)->getName() << ", it is now your turn. Here is the current state of the game." << endl
                      << endl;
            state.map->printNodes();

            // player purchases a card
            state.deck->exchange(*state.players->at(turnIndex), topBoard, *state.deck);

            // player has the option to ignore card effect, effectively ending their turn
            bool endTurn = state.players->at(turnIndex)->ignore();
            if (endTurn)
            {
                continue;
            }

            std::string action = *(state.players->at(turnIndex)->getGameHand()->at(i - 1)->getAction());

            //if card action is of type "AND" or "OR" call andOrAction()
            if (action.find("OR") != std::string::npos || action.find("AND") != std::string::npos)
            {
                state.players->at(turnIndex)->andOrAction(action, *state.map, *state.players);
            }
            // otherwise call takeAction
            else
            {
                state.players->at(turnIndex)->takeAction(action, *state.map, *state.players);
            }
        }
    }
}