
#include "Cards.h"
#include <ctime>
#include <algorithm>
#include <iostream>

Cards::Cards() {
    *good = nullptr;
    *action = nullptr;
}

Cards::Cards(string *good, string *action) : good(good), action(action) {}

Cards::~Cards() {
    delete good;
    delete action;
}

std::ostream &operator<<(std::ostream &os, const Cards &cards) {
    os << "good: " << cards.good << " action: " << cards.action;
    return os;
}


Deck::Deck() {
    deck.push_back(cards01);
    deck.push_back(cards02);
    deck.push_back(cards03);
    deck.push_back(cards04);
    deck.push_back(cards05);
    deck.push_back(cards06);
    deck.push_back(cards07);
    deck.push_back(cards08);
    deck.push_back(cards09);
    deck.push_back(cards10);
    deck.push_back(cards11);
    deck.push_back(cards12);
    deck.push_back(cards13);
    deck.push_back(cards14);
    deck.push_back(cards15);
    deck.push_back(cards16);
    deck.push_back(cards17);
    deck.push_back(cards18);
    deck.push_back(cards19);
    deck.push_back(cards20);
    deck.push_back(cards21);
    deck.push_back(cards22);
    deck.push_back(cards23);
    deck.push_back(cards24);
    deck.push_back(cards25);
    deck.push_back(cards26);
    deck.push_back(cards27);
    deck.push_back(cards28);
    deck.push_back(cards29);
    deck.push_back(cards30);
    deck.push_back(cards31);
    deck.push_back(cards32);
    deck.push_back(cards33);
    deck.push_back(cards34);
    deck.push_back(cards35);
    deck.push_back(cards36);
    deck.push_back(cards37);
    deck.push_back(cards38);
    deck.push_back(cards39);
    deck.push_back(cards40);
    deck.push_back(cards41);
    deck.push_back(cards42);
}

Deck::~Deck() {

}

// random generator function:
int myrandom (int i) { return std::rand()%i;}
void Deck::draw() {
    Deck deck1;
    std::cout << deck1.cards02;
    std::srand ( unsigned ( std::time(0) ) );
    std::random_shuffle(deck.begin(), deck.end(), myrandom);

    std::cout << "deck contains:";
    for (std::vector<Cards>::iterator it=deck.begin(); it!=deck.end(); ++it)
        std::cout << ' ' << *it;

    std::cout << '\n';
}

std::ostream &operator<<(std::ostream &os, const Deck &deck) {
    os << "deck: " << " cards01: " << deck.cards01 << " cards02: " << deck.cards02 << " cards03: "
       << deck.cards03 << " cards04: " << deck.cards04 << " cards05: " << deck.cards05 << " cards06: " << deck.cards06
       << " cards07: " << deck.cards07 << " cards08: " << deck.cards08 << " cards09: " << deck.cards09 << " cards10: "
       << deck.cards10 << " cards11: " << deck.cards11 << " cards12: " << deck.cards12 << " cards13: " << deck.cards13
       << " cards14: " << deck.cards14 << " cards15: " << deck.cards15 << " cards16: " << deck.cards16 << " cards17: "
       << deck.cards17 << " cards18: " << deck.cards18 << " cards19: " << deck.cards19 << " cards20: " << deck.cards20
       << " cards21: " << deck.cards21 << " cards22: " << deck.cards22 << " cards23: " << deck.cards23 << " cards24: "
       << deck.cards24 << " cards25: " << deck.cards25 << " cards26: " << deck.cards26 << " cards27: " << deck.cards27
       << " cards28: " << deck.cards28 << " cards29: " << deck.cards29 << " cards30: " << deck.cards30 << " cards31: "
       << deck.cards31 << " cards32: " << deck.cards32 << " cards33: " << deck.cards33 << " cards34: " << deck.cards34
       << " cards35: " << deck.cards35 << " cards36: " << deck.cards36 << " cards37: " << deck.cards37 << " cards38: "
       << deck.cards38 << " cards39: " << deck.cards39 << " cards40: " << deck.cards40 << " cards41: " << deck.cards41
       << " cards42: " << deck.cards42;
    return os;
}

Hand::Hand() {}

Hand::~Hand() {

}

void Hand::exchange() {

}





