#pragma once
#include "AfterActionDriver.h"
#include "Cards.h"
#include "Player.h"

void afterActionExample() {

    std::cout<< "======== Test Top Board and Play pass to the next ====== "<< endl;
    Deck deck1;
    std::vector<Cards*> tb = deck1.topBoardGenetor(deck1);
    std::vector<Cards*> *hand1 = new std::vector<Cards*>();
    std::vector<Cards*> *hand2 = new std::vector<Cards*>();
    std::vector<Cards*> *hand3 = new std::vector<Cards*>();
    for (int i = 1; i < 4; i++) {
        deck1.exchange(*hand1, tb, deck1);
        deck1.exchange(*hand2, tb, deck1);
        deck1.exchange(*hand3, tb, deck1);
    }
    deck1.displayTopBoard(tb);
    cout << "============= Player 1 =================" << endl;
    deck1.displayHand(*hand1);
    cout << "============= Player 2 =================" << endl;
    deck1.displayHand(*hand2);
    cout << "============= Player 3 =================" << endl;
    deck1.displayHand(*hand3);

}
