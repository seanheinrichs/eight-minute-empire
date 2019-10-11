
#pragma once
#ifndef EIGHT_MINUTE_EMPIRE_CARDS_H
#define EIGHT_MINUTE_EMPIRE_CARDS_H

#include <string>
#include <ostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <iostream>
using namespace std;

using std::string;

class Cards {
private:
    string *good;
    string *action;
public:

    Cards(string *good, string *action);

    Cards();

    virtual ~Cards();

    inline string *getGood() const {
        return good;
    }

    inline void setGood(string *good) {
        Cards::good = good;
    }

    inline string *getAction() const {
        return action;
    }

    inline void setAction(string *action) {
        Cards::action = action;
    }

    friend std::ostream &operator<<(std::ostream &os, const Cards &cards);

};

class Deck {
    std::vector<Cards> deck;

public:
    const Cards cards01 = Cards((string *) "Wild", (string *)"MOVE_OVER_WATER 2");
    const Cards cards02 = Cards((string *) "Wild", (string *)"MOVE_OVER_WATER 2");
    const Cards cards03 = Cards((string *) "Wild", (string *)"PLACE_NEW_ARMIES_ON_BOARD 2");
    const Cards cards04 = Cards((string *) "Crystal", (string *)"PLACE_NEW_ARMIES_ON_BOARD 2");
    const Cards cards05 = Cards((string *) "Crystal", (string *)"PLACE_NEW_ARMIES_ON_BOARD 2");
    const Cards cards06 = Cards((string *) "Crystal", (string *)"PLACE_NEW_ARMIES_ON_BOARD 2");
    const Cards cards07 = Cards((string *) "Crystal", (string *)"PLACE_NEW_ARMIES_ON_BOARD 1");
    const Cards cards08 = Cards((string *) "Crystal", (string *)"MOVE_OVER_LAND 2");
    const Cards cards09 = Cards((string *) "Rock", (string *)"MOVE_OVER_LAND 2");
    const Cards cards10 = Cards((string *) "Rock", (string *)"MOVE_OVER_WATER 2");
    const Cards cards11 = Cards((string *) "Rock", (string *)"MOVE_OVER_WATER 2");
    const Cards cards12 = Cards((string *) "Rock", (string *)"MOVE_OVER_WATER 3");
    const Cards cards13 = Cards((string *) "Rock", (string *)"PLACE_NEW_ARMIES_ON_BOARD 3");
    const Cards cards14 = Cards((string *) "Rock", (string *)"PLACE_NEW_ARMIES_ON_BOARD 3");
    const Cards cards15 = Cards((string *) "Rock", (string *)"PLACE_NEW_ARMIES_ON_BOARD 2 OR BUILD_A_CITY");
    const Cards cards16 = Cards((string *) "Carrot", (string *)"BUILD_A_CITY");
    const Cards cards17 = Cards((string *) "Carrot", (string *)"DESTROY_ARMY 1 AND PLACE_NEW_ARMIES_ON_BOARD 1");
    const Cards cards18 = Cards((string *) "Carrot", (string *)"PLACE_NEW_ARMIES_ON_BOARD 3");
    const Cards cards19 = Cards((string *) "Carrot", (string *)"MOVE_OVER_LAND 4");
    const Cards cards20 = Cards((string *) "Carrot", (string *)"MOVE_OVER_LAND 4");
    const Cards cards21 = Cards((string *) "Carrot", (string *)"PLACE_NEW_ARMIES_ON_BOARD 4 OR MOVE_OVER_LAND 2");
    const Cards cards22 = Cards((string *) "Carrot", (string *)"MOVE_OVER_LAND 5");
    const Cards cards23 = Cards((string *) "Carrot", (string *)"BUILD_A_CITY");
    const Cards cards24 = Cards((string *) "Carrot", (string *)"MOVE_OVER_WATER 3");
    const Cards cards25 = Cards((string *) "Carrot 2", (string *)"PLACE_NEW_ARMIES_ON_BOARD 3");
    const Cards cards26 = Cards((string *) "Tree", (string *)"MOVE_OVER_LAND 5");
    const Cards cards27 = Cards((string *) "Tree", (string *)"MOVE_OVER_LAND 6");
    const Cards cards28 = Cards((string *) "Tree", (string *)"PLACE_NEW_ARMIES_ON_BOARD 2 OR MOVE_OVER_LAND 3");
    const Cards cards29 = Cards((string *) "Tree", (string *)"DESTROY_ARMY 1 OR BUILD_A_CITY");
    const Cards cards30 = Cards((string *) "Tree", (string *)"PLACE_NEW_ARMIES_ON_BOARD 3");
    const Cards cards31 = Cards((string *) "Tree", (string *)"MOVE_OVER_WATER 4");
    const Cards cards32 = Cards((string *) "Tree", (string *)"MOVE_OVER_WATER 3");
    const Cards cards33 = Cards((string *) "Tree", (string *)"BUILD_A_CITY");
    const Cards cards34 = Cards((string *) "Anvil", (string *)"PLACE_NEW_ARMIES_ON_BOARD 3");
    const Cards cards35 = Cards((string *) "Anvil", (string *)"PLACE_NEW_ARMIES_ON_BOARD 3");
    const Cards cards36 = Cards((string *) "Anvil", (string *)"MOVE_OVER_WATER 3");
    const Cards cards37 = Cards((string *) "Anvil", (string *)"BUILD_A_CITY");
    const Cards cards38 = Cards((string *) "Anvil 2", (string *)"MOVE_OVER_LAND 4");
    const Cards cards39 = Cards((string *) "Anvil", (string *)"MOVE_OVER_LAND 5");
    const Cards cards40 = Cards((string *) "Anvil", (string *)"MOVE_OVER_LAND 4");
    const Cards cards41 = Cards((string *) "Anvil", (string *)"PLACE_NEW_ARMIES_ON_BOARD 3 OR MOVE_OVER_LAND 4");
    const Cards cards42 = Cards((string *) "Anvil", (string *)"PLACE_NEW_ARMIES_ON_BOARD 3 OR MOVE_OVER_LAND 3");


//    enum TypeOfGood {TREE, CARROT, ANVIL, CRYSTAL, ROCK};
//    enum Instruction { PLACE_NEW_ARMIES_ON_BOARD, MOVE_ARMIES, MOVE_OVER_LAND, MOVE_OVER_WATER, BUILD_A_CITY, DESTROY_ARMY, AND, OR };
    Deck();

    virtual ~Deck();
    void draw();

    friend std::ostream &operator<<(std::ostream &os, const Deck &deck);

};

class Hand {
    Cards cards;
public:
    Hand();

    virtual ~Hand();
    void exchange();
};

#endif //EIGHT_MINUTE_EMPIRE_CARDS_H
