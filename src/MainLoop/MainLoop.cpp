#include "MainLoop.h"
#include "GameState.h"
#include "GameStartup.h"
#include "GameObservers.h"
#include <iostream>

void mainLoopDriver()
{

    // setting up the game
    GameState state = GameState();
    int firstPlayerIndex = startGame(state);
    int gameLength = state.determineGameLength();
    std::vector<Cards *> topBoard = state.deck->topBoardGenetor(*state.deck);

    // Setting up the observers
    Observable subject{};
    auto *phase = new PhaseObserver("phase");
    auto *stats = new StatisticsObserver("stats");
    subject.attach(phase);
    subject.attach(stats);

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
            std::cout << state.players->at(turnIndex)->getName() << ", it is now your turn." << std::endl;

            // player purchases a card
            state.deck->exchange(*state.players->at(turnIndex), topBoard, *state.deck);

            // player has the option to ignore card effect, effectively ending their turn
            bool endTurn = state.players->at(turnIndex)->ignore();
            std::string action = *(state.players->at(turnIndex)->getGameHand()->at(i - 1)->getAction());

            if (endTurn)
            {
                subject.notify(state, state.players->at(turnIndex)->getName(), action);
                continue;
            }

            //if card action is of type "AND" or "OR" call andOrAction()
            if (action.find("OR") != std::string::npos || action.find("AND") != std::string::npos)
            {
                state.players->at(turnIndex)->andOrAction(action, *state.map, *state.players);
                subject.notify(state, state.players->at(turnIndex)->getName(), action);
            }
            // otherwise call takeAction
            else
            {
                state.players->at(turnIndex)->takeAction(action, *state.map, *state.players);
                subject.notify(state, state.players->at(turnIndex)->getName(), action);
            }
        }
    }
}
