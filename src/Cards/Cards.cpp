
#include "Cards.h"
#include <ctime>
#include <algorithm>
#include <iostream>

Cards::Cards() {}

Cards::Cards(int numOfGood, string good, string action) {
    Cards::numOfGood = new int(numOfGood);
    this->good = new string(good);
    this->action = new string(action);
}

Cards::~Cards() {
    this->good = nullptr;
    this->action = nullptr;
}

string *Cards::getGood() const {
    return good;
}

void Cards::setGood(string good) {
    Cards::good = new string(good);
}

string *Cards::getAction() const {
    return this->action;
}

void Cards::setAction(string action) {
    Cards::action = new string(action);
}

int *Cards::getNumOfGood() const {
    return this->numOfGood;
}

void Cards::setNumOfGood(int numOfGood) {
    Cards::numOfGood = new int(numOfGood);
}

ostream &operator<<(ostream &os, const Cards &cards) {
    os <<"numOfGood: " << *cards.getNumOfGood() <<"good: " << *cards.getGood() << " action: " << *cards.getAction();
    return os;
}
// random generator function:
int seed1 (int i) { return std::rand() % i;}
int seed2 (int i) { return std::rand()%i;}

Deck::Deck() {
    deck->push_back(*cards01);
    deck->push_back(*cards02);
    deck->push_back(*cards03);
    deck->push_back(*cards04);
    deck->push_back(*cards05);
    deck->push_back(*cards06);
    deck->push_back(*cards07);
    deck->push_back(*cards08);
    deck->push_back(*cards09);
    deck->push_back(*cards10);
    deck->push_back(*cards11);
    deck->push_back(*cards12);
    deck->push_back(*cards13);
    deck->push_back(*cards14);
    deck->push_back(*cards15);
    deck->push_back(*cards16);
    deck->push_back(*cards17);
    deck->push_back(*cards18);
    deck->push_back(*cards19);
    deck->push_back(*cards20);
    deck->push_back(*cards21);
    deck->push_back(*cards22);
    deck->push_back(*cards23);
    deck->push_back(*cards24);
    deck->push_back(*cards25);
    deck->push_back(*cards26);
    deck->push_back(*cards27);
    deck->push_back(*cards28);
    deck->push_back(*cards29);
    deck->push_back(*cards30);
    deck->push_back(*cards31);
    deck->push_back(*cards32);
    deck->push_back(*cards33);
    deck->push_back(*cards34);
    deck->push_back(*cards35);
    deck->push_back(*cards36);
    deck->push_back(*cards37);
    deck->push_back(*cards38);
    deck->push_back(*cards39);
    deck->push_back(*cards40);
    deck->push_back(*cards41);
    deck->push_back(*cards42);
}

Deck::~Deck() {
}


void Deck::draw() {
//    std::srand ( unsigned ( std::time(0) ) ); // another way to generate a Random seed
    std::random_shuffle(deck->begin(), deck->end(), seed1);
//    Check if deck shuffled well:
//    std::cout << "deck contains:";
//    for (std::vector<Cards>::iterator it=deck->begin(); it!=deck->end(); ++it)
//        std::cout << ' ' << *it << endl;

    std::cout << '\n';
    std::cout << "draw one card: " << deck->back() << endl;
    deck->pop_back();
//    Check if the cards set shrinks after draw out one card and
//    shuffles before each draw in order to simulate the random draw a card:
    std::cout << "deck size: " << deck->size() << endl;
    std::cout << "next card: " << deck->back() << endl;
}




Deck::Hand::Hand() {
    shuffledCards.emplace_back(cards01);
    shuffledCards.emplace_back(cards02);
    shuffledCards.emplace_back(cards03);
    shuffledCards.emplace_back(cards04);
    shuffledCards.emplace_back(cards05);
    shuffledCards.emplace_back(cards06);
    shuffledCards.emplace_back(cards07);
    shuffledCards.emplace_back(cards08);
    shuffledCards.emplace_back(cards09);
    shuffledCards.emplace_back(cards10);
    shuffledCards.emplace_back(cards11);
    shuffledCards.emplace_back(cards12);
    shuffledCards.emplace_back(cards13);
    shuffledCards.emplace_back(cards14);
    shuffledCards.emplace_back(cards15);
    shuffledCards.emplace_back(cards16);
    shuffledCards.emplace_back(cards17);
    shuffledCards.emplace_back(cards18);
    shuffledCards.emplace_back(cards19);
    shuffledCards.emplace_back(cards20);
    shuffledCards.emplace_back(cards21);
    shuffledCards.emplace_back(cards22);
    shuffledCards.emplace_back(cards23);
    shuffledCards.emplace_back(cards24);
    shuffledCards.emplace_back(cards25);
    shuffledCards.emplace_back(cards26);
    shuffledCards.emplace_back(cards27);
    shuffledCards.emplace_back(cards28);
    shuffledCards.emplace_back(cards29);
    shuffledCards.emplace_back(cards30);
    shuffledCards.emplace_back(cards31);
    shuffledCards.emplace_back(cards32);
    shuffledCards.emplace_back(cards33);
    shuffledCards.emplace_back(cards34);
    shuffledCards.emplace_back(cards35);
    shuffledCards.emplace_back(cards36);
    shuffledCards.emplace_back(cards37);
    shuffledCards.emplace_back(cards38);
    shuffledCards.emplace_back(cards39);
    shuffledCards.emplace_back(cards40);
    shuffledCards.emplace_back(cards41);
    shuffledCards.emplace_back(cards42);

    std::random_shuffle(shuffledCards.begin(), shuffledCards.end(), seed2);

    for (auto i=0; i<6; i++) {
        hand.emplace_back(shuffledCards.back());
        shuffledCards.pop_back();
    }
    int j = 0;
    for (auto it = hand.begin(); it != hand.end(); ++it){
        cout << "Position " << ++j << " " << *it << endl;
    }
}

Deck::Hand::~Hand() {

}

int *Deck::Hand::getCost() const {
    return cost;
}

void Deck::Hand::setCost(int *cost) {
    Hand::cost = cost;
}

int *Deck::Hand::getPosition() const {
    return position;
}

void Deck::Hand::setPosition(int position) {
    *Hand::position = position;
}

void Deck::Hand::exchange() {
    int input, index;
    cout << "Which card do you want to buy? Please enter an integer from 1 to 6: " << endl;
    cin >> input;
    while (input >6 || input < 1){
        cout << "Invalid input : " << input << ".  Please enter an integer from 1 to 6: " << endl;
        cin >> input;
    }
    index = input -1 ;
    cout << "The card which shows: " << hand.at(index) << " and costs " << posArray[index] << " dollars." << endl;
//    setCost(posArray[index]);
    cout << "Would you like to buy this card ? " << endl;
    cout << "You are going to pay " << posArray[index] << " for this card." << endl;
    //TODO: call PayCoin() here

    playerHand1.emplace_back(hand.at(index));
    hand.erase(hand.begin()+index);
    cout << "Top Board cards series size is " << hand.size() << endl ;
    hand.emplace_back(shuffledCards.back());
    cout << "Top Board cards series size is " << hand.size() << endl ;
    cout << "Player 1 's hand has " << playerHand1.back() << endl;
}
