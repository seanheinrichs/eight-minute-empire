#pragma once
#include "AfterActionDriver.h"
#include "Cards.h"
#include "Player.h"
#include "GameState.h"
#include "GameStartup.h"

void afterActionExample() {

    // setting up the game
    GameState state = GameState();
    int firstPlayerIndex = startGame(state);
    int gameLength = state.determineGameLength();
    std::vector<Cards*> topBoard = state.deck->topBoardGenetor(*state.deck);

    // number of game terms limited by number of players
    for (int i = 1; i <= gameLength; i++) {

        std::cout << "Turn " << i << ". " << gameLength - i << " Turns remain." << endl << endl;

        // each player gets to play once per turn
        for (int j = firstPlayerIndex; j < firstPlayerIndex + state.players->size(); j++) {

            int turnIndex = j % state.players->size();

            // infrom players on whose turn it is, display current state of the map
            std::cout << state.players->at(turnIndex)->getName() << ", it is now your turn. Here is the current state of the game." << endl << endl;
            state.map->printNodes();

            // player purchases a card
            state.deck->exchange(*state.players->at(turnIndex), topBoard, *state.deck);

            // player has the option to ignore card effect, effectively ending their turn
            bool endTurn = state.players->at(turnIndex)->ignore();
            if (endTurn) {
                continue;
            }

            std::string action = *(state.players->at(turnIndex)->getGameHand()->at(i-1)->getAction());

            //if card action is of type "AND" or "OR" call andOrAction()
            if (action.find("OR") != std::string::npos || action.find("AND") != std::string::npos) {
                state.players->at(turnIndex)->andOrAction(action, *state.map, *state.players);
            }
                // otherwise call takeAction
            else {
                state.players->at(turnIndex)->takeAction(action, *state.map, *state.players);
            }
        }
    }

    //// please comment out one block before run the code, otherwise surprise expected ////
//    std::cout<< "======== Deck draw( ) shuffled well ====== "<< endl;
//    Deck deck100;
//    deck100.draw();
//    deck100.draw();


//    std::cout<< "======== Test Top Board and Play pass to the next ====== "<< endl;
//    Deck deck1;
//    std::vector<Cards*> tb = deck1.topBoardGenetor(deck1);
//    std::vector<Cards*> *hand1 = new std::vector<Cards*>();
//    std::vector<Cards*> *hand2 = new std::vector<Cards*>();
//    std::vector<Cards*> *hand3 = new std::vector<Cards*>();
//    for (int i = 1; i < 4; i++) {
//        deck1.exchange(*hand1, tb, deck1);
//        deck1.exchange(*hand2, tb, deck1);
//        deck1.exchange(*hand3, tb, deck1);
//    }
//    deck1.displayTopBoard(tb);
//    cout << "============= Player 1 =================" << endl;
//    deck1.displayHand(*hand1);
//    cout << "============= Player 2 =================" << endl;
//    deck1.displayHand(*hand2);
//    cout << "============= Player 3 =================" << endl;
//    deck1.displayHand(*hand3);

}
