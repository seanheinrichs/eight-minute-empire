#include "CardsDriver.h"
#include "Cards.h"
#include <iostream>

void cardsDriverExamples()
{
    //test Deck and draw() exchange
    std::cout<< "======== Test Deck, topBoard, hand, draw( ) exchange( )"<< endl;
    Deck deck1;
    std::vector<Cards*> topBoard = deck1.topBoardGenetor(deck1);
    std::vector<Cards*> hand;
    deck1.exchange(hand, topBoard, deck1);

}