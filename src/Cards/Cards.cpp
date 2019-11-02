
#include "Cards.h"
#include <ctime>
#include <algorithm>
#include <iostream>

Cards::Cards() {
    this->numOfGood = nullptr;
    this->good = nullptr;
    this->action = nullptr;
}

Cards::Cards(int numOfGood, string good, string action) {
    Cards::numOfGood = new int(numOfGood);
    this->good = new string(good);
    this->action = new string(action);
}

Cards::~Cards() {
    delete numOfGood;
    this->numOfGood = nullptr;
    delete good;
    this->good = nullptr;
    delete action;
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

Cards* cards01 = new Cards(1,"Wild", "MOVE_OVER_WATER 2");
Cards* cards02 = new Cards(1,"Wild", "MOVE_OVER_WATER 2");
Cards* cards03 = new Cards(1,"Wild", "PLACE_NEW_ARMIES_ON_BOARD 2");
Cards* cards04 = new Cards(1,"Crystal", "PLACE_NEW_ARMIES_ON_BOARD 2");
Cards* cards05 = new Cards(1,"Crystal", "PLACE_NEW_ARMIES_ON_BOARD 2");
Cards* cards06 = new Cards(1,"Crystal", "PLACE_NEW_ARMIES_ON_BOARD 2");
Cards* cards07 = new Cards(1,"Crystal", "PLACE_NEW_ARMIES_ON_BOARD 1");
Cards* cards08 = new Cards(1,"Crystal", "MOVE_OVER_LAND 2");
Cards* cards09 = new Cards(1,"Rock", "MOVE_OVER_LAND 2");
Cards* cards10 = new Cards(1,"Rock", "MOVE_OVER_WATER 2");
Cards* cards11 = new Cards(1,"Rock", "MOVE_OVER_WATER 2");
Cards* cards12 = new Cards(1, "Rock", "MOVE_OVER_WATER 3");
Cards* cards13 = new Cards(1,"Rock", "PLACE_NEW_ARMIES_ON_BOARD 3");
Cards* cards14 = new Cards(1,"Rock", "PLACE_NEW_ARMIES_ON_BOARD 3");
Cards* cards15 = new Cards(1,"Rock", "PLACE_NEW_ARMIES_ON_BOARD 2 OR BUILD_A_CITY");
Cards* cards16 = new Cards(1,"Carrot", "BUILD_A_CITY");
Cards* cards17 = new Cards(1,"Carrot", "DESTROY_ARMY 1 AND PLACE_NEW_ARMIES_ON_BOARD 1");
Cards* cards18 = new Cards(1,"Carrot", "PLACE_NEW_ARMIES_ON_BOARD 3");
Cards* cards19 = new Cards(1,"Carrot", "MOVE_OVER_LAND 4");
Cards* cards20 = new Cards(1,"Carrot", "MOVE_OVER_LAND 4");
Cards* cards21 = new Cards(1,"Carrot","PLACE_NEW_ARMIES_ON_BOARD 4 OR MOVE_OVER_LAND 2");
Cards* cards22 = new Cards(1,"Carrot", "MOVE_OVER_LAND 5");
Cards* cards23 = new Cards(1,"Carrot", "BUILD_A_CITY");
Cards* cards24 = new Cards(1,"Carrot", "MOVE_OVER_WATER 3");
Cards* cards25 = new Cards(2,"Carrot", "PLACE_NEW_ARMIES_ON_BOARD 3");
Cards* cards26 = new Cards(1,"Tree", "MOVE_OVER_LAND 5");
Cards* cards27 = new Cards(1,"Tree", "MOVE_OVER_LAND 6");
Cards* cards28 = new Cards(1,"Tree", "PLACE_NEW_ARMIES_ON_BOARD 2 OR MOVE_OVER_LAND 3");
Cards* cards29 = new Cards(1,"Tree", "DESTROY_ARMY 1 OR BUILD_A_CITY");
Cards* cards30 = new Cards(1,"Tree", "PLACE_NEW_ARMIES_ON_BOARD 3");
Cards* cards31 = new Cards(1,"Tree", "MOVE_OVER_WATER 4");
Cards* cards32 = new Cards(1,"Tree", "MOVE_OVER_WATER 3");
Cards* cards33 = new Cards(1,"Tree", "BUILD_A_CITY");
Cards* cards34 = new Cards(1,"Anvil", "PLACE_NEW_ARMIES_ON_BOARD 3");
Cards* cards35 = new Cards(1,"Anvil", "PLACE_NEW_ARMIES_ON_BOARD 3");
Cards* cards36 = new Cards(1,"Anvil", "MOVE_OVER_WATER 3");
Cards* cards37 = new Cards(1,"Anvil", "BUILD_A_CITY");
Cards* cards38 = new Cards(2,"Anvil", "MOVE_OVER_LAND 4");
Cards* cards39 = new Cards(1,"Anvil", "MOVE_OVER_LAND 5");
Cards* cards40 = new Cards(1,"Anvil", "MOVE_OVER_LAND 4");
Cards* cards41 = new Cards(1,"Anvil", "PLACE_NEW_ARMIES_ON_BOARD 3 OR MOVE_OVER_LAND 4");
Cards* cards42 = new Cards(1,"Anvil", "PLACE_NEW_ARMIES_ON_BOARD 3 OR MOVE_OVER_LAND 3");
// random generator function:
int seed1 (int i) { return std::rand() % i;}

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
//    std::cout<<"Deck is good" << endl;
}

Deck::~Deck() {
}


Cards* Deck::draw() {
//    std::srand ( unsigned ( std::time(0) ) ); // another way to generate a Random seed
    std::random_shuffle(deck.begin(), deck.end(), seed1);
//    Check if deck shuffled well:
//    std::cout << "deck contains:";
//    for (std::vector<Cards*>::iterator it=deck.begin(); it!=deck.end(); ++it)
//        std::cout << ' ' << **it << endl;

    std::cout << '\n';
//    Cards* card = (Cards *) (deck.back());
    auto card = deck.back();
    std::cout << "draw one card: " << *card << endl;

    deck.pop_back();
//    Check if the cards set shrinks after draw out one card and
//    shuffles before each draw in order to simulate the random draw a card:
    std::cout << "deck size: " << deck.size() << endl;
//    std::cout << "next card: " << *deck.back() << endl;
//    std::cout << "draw( ) works" << endl;
    return card;
}

std::vector<Cards*> Deck::topBoardGenetor(Deck deck) {
    for (auto i = 0; i < 6; i++) {
        topBoard.emplace_back(deck.draw());
    }
    std::cout << "TopBoard size: " << topBoard.size() << endl;

    int j = 0;
    for (auto it = topBoard.begin(); it != topBoard.end(); ++it)
        cout << "Position " << ++j << " " << **it << endl;
//    std::cout << "topBoardGenetor(Deck deck) works" << endl;
    return topBoard;
}

// could use or remove in the future
std::vector<Cards*> Deck::handGenetor(Cards* card) {
    std::vector<Cards*> hand;
    hand.emplace_back(card);
    return hand;
}

std::vector<Cards*> Deck::exchange(std::vector<Cards*> hand, std::vector<Cards*> topBoard, Deck deck) {
    int input, index;
    cout << "Which card do you want to buy? Please enter an integer from 1 to 6: " << endl;
    cin >> input;
    while (input > 6 || input < 1) {
        cout << "Invalid input: " << input << ". Please enter an integer from 1 to 6: " << endl;
        cin >> input;
    }
    index = input - 1;
    cout << "The card which shows: " << topBoard.at(index) << " and costs " << posArray[index] << " dollars." << endl;
    cout << "Would you like to buy this card ? " << endl;
    //TODO: call PayCoin() here
    hand.emplace_back(topBoard.at(index));
    topBoard.erase(topBoard.begin()+index);
    cout << "Top Board cards series size is " << topBoard.size() << endl ;
    topBoard.emplace_back(deck.draw());
    cout << "Top Board cards series size is " << topBoard.size() << endl ;
    cout << "Player 1 's hand has " << *hand.back() << endl;
//    cout << "Deck::exchange(hand, topboard, deck) works"  << endl;
    return hand;
}
