
#pragma once
#ifndef EIGHT_MINUTE_EMPIRE_CARDS_H
#define EIGHT_MINUTE_EMPIRE_CARDS_H

#include <string>
#include <ostream>
#include <vector>

using std::string;

class Good {

private:
    int *numOfGood, *points;
    enum TypeOfGood {TREE, CARROT, ANVIL, CRYSTAL, ROCK};
    TypeOfGood *typeOfGood;
public:
    Good();

    Good(int *numOfGood, TypeOfGood *typeOfGood, int *points);

    virtual ~Good();

    inline int *getNumOfGood() const {
        return numOfGood;
    }

    inline void setNumOfGood(int *numOfGood) {
        Good::numOfGood = numOfGood;
    }

    inline int *getPoints() const {
        return points;
    }

    inline void setPoints(int *points) {
        Good::points = points;
    }

    inline TypeOfGood *getTypeOfGood() const {
        return typeOfGood;
    }

    inline void setTypeOfGood(TypeOfGood *typeOfGood) {
        Good::typeOfGood = typeOfGood;
    }

    friend std::ostream &operator<<(std::ostream &os, const Good &good);

    friend class Cards;
};

class Action {

private:
    int *numOfMoves;
    string *instruction;
//    enum Instruction { PLACE_NEW_ARMIES_ON_BOARD, MOVE_ARMIES, MOVE_OVER_LAND, MOVE_OVER_WATER, BUILD_A_CITY, DESTROY_ARMY, AND, OR };
public:
    Action();

    Action(int *numOfMoves, string *instruction);

    virtual ~Action();

    inline int *getNumOfMoves() const {
        return numOfMoves;
    }

    inline void setNumOfMoves(int *numOfMoves) {
        Action::numOfMoves = numOfMoves;
    }

    inline string *getInstruction() const {
        return instruction;
    }

    inline void setInstruction(string *instruction) {
        Action::instruction = instruction;
    }

    friend std::ostream &operator<<(std::ostream &os, const Action &action);

    friend class Cards;

};

class Cards {
private:
    Good *good;
    Action *action;
public:
    Cards();

    Cards(Good *good, Action *action);

    virtual ~Cards();

    Good *getGood() const;

    void setGood(Good *good);

    Action *getAction() const;

    void setAction(Action *action);
};

class Deck {
    Cards cards;
    std::vector<Cards> deck;
public:

    Deck();

    virtual ~Deck();
    void draw();

};

class Hand {
    Cards cards;
public:
    Hand();

    virtual ~Hand();
    void exchange();
};

#endif //EIGHT_MINUTE_EMPIRE_CARDS_H
