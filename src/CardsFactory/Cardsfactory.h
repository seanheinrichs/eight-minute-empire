#pragma once

#include <string>
#include <iostream>
#include "Cards.h"

using namespace std;

// refactoring the original Card class, an easy-to-use version
class gameCard {
public:
    gameCard();
    ~gameCard();

    gameCard(int numOfGood, string good, string action, int numOfAction);
    gameCard(int numOfGood, string good, string action1, int numOfAction1, bool isAnd, string action2, int numOfAction2);

    int *getNumOfGood() const;

    string *getGood() const;

    string *getAction() const;

    int *getNumOfAction() const;

    string *getAction1() const;

    string *getAction2() const;

    int *getNumOfAction1() const;

    int *getNumOfAction2() const;

    bool *getIsAnd() const;

    void setNumOfGood(int numOfGood);

    void setGood(string good);

    void setAction(string action);

    void setNumOfAction(int numOfAction);

    void setAction1(string action1);

    void setAction2(string action2);

    void setNumOfAction1(int numOfAction1);

    void setNumOfAction2(int numOfAction2);

    void setIsAnd(bool isAnd);

    friend ostream &operator<<(ostream &os, const gameCard &card);


private:
    int* numOfGood;
    string* good;
    string* action;
    int* numOfAction;
    string* action1;
    string* action2;
    int* numOfAction1;
    int* numOfAction2;
    bool* isAnd;

};

// an interface of factory
class Cardsfactory {
public:
    virtual gameCard* create(string type) = 0;

    virtual std::vector<gameCard*> createCardSet(string type) = 0;

    virtual void display(string type, gameCard* card) = 0;
};

// a concrete Card factory
class Card : public Cardsfactory {
public:
    // produce one customized card with two types: One Action and Two Action
    gameCard* create(string type);

    // produces a set of gameCards with 8 types of options.
    // "OneAction" type and "TwoAction" type :produced a set of 42 gameCards as same as the original game set.
    // "Wild" type, "Crystal" type, "Rock" type, "Carrot" type, "Tree" type, "Anvil" type are sets of customized gameCard set,
    // which clients can customized the sizes of "OneAction" Card set and "TwoAction" Card set.
    std::vector<gameCard*> createCardSet(string type);

    // displays the card generated from two gameCard constructor with different signatures
    // especially works for the original game set: the "OneAction" type and "TwoAction" type,
    // since they are generated from two gameCard constructor with different signatures
    // However, using operator<< overloading of class gameCard can omit this display( ) method.
    // Therefore, the purpose of this function just for practising factory pattern
    void display(string type, gameCard* card);

};
