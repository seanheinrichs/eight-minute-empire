
#include "Cards.h"
#include <ctime>
#include <algorithm>
#include <iostream>

Cards::Cards() {
    this->numOfGood = nullptr;
    this->good = nullptr;
    this->action = nullptr;
}

ostream &operator<<(ostream &os, const Cards &cards) {
    os << *cards.getGood() << " (" << *cards.getNumOfGood() << ") - " << *cards.getAction();
    return os;
}

Cards::~Cards() {
    if (good){
        delete good;
        good = nullptr;
    }
    if (action){
        delete action;
        action = nullptr;
    }
    if (numOfGood){
        delete numOfGood;
        numOfGood = nullptr;
    }
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

Cards::Cards(int numOfGood, string good, string action) {
    Cards::numOfGood = new int(numOfGood);
    this->good = new string(good);
    this->action = new string(action);
}

int *Cards::getNumOfGood() const {
    return this->numOfGood;
}

void Cards::setNumOfGood(int numOfGood) {
    Cards::numOfGood = new int(numOfGood);
}

Cards* cards01 = new Cards(1,"Wild", "MOVE_OVER_WATER 2");
Cards* cards02 = new Cards(1,"Wild", "MOVE_OVER_WATER 2");
Cards* cards03 = new Cards(1,"Wild", "PLACE_NEW_ARMIES_ON_BOARD 2");
Cards* cards04 = new Cards(1,"Crystal", "PLACE_NEW_ARMIES_ON_BOARD 2");
Cards* cards05 = new Cards(1,"Crystal", "PLACE_NEW_ARMIES_ON_BOARD 2");
Cards* cards06 = new Cards(1,"Crystal", "PLACE_NEW_ARMIES_ON_BOARD 2");
Cards* cards07 = new Cards(1,"Crystal", "PLACE_NEW_ARMIES_ON_BOARD 1");
Cards* cards08 = new Cards(1,"Crystal", "MOVE_OVER_GROUND 2");
Cards* cards09 = new Cards(1,"Rock", "MOVE_OVER_GROUND 2");
Cards* cards10 = new Cards(1,"Rock", "MOVE_OVER_WATER 2");
Cards* cards11 = new Cards(1,"Rock", "MOVE_OVER_WATER 2");
Cards* cards12 = new Cards(1, "Rock", "MOVE_OVER_WATER 3");
Cards* cards13 = new Cards(1,"Rock", "PLACE_NEW_ARMIES_ON_BOARD 3");
Cards* cards14 = new Cards(1,"Rock", "PLACE_NEW_ARMIES_ON_BOARD 3");
Cards* cards15 = new Cards(1,"Rock", "PLACE_NEW_ARMIES_ON_BOARD 2 OR BUILD_A_CITY 1");
Cards* cards16 = new Cards(1,"Carrot", "BUILD_A_CITY 1");
Cards* cards17 = new Cards(1,"Carrot", "DESTROY_ARMY 1 AND PLACE_NEW_ARMIES_ON_BOARD 1");
Cards* cards18 = new Cards(1,"Carrot", "PLACE_NEW_ARMIES_ON_BOARD 3");
Cards* cards19 = new Cards(1,"Carrot", "MOVE_OVER_GROUND 4");
Cards* cards20 = new Cards(1,"Carrot", "MOVE_OVER_GROUND 4");
Cards* cards21 = new Cards(1,"Carrot","PLACE_NEW_ARMIES_ON_BOARD 4 OR MOVE_OVER_GROUND 2");
Cards* cards22 = new Cards(1,"Carrot", "MOVE_OVER_GROUND 5");
Cards* cards23 = new Cards(1,"Carrot", "BUILD_A_CITY 1");
Cards* cards24 = new Cards(1,"Carrot", "MOVE_OVER_WATER 3");
Cards* cards25 = new Cards(2,"Carrot", "PLACE_NEW_ARMIES_ON_BOARD 3");
Cards* cards26 = new Cards(1,"Tree", "MOVE_OVER_GROUND 5");
Cards* cards27 = new Cards(1,"Tree", "MOVE_OVER_GROUND 6");
Cards* cards28 = new Cards(1,"Tree", "PLACE_NEW_ARMIES_ON_BOARD 2 OR MOVE_OVER_GROUND 3");
Cards* cards29 = new Cards(1,"Tree", "DESTROY_ARMY 1 OR BUILD_A_CITY 1");
Cards* cards30 = new Cards(1,"Tree", "PLACE_NEW_ARMIES_ON_BOARD 3");
Cards* cards31 = new Cards(1,"Tree", "MOVE_OVER_WATER 4");
Cards* cards32 = new Cards(1,"Tree", "MOVE_OVER_WATER 3");
Cards* cards33 = new Cards(1,"Tree", "BUILD_A_CITY 1");
Cards* cards34 = new Cards(1,"Anvil", "PLACE_NEW_ARMIES_ON_BOARD 3");
Cards* cards35 = new Cards(1,"Anvil", "PLACE_NEW_ARMIES_ON_BOARD 3");
Cards* cards36 = new Cards(1,"Anvil", "MOVE_OVER_WATER 3");
Cards* cards37 = new Cards(1,"Anvil", "BUILD_A_CITY 1");
Cards* cards38 = new Cards(2,"Anvil", "MOVE_OVER_GROUND 4");
Cards* cards39 = new Cards(1,"Anvil", "MOVE_OVER_GROUND 5");
Cards* cards40 = new Cards(1,"Anvil", "MOVE_OVER_GROUND 4");
Cards* cards41 = new Cards(1,"Anvil", "PLACE_NEW_ARMIES_ON_BOARD 3 OR MOVE_OVER_GROUND 4");
Cards* cards42 = new Cards(1,"Anvil", "PLACE_NEW_ARMIES_ON_BOARD 3 OR MOVE_OVER_GROUND 3");

Deck::Deck() {
    position = new int();
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
    if(cost){
        delete cost;
        cost = nullptr;
    }
    if(position){
        delete position;
        position = nullptr;
    }
}


Cards* Deck::draw() {
    std::srand ( unsigned ( std::time(0) ) ); // another way to generate a Random seed
    std::random_shuffle(deck.begin(), deck.end());
//    std::random_shuffle(deck.begin(), deck.end(), seed1); // one way to generate a Random seed

//    Check if deck shuffled well:
//    std::cout << "deck contains:";
//    for (std::vector<Cards*>::iterator it=deck.begin(); it!=deck.end(); ++it)
//        std::cout << ' ' << **it << endl;

    std::cout << '\n';
//    Cards* card = (Cards *) (deck.back());
    auto card = deck.back();
    std::cout << "draw one card from the deck: " << *card << endl;

    deck.pop_back();
//    Check if the cards set shrinks after draw out one card and
//    shuffles before each draw in order to simulate the random draw a card:
    std::cout << "deck size: " << deck.size() << endl;
//    std::cout << "next card: " << *deck.back() << endl;
    std::cout << "slide the card to the end of Top Board" << endl;
    return card;
}

std::vector<Cards*> Deck::topBoardGenetor(Deck &deck) {
    auto tb = new std::vector<Cards*>();
    for (auto i = 0; i < 6; i++) {
        tb->emplace_back(deck.draw());
    }
//    std::cout << "TopBoard size: " << tb->size() << endl;
    // displayTopBoard(*tb);
//    std::cout << "topBoardGenetor(Deck deck) works" << endl;
    return *tb;
}

void Deck::displayTopBoard(std::vector<Cards*> &topBoard) {
    int j = 0;
    int index =  0;
    for (auto it = topBoard.begin(); it != topBoard.end(); ++it)
        cout << "Position " << ++j << " - Cost: "<< posArray[index++] << " Coins. " << **it << endl;
//    std::cout << "displayTopBoard( topBoard ) works" << endl;
}

void Deck::updateTopBoard(int &position, std::vector<Cards*> &topBoard, Deck &deck) {
    int index = position - 1;
    topBoard.erase(topBoard.begin()+index);
    cout << "Top Board cards series size is " << topBoard.size() << endl ;
    topBoard.emplace_back(deck.draw());
    cout << "Top Board cards series size is " << topBoard.size() << endl ;
    std::cout << "updateTopBoard( topBoard ) works" << endl;
    displayTopBoard(topBoard);
    std::cout << "----------------------"<<endl;
//    auto tb = new std::vector<Cards*>();
//    for (auto it = topBoard.begin(); it != topBoard.end(); ++it){
//        tb->emplace_back(it);
//    }
//    return *tb;
}

std::vector<Cards*> Deck::handGenetor(Cards* &card) {
    std::vector<Cards*> hand;
    hand.emplace_back(card);
    return hand;
}

void Deck::displayHand(std::vector<Cards*> &hand) {
    for (auto it = hand.begin(); it != hand.end(); ++it) {
        std::cout << ' ' << **it << endl;
    }
}

void Deck::exchange(Player &player, std::vector<Cards*> &topBoard, Deck &deck) {
    bool successfullPurchase = false;
    int cost, position, index;

    // display top board before player purchases a card
    cout<< "Top Board:" << endl;
    displayTopBoard(topBoard);

    // allow player to purchase a card
    cout << player.getName() << ", you have " << player.getCoins() << " coins remaining in your stash." << endl;
    cout << "Which card do you want to buy? Please enter an integer from 1 to 6: " << endl;
    do {
        cin >> position;
        if (position < 1 || position > 6) {
            cout << "Invalid input: " << position << ". Please enter an integer from 1 to 6: " << endl;
            continue;
        }
        if (position == 1) {
            cost = 0;
        }
        else if (position == 2 || position == 3) {
            cost = 1;
        }
        else if (position == 4 || position == 5) {
            cost = 2;
        }
        else if (position == 6) {
            cost = 3;
        }
        successfullPurchase = player.payCoin(cost);
    } while (!successfullPurchase);

    // purchase confirmation
    index = position - 1;
    cout << "The card which shows: " << *topBoard.at(index) << " and costs " << posArray[index] << " coins." << endl;

    // update gamehand and update top board
    player.getGameHand()->emplace_back(topBoard.at(index));
    topBoard.erase(topBoard.begin()+index);
    cout << "Top Board cards series size is " << topBoard.size() << endl ;
    topBoard.emplace_back(deck.draw());
    cout << "Top Board cards series size is " << topBoard.size() << endl ;
    cout << player.getName() << " added the following card to their hand: " << *player.getGameHand()->back() << endl;
//    cout << "Deck::exchange(hand, topboard, deck) works"  << endl;

    // display updated top board
    cout << "Top Board:" << endl;
    displayTopBoard(topBoard);
    cout << player.getName() << " added the following card to their hand: " << *player.getGameHand()->back() << endl;
    cout << endl << endl;
}

