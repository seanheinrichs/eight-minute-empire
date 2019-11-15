#ifndef EIGHT_MINUTE_EMPIRE_CARDS_H
#define EIGHT_MINUTE_EMPIRE_CARDS_H

#include "../Player/Player.h"
#include <string>
#include <ostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <iostream>
using namespace std;

// Forward Declaration
class Player;

class Cards
{

private:
    int* numOfGood;
    string* good;
    string* action;

public:
    // constructors
    Cards();
    Cards(int numOfGood, string good, string action);

    // deconstructor
    virtual ~Cards();

    // accessors
    string *getGood() const;
    string *getAction() const;
    int *getNumOfGood() const;

    // mutators
    void setGood(string good);
    void setAction(string action);
    void setNumOfGood(int numOfGood);

    // operator overides
    friend ostream &operator<<(ostream &os, const Cards &cards);
};

class Deck
{

private:
    int* cost;
    int* position;
    int posArray[6] = {0, 1, 1, 2, 2, 3};
    // std::vector<Cards*> topBoard;

public:
    // constructor
    Deck();

    // deconstructor
    virtual ~Deck();

    // gameplay methods
    Cards* draw();
    std::vector<Cards*> topBoardGenetor(Deck &deck);
    void displayTopBoard(std::vector<Cards*> &topBoard);
    void updateTopBoard(int &position, std::vector<Cards*> &topBoard, Deck &deck);
    std::vector<Cards*> handGenetor(Cards* &card);
    void displayHand(std::vector<Cards*> &hand);
    void exchange(Player &player, std::vector<Cards*> &topBoard, Deck &deck);
};

static std::vector<Cards*> deck;
// static std::vector<Cards*> topBoard;
#endif //EIGHT_MINUTE_EMPIRE_CARDS_H
