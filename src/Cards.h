//
// Created by steve on 11/2/2019.
//

#ifndef CARDS_CARDS_H
#define CARDS_CARDS_H

#include <string>
#include <ostream>
#include <vector>

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
    std::vector<Cards*> topBoardGenetor(Deck deck);
    void displayTopBoard(std::vector<Cards*> topBoard);
    void updateTopBoard(int position, std::vector<Cards*> topBoard, Deck deck);
    std::vector<Cards*> handGenetor(Cards* card);
    void displayHand(std::vector<Cards*> hand);
    int* cost;
    int* position;
    int posArray[6] = {0, 1, 1, 2, 2, 3};
    void exchange(std::vector<Cards*> hand,  std::vector<Cards*> topBoard, Deck deck);
    class TopBoard {
    public:
        TopBoard();

        virtual ~TopBoard();

        const vector<Cards *> &getTopBoard() const;

        void setTopBoard(Deck deck);

        std::vector<Cards*> topBoard;

    };
    void exchange1(std::vector<Cards*> hand,  Deck deck);


};
static std::vector<Cards*> deck;
static Deck::TopBoard topBoard;
//static std::vector<Cards*> topBoard;


#endif //CARDS_CARDS_H
