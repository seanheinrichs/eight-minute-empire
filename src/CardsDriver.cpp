
#include "Cards.h"
#include <iostream>


int main(int argc, char *argv[]){

    //test Hand and exchange()
    Deck::Hand hand1;
    hand1.exchange();

    //test Deck and draw() Hand include all functions of Deck, so Deck or draw() are redundancies should be removed
    Deck deck1;
    deck1.draw();
    deck1.draw();
    deck1.draw();
}