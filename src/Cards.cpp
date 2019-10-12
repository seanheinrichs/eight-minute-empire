
#include "Cards.h"
#include <ctime>
#include <algorithm>
#include <iostream>

Cards::Cards() {
    this->good = nullptr;
    this->action = nullptr;
}

Cards::~Cards() {
}

Cards::Cards(const string &good, const string &action) : good(good), action(action) {}

const string &Cards::getGood() const {
    return good;
}

void Cards::setGood(const string &good) {
    Cards::good = good;
}

const string &Cards::getAction() const {
    return action;
}

void Cards::setAction(const string &action) {
    Cards::action = action;
}

ostream &operator<<(ostream &os, const Cards &cards) {
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
    std::srand ( unsigned ( std::time(0) ) );
    std::random_shuffle(deck.begin(), deck.end(), myrandom);

//    std::cout << "deck contains:";
//    for (std::vector<Cards>::iterator it=deck.begin(); it!=deck.end(); ++it)
//        std::cout << ' ' << *it << endl;

    std::cout << '\n';
    std::cout << "draw one card: " << deck.back() << endl;
    deck.pop_back();
    std::cout << "deck size: " << deck.size() << endl;
    std::cout << "next card: " << deck.back() << endl;
}

std::ostream &operator<<(std::ostream &os, const Deck &deck) {
    os << "deck: " << " cards01: " << endl;
    return os;
}

Hand::Hand() {}

Hand::~Hand() {

}

void Hand::exchange() {

}


