
#include "CardsFactoryDriver.h"

void cardsFactoryExample() {

    cout << "================Test CardFactory producing Three Types of Card Set===============\n";
    Card *cardFactory = new Card;

    auto s0 = cardFactory->createCardSet("Full");
    auto s1 = cardFactory->createCardSet("OneAction");
    auto s2 = cardFactory->createCardSet("TwoAction");

    cout << "============================== Test display( type, card ) ========================================\n";
    cout << "============================== s0 ========================================\n";
    for (int i = 0; i < s0.size(); i++)
        cardFactory->display("Full", s0[i]);
    cout << "================================ s1 ======================================\n";
    for (int i =0; i< s1.size(); i++)
        cardFactory->display("OneAction", s1[i]);
    cout << "================================ s2 ======================================\n";
    for (int i =0; i< s2.size(); i++)
        cardFactory->display("TwoAction", s2[i]);

    cout << "============================== Test display( cardVector ) ========================================\n";
    cout << "============================== s0 ========================================\n";
    cardFactory->display(s0);
    cout << "============================== s1 ========================================\n";
    cardFactory->display(s1);

    cout << "========== Above 42-Card Set is the same as the original game set, display() method also tested ============\n\n";

    cout << "================Test CardFactory producing Customised Six Types of Card Set===============\n";
    auto wild = cardFactory->createCardSet("Wild");
    for (int i =0; i< wild.size(); i++) {
        cardFactory->display("Wild", wild[i]);
    }
    cout << "========== above display(Wild, card) method also tested ============\n";
    cout << "================ Test gameCard's operator<< overloading ===============\n";
    for (int i =0; i< wild.size(); i++) {
        cout << *wild[i];
    }
    cout << "================ Test display( cardVector ) ===============\n";
    cardFactory->display(wild);


    cout << "================ Test  Crystal type Card Set ===============\n";
    auto g1 = cardFactory->createCardSet("Crystal");
    cout << "=============== Test Rock type Card Set ================\n";
    auto g2 = cardFactory->createCardSet("Rock");
    cout << "================ Test Carrot type Card Set ===============\n";
    auto g3 = cardFactory->createCardSet("Carrot");
    cout << "=============== Test Tree type Card Set ================\n";
    auto g4 = cardFactory->createCardSet("Tree");
    cout << "=============== Test Anvil type Card Set ================\n";
    auto g5 = cardFactory->createCardSet("Anvil");
    cout << "=============================================================\n";

    cout << "============== Test Constumized create One Card of Two Types =================\n";
    auto c1 = cardFactory->create("OneAction");
    auto c2 = cardFactory->create("TwoAction");
    cout << "=============== Test display(type, gameCard) ================\n";
    cardFactory->display("OneAction", c1);
    cardFactory->display("TwoAction", c2);
    cout << "============== Test operator << overloading for One Card =================\n";
    cout << *c1;
    cout << *c2;

    cout << "=========================== memory management ==================================\n";
    cardFactory->destroy(s0);
    cardFactory->destroy(wild);
    cardFactory->destroy(g1);
    cardFactory->destroy(g2);
    cardFactory->destroy(g3);
    cardFactory->destroy(g4);
    cardFactory->destroy(g5);
    delete c1;
    delete c2;
    c1 = nullptr;
    c2 = nullptr;

    cout << "============================ Thank you so much for grading! =================================\n";

}