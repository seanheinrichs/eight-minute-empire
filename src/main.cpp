#include <iostream>
#include "Cards.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
////    Cards* c1 = new Cards(2,"aa", "bb");
//    Cards* c1 = new Cards(1,"Wild", "MOVE_OVER_WATER 2");
//    Cards* c2 = new Cards(2,"Wild", "MOVE_OVER_WATER 2");
//    Cards* c3 = new Cards(3,"Wild", "PLACE_NEW_ARMIES_ON_BOARD 2");
//    Cards* c4 = new Cards(4,"Wild", "MOVE_OVER_WATER 2");
//    Cards* c5 = new Cards(5,"Wild", "MOVE_OVER_WATER 2");
//    Cards* c6 = new Cards(6,"Wild", "PLACE_NEW_ARMIES_ON_BOARD 2");
//    Cards* c7 = new Cards(7,"Wild", "MOVE_OVER_WATER 2");
//    Cards* c8 = new Cards(8,"Wild", "MOVE_OVER_WATER 2");
//    Cards* c9 = new Cards(9,"Wild", "PLACE_NEW_ARMIES_ON_BOARD 2");
//    Cards* c10 = new Cards(10,"Wild", "MOVE_OVER_WATER 2");
//    Cards* c11 = new Cards(11,"Wild", "MOVE_OVER_WATER 2");
//    Cards* c12 = new Cards(12,"Wild", "PLACE_NEW_ARMIES_ON_BOARD 2");
//    cout << *c1 << endl;
//    cout << *c1->getGood() << endl;
//    cout << *c1->getAction() << endl;

//    c1->setAction("ActionA");
//    cout << *c1->getAction() << endl;
//    c1->setGood("new_good");
//    cout << *c1->getGood() << endl;
//    c1->setNumOfGood(100);
//    cout << *c1->getNumOfGood() << endl;

//    std::vector<Cards*> d;
//    d.emplace_back(c1);
//    d.emplace_back(c2);
//    d.emplace_back(c3);
//
//     auto k = d.back();
//    cout<< *k <<endl;
//    std::vector<Cards*> *dd = new Cards();
//    dd->emplace_back(c4);
//    dd->emplace_back(c5);
//    dd->emplace_back(c6);
//    auto kk = dd->back();
//    cout<< *kk <<endl;
//    vector<Cards*> ddd {c1, c2, c3};
//    auto kk = ddd.back();
//    cout<< *kk <<endl;
//    int index = 3;
//    auto *d1 = new vector<Cards*>();
//    d1->emplace_back(c1);
//    d1->emplace_back(c2);
//    d1->emplace_back(c3);
//    d1->emplace_back(c4);
//    d1->erase(d1->begin()+index);
//    d1->emplace_back(c5);
//    auto k1 = d1->back();
//    cout<< *k1 << endl;
//    for (auto it = d1->begin(); it != d1->end(); ++it){
//        cout << "     " << **it << endl;
//    }


//    vector<int> v {10, 20, 30};
//    for (int x: v){
//        cout << x << " ";
//    }
    Deck deck1;
    Deck::TopBoard tb;
    tb.setTopBoard(deck1);
    tb.getTopBoard();
    deck1.displayTopBoard(tb.topBoard);
    std::vector<Cards*> *hand = new std::vector<Cards*>();
    deck1.exchange1(*hand, deck1);
    deck1.exchange1(*hand, deck1);
    deck1.displayTopBoard(tb.topBoard);

//    Deck deck1;
//    std::vector<Cards*> tb = deck1.topBoardGenetor(deck1);
//    std::vector<Cards*> *hand = new std::vector<Cards*>();
//    deck1.exchange(*hand, tb, deck1);
//    deck1.exchange(*hand, tb, deck1);
//    deck1.exchange(*hand, tb, deck1);
//    deck1.exchange(*hand, tb, deck1);
//    deck1.displayTopBoard(tb);
//    deck1.exchange(*hand, tb, deck1);
//    deck1.displayTopBoard(tb);
//    deck1.exchange(hand, topBoard, deck1);
//    deck1.displayTopBoard(topBoard);
//    deck1.exchange(hand, topBoard, deck1);
//    deck1.displayTopBoard(topBoard);
//    deck1.exchange(hand, topBoard, deck1);
//    deck1.displayTopBoard(topBoard);
//    deck1.exchange(hand, topBoard, deck1);
//    deck1.displayTopBoard(topBoard);
//    deck1.updateTopBoard(3, topBoard, deck1);
//    deck1.displayTopBoard(topBoard);
//    deck1.updateTopBoard(3, tb, deck1);
//    deck1.displayTopBoard(tb);
//    deck1.updateTopBoard(3, topBoard, deck1);
//    deck1.displayTopBoard(topBoard);
//    deck1.displayHand(*hand);

//    Deck *deck2 = new Deck();
//    std::vector<Cards*> *top = deck2->topBoardGenetor(*deck2);
//    std::vector<Cards*> *hand1;
//    deck2->exchange(*hand1, top, *deck2);
//    deck2->displayTopBoard(top);
//    deck2->exchange(hand1, top, *deck2);
//    deck2->displayTopBoard(top);
//    deck2->exchange(hand1, top, *deck2);
//    deck2->displayTopBoard(top);
//    deck2->displayHand(hand1);

//    auto *d1 = new vector<Cards*>();
//    auto t1 = new vector<Cards*>();
//    d1->emplace_back(c1);
//    d1->emplace_back(c2);
//    d1->emplace_back(c3);
//    d1->emplace_back(c4);
//    d1->emplace_back(c5);
//    d1->emplace_back(c6);
//    d1->emplace_back(c7);
//    d1->emplace_back(c8);
//    d1->emplace_back(c9);
//    d1->emplace_back(c10);
//    d1->emplace_back(c11);
//    d1->emplace_back(c12);
//    int index = 3;
//    d1->erase(d1->begin()+index);
//    d1->emplace_back(c5);
//    auto k1 = d1->back();
//    cout<< *k1 << endl;
//    for (auto it = d1->begin(); it != d1->end(); ++it){
//        cout << "     " << **it << endl;}
//    for (auto i = 0; i < 6; i++) {
//        t1.emplace_back(c1);
//    }
//    t1->emplace_back(c1);
//    t1->emplace_back(c2);
//    t1->emplace_back(c3);
//    auto t2 = t1;
//    t2->erase(t2->begin()+1);
//    for (auto it = t1->begin(); it != t1->end(); ++it){
//        cout << "     " << **it << endl;}
    return 0;
}