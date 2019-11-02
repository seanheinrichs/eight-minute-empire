
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

    Cards(int numOfGood, string good, string action);

    virtual ~Cards();

    string *getGood() const;

    void setGood(string good);

    string *getAction() const;

    void setAction(string action);

    int *getNumOfGood() const;

    void setNumOfGood(int numOfGood);

    friend ostream &operator<<(ostream &os, const Cards &cards);

private:
    int* numOfGood;
    string* good;
    string* action;
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

static std::vector<Cards>* deck;

const Cards* cards01 = new Cards(1,"Wild", "MOVE_OVER_WATER 2");
const Cards* cards02 = new Cards(1,"Wild", "MOVE_OVER_WATER 2");
const Cards* cards03 = new Cards(1,"Wild", "PLACE_NEW_ARMIES_ON_BOARD 2");
const Cards* cards04 = new Cards(1,"Crystal", "PLACE_NEW_ARMIES_ON_BOARD 2");
const Cards* cards05 = new Cards(1,"Crystal", "PLACE_NEW_ARMIES_ON_BOARD 2");
const Cards* cards06 = new Cards(1,"Crystal", "PLACE_NEW_ARMIES_ON_BOARD 2");
const Cards* cards07 = new Cards(1,"Crystal", "PLACE_NEW_ARMIES_ON_BOARD 1");
const Cards* cards08 = new Cards(1,"Crystal", "MOVE_OVER_LAND 2");
const Cards* cards09 = new Cards(1,"Rock", "MOVE_OVER_LAND 2");
const Cards* cards10 = new Cards(1,"Rock", "MOVE_OVER_WATER 2");
const Cards* cards11 = new Cards(1,"Rock", "MOVE_OVER_WATER 2");
const Cards* cards12 = new Cards(1, "Rock", "MOVE_OVER_WATER 3");
const Cards* cards13 = new Cards(1,"Rock", "PLACE_NEW_ARMIES_ON_BOARD 3");
const Cards* cards14 = new Cards(1,"Rock", "PLACE_NEW_ARMIES_ON_BOARD 3");
const Cards* cards15 = new Cards(1,"Rock", "PLACE_NEW_ARMIES_ON_BOARD 2 OR BUILD_A_CITY");
const Cards* cards16 = new Cards(1,"Carrot", "BUILD_A_CITY");
const Cards* cards17 = new Cards(1,"Carrot", "DESTROY_ARMY 1 AND PLACE_NEW_ARMIES_ON_BOARD 1");
const Cards* cards18 = new Cards(1,"Carrot", "PLACE_NEW_ARMIES_ON_BOARD 3");
const Cards* cards19 = new Cards(1,"Carrot", "MOVE_OVER_LAND 4");
const Cards* cards20 = new Cards(1,"Carrot", "MOVE_OVER_LAND 4");
const Cards* cards21 = new Cards(1,"Carrot","PLACE_NEW_ARMIES_ON_BOARD 4 OR MOVE_OVER_LAND 2");
const Cards* cards22 = new Cards(1,"Carrot", "MOVE_OVER_LAND 5");
const Cards* cards23 = new Cards(1,"Carrot", "BUILD_A_CITY");
const Cards* cards24 = new Cards(1,"Carrot", "MOVE_OVER_WATER 3");
const Cards* cards25 = new Cards(2,"Carrot", "PLACE_NEW_ARMIES_ON_BOARD 3");
const Cards* cards26 = new Cards(1,"Tree", "MOVE_OVER_LAND 5");
const Cards* cards27 = new Cards(1,"Tree", "MOVE_OVER_LAND 6");
const Cards* cards28 = new Cards(1,"Tree", "PLACE_NEW_ARMIES_ON_BOARD 2 OR MOVE_OVER_LAND 3");
const Cards* cards29 = new Cards(1,"Tree", "DESTROY_ARMY 1 OR BUILD_A_CITY");
const Cards* cards30 = new Cards(1,"Tree", "PLACE_NEW_ARMIES_ON_BOARD 3");
const Cards* cards31 = new Cards(1,"Tree", "MOVE_OVER_WATER 4");
const Cards* cards32 = new Cards(1,"Tree", "MOVE_OVER_WATER 3");
const Cards* cards33 = new Cards(1,"Tree", "BUILD_A_CITY");
const Cards* cards34 = new Cards(1,"Anvil", "PLACE_NEW_ARMIES_ON_BOARD 3");
const Cards* cards35 = new Cards(1,"Anvil", "PLACE_NEW_ARMIES_ON_BOARD 3");
const Cards* cards36 = new Cards(1,"Anvil", "MOVE_OVER_WATER 3");
const Cards* cards37 = new Cards(1,"Anvil", "BUILD_A_CITY");
const Cards* cards38 = new Cards(2,"Anvil", "MOVE_OVER_LAND 4");
const Cards* cards39 = new Cards(1,"Anvil", "MOVE_OVER_LAND 5");
const Cards* cards40 = new Cards(1,"Anvil", "MOVE_OVER_LAND 4");
const Cards* cards41 = new Cards(1,"Anvil", "PLACE_NEW_ARMIES_ON_BOARD 3 OR MOVE_OVER_LAND 4");
const Cards* cards42 = new Cards(1,"Anvil", "PLACE_NEW_ARMIES_ON_BOARD 3 OR MOVE_OVER_LAND 3");

#endif //EIGHT_MINUTE_EMPIRE_CARDS_H
