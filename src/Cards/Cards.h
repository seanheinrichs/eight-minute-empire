
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
private:

public:
    Deck();

    virtual ~Deck();
    Cards* draw();
    std::vector<Cards*> topBoard;
    std::vector<Cards*> topBoardGenetor(Deck deck);
    std::vector<Cards*> handGenetor(Cards* card);
    int* cost;
    int* position;
    int posArray[6] = {0, 1, 1, 2, 2, 3};
    std::vector<Cards*> exchange(std::vector<Cards*> hand, std::vector<Cards*> topBoard, Deck deck);
};
static std::vector<Cards*> deck;

#endif //EIGHT_MINUTE_EMPIRE_CARDS_H
