
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
public:
    Cards();

    Cards(const string &good, const string &action);

    virtual ~Cards();

    const string &getGood() const;

    void setGood(const string &good);

    const string &getAction() const;

    void setAction(const string &action);

    friend ostream &operator<<(ostream &os, const Cards &cards);

private:
    string good;
    string action;
};

class Deck {

public:
    Deck();

    virtual ~Deck();
    void draw();

    class Hand {
    public:
        Hand();

        virtual ~Hand();

        int *getCost() const;

        void setCost(int *cost);

        int *getPosition() const;

        void setPosition(int position);

    private:
        std::vector<Cards> shuffledCards;
        std::vector<Cards> hand;
        std::vector<Cards> playerHand1;

    public:
        int* cost;
        int* position;
        int posArray[6] = { 0, 1, 1, 2, 2, 3 };
        void exchange();
    };
};

static std::vector<Cards> deck;

const Cards cards01 = Cards("Wild", "MOVE_OVER_WATER 2");
const Cards cards02 = Cards("Wild", "MOVE_OVER_WATER 2");
const Cards cards03 = Cards("Wild", "PLACE_NEW_ARMIES_ON_BOARD 2");
const Cards cards04 = Cards("Crystal", "PLACE_NEW_ARMIES_ON_BOARD 2");
const Cards cards05 = Cards("Crystal", "PLACE_NEW_ARMIES_ON_BOARD 2");
const Cards cards06 = Cards("Crystal", "PLACE_NEW_ARMIES_ON_BOARD 2");
const Cards cards07 = Cards("Crystal", "PLACE_NEW_ARMIES_ON_BOARD 1");
const Cards cards08 = Cards("Crystal", "MOVE_OVER_LAND 2");
const Cards cards09 = Cards("Rock", "MOVE_OVER_LAND 2");
const Cards cards10 = Cards("Rock", "MOVE_OVER_WATER 2");
const Cards cards11 = Cards("Rock", "MOVE_OVER_WATER 2");
const Cards cards12 = Cards("Rock", "MOVE_OVER_WATER 3");
const Cards cards13 = Cards("Rock", "PLACE_NEW_ARMIES_ON_BOARD 3");
const Cards cards14 = Cards("Rock", "PLACE_NEW_ARMIES_ON_BOARD 3");
const Cards cards15 = Cards("Rock", "PLACE_NEW_ARMIES_ON_BOARD 2 OR BUILD_A_CITY");
const Cards cards16 = Cards("Carrot", "BUILD_A_CITY");
const Cards cards17 = Cards("Carrot", "DESTROY_ARMY 1 AND PLACE_NEW_ARMIES_ON_BOARD 1");
const Cards cards18 = Cards("Carrot", "PLACE_NEW_ARMIES_ON_BOARD 3");
const Cards cards19 = Cards("Carrot", "MOVE_OVER_LAND 4");
const Cards cards20 = Cards("Carrot", "MOVE_OVER_LAND 4");
const Cards cards21 = Cards("Carrot","PLACE_NEW_ARMIES_ON_BOARD 4 OR MOVE_OVER_LAND 2");
const Cards cards22 = Cards("Carrot", "MOVE_OVER_LAND 5");
const Cards cards23 = Cards("Carrot", "BUILD_A_CITY");
const Cards cards24 = Cards("Carrot", "MOVE_OVER_WATER 3");
const Cards cards25 = Cards("Carrot 2", "PLACE_NEW_ARMIES_ON_BOARD 3");
const Cards cards26 = Cards("Tree", "MOVE_OVER_LAND 5");
const Cards cards27 = Cards("Tree", "MOVE_OVER_LAND 6");
const Cards cards28 = Cards("Tree", "PLACE_NEW_ARMIES_ON_BOARD 2 OR MOVE_OVER_LAND 3");
const Cards cards29 = Cards("Tree", "DESTROY_ARMY 1 OR BUILD_A_CITY");
const Cards cards30 = Cards("Tree", "PLACE_NEW_ARMIES_ON_BOARD 3");
const Cards cards31 = Cards("Tree", "MOVE_OVER_WATER 4");
const Cards cards32 = Cards("Tree", "MOVE_OVER_WATER 3");
const Cards cards33 = Cards("Tree", "BUILD_A_CITY");
const Cards cards34 = Cards("Anvil", "PLACE_NEW_ARMIES_ON_BOARD 3");
const Cards cards35 = Cards("Anvil", "PLACE_NEW_ARMIES_ON_BOARD 3");
const Cards cards36 = Cards("Anvil", "MOVE_OVER_WATER 3");
const Cards cards37 = Cards("Anvil", "BUILD_A_CITY");
const Cards cards38 = Cards("Anvil 2", "MOVE_OVER_LAND 4");
const Cards cards39 = Cards("Anvil", "MOVE_OVER_LAND 5");
const Cards cards40 = Cards("Anvil", "MOVE_OVER_LAND 4");
const Cards cards41 = Cards("Anvil", "PLACE_NEW_ARMIES_ON_BOARD 3 OR MOVE_OVER_LAND 4");
const Cards cards42 = Cards("Anvil", "PLACE_NEW_ARMIES_ON_BOARD 3 OR MOVE_OVER_LAND 3");

#endif //EIGHT_MINUTE_EMPIRE_CARDS_H
