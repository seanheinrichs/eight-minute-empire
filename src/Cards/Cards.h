
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


class Cards {
public:
    Cards();

    Cards(int numOfGood, string good, string action);

    string *getGood() const;

    void setGood(string good);

    string *getAction() const;

    void setAction(string action);

    virtual ~Cards();

    friend ostream &operator<<(ostream &os, const Cards &cards);

    int *getNumOfGood() const;

    void setNumOfGood(int numOfGood);

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
//    std::vector<Cards*> topBoard;
    std::vector<Cards*> topBoardGenetor(Deck &deck);
    void displayTopBoard(std::vector<Cards*> &topBoard);
    void updateTopBoard(int &position, std::vector<Cards*> &topBoard, Deck &deck);
    std::vector<Cards*> handGenetor(Cards* &card);
    void displayHand(std::vector<Cards*> &hand);
    void exchange(std::vector<Cards*> &hand,  std::vector<Cards*> &topBoard, Deck &deck);
    int* cost;
    int* position;
    int posArray[6] = {0, 1, 1, 2, 2, 3};



};
static std::vector<Cards*> deck;
//static std::vector<Cards*> topBoard;
#endif //EIGHT_MINUTE_EMPIRE_CARDS_H
