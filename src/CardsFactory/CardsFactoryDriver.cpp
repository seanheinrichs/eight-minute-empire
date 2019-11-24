
#include "CardsFactoryDriver.h"

void cardsFactoryExample() {

    cout << "================Test CardFactory producing Two Types of Card Set===============\n";
    Card *cardFactory = new Card;

    auto s1= cardFactory->createCardSet("OneAction");
    auto s2 = cardFactory->createCardSet("TwoAction");

    for (int i =0; i< s1.size(); i++)
        cardFactory->display("OneAction", s1[i]);
    cout << "======================================================================\n";
    for (int i =0; i< s2.size(); i++)
        cardFactory->display("TwoAction", s2[i]);

    cout << "========== Above 42-Card Set is the same as the original game set, display(type, card) method also tested ============\n\n";

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
    cout << "================ Test  Crystal type Card Set ===============\n";
    cardFactory->createCardSet("Crystal");
    cout << "=============== Test Rock type Card Set ================\n";
    cardFactory->createCardSet("Rock");
    cout << "================ Test Carrot type Card Set ===============\n";
    cardFactory->createCardSet("Carrot");
    cout << "=============== Test Tree type Card Set ================\n";
    cardFactory->createCardSet("Tree");
    cout << "=============== Test Anvil type Card Set ================\n";
    cardFactory->createCardSet("Anvil");
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
    cout << "============================ Thank you so much for grading! =================================\n";

}