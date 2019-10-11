
#include "Cards.h"


Cards::~Cards() {

}

Good *Cards::getGood() const {
    return good;
}

void Cards::setGood(Good *good) {
    Cards::good = good;
}

Action *Cards::getAction() const {
    return action;
}

void Cards::setAction(Action *action) {
    Cards::action = action;
}

Cards::Cards(Good *good, Action *action) : good(good), action(action) {}


Deck::Deck() {}

Deck::~Deck() {

}

void Deck::draw() {

}

Hand::Hand() {}

Hand::~Hand() {

}

void Hand::exchange() {

}


Good::Good() {}

Good::~Good() {

}

Good::Good(int *numOfGood, TypeOfGood *typeOfGood, int *points) : numOfGood(numOfGood), typeOfGood(typeOfGood), points(points) {}

std::ostream &operator<<(std::ostream &os, const Good &good) {
    os << "numOfGood: " << good.numOfGood << " points: " << good.points << " typeOfGood: " << good.typeOfGood;
    return os;
}

Action::Action() {}

Action::~Action() {

}

std::ostream &operator<<(std::ostream &os, const Action &action) {
    os << "numOfMoves: " << action.numOfMoves << " instruction: " << action.instruction;
    return os;
}

Action::Action(int *numOfMoves, string *instruction) : numOfMoves(numOfMoves), instruction(instruction) {}


