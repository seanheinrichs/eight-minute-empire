#include "Cardsfactory.h"
#include <string>
using namespace std;

gameCard::gameCard() {
    numOfGood = new int(0);
    good = new string("");
    action = new string("");
    numOfAction = new int(0);
    numOfAction1 = new int(0);
    numOfAction2 = new int(0);
    action1 = new string("");
    action2 = new string("");
    isAnd = new bool(false);
}

gameCard::~gameCard() {
    if(numOfGood) {
        delete numOfGood;
        numOfGood = nullptr;
    }
    if(good) {
        delete good;
        good = nullptr;
    }
    if(action) {
        delete action;
        action = nullptr;
    }
    if(action1) {
        delete action1;
        action1 = nullptr;
    }
    if(action2) {
        delete action2;
        action2 = nullptr;
    }
    if(numOfAction) {
        delete numOfAction;
        numOfAction = nullptr;
    }
    if(numOfAction1) {
        delete numOfAction1;
        numOfAction1 = nullptr;
    }
    if(numOfAction2) {
        delete numOfAction2;
        numOfAction2 = nullptr;
    }
    if(isAnd) {
        delete isAnd;
        isAnd = nullptr;
    }
}

gameCard::gameCard(int numOfGood, string good, string action, int numOfAction) :
        numOfGood(new int(numOfGood)), good(new string(good)), action(new string(action)),
        numOfAction(new int(numOfAction)){}

gameCard::gameCard(int numOfGood, string good, string action1, int numOfAction1, bool isAnd, string action2,
                   int numOfAction2) :
        numOfGood(new int(numOfGood)), good(new string(good)), action1(new string(action1)),
        numOfAction1(new int(numOfAction1)), isAnd(new bool(isAnd)), action2(new string(action2)),
        numOfAction2(new int(numOfAction2)) {}

gameCard::gameCard(int numOfGood, string good, string action, int numOfAction, string action1, int numOfAction1,
                   bool isAnd, string action2, int numOfAction2) :
                   numOfGood(new int(numOfGood)), good(new string(good)), action(new string(action)),
                   numOfAction(new int(numOfAction)), action1(new string(action1)),
                   numOfAction1(new int(numOfAction1)), isAnd(new bool(isAnd)), action2(new string(action2)),
                   numOfAction2(new int(numOfAction2)) {}

int *gameCard::getNumOfGood() const {
    return numOfGood;
}

string *gameCard::getGood() const {
    return good;
}

string *gameCard::getAction() const {
    return action;
}

int *gameCard::getNumOfAction() const {
    return numOfAction;
}

string *gameCard::getAction1() const {
    return action1;
}

string *gameCard::getAction2() const {
    return action2;
}

int *gameCard::getNumOfAction1() const {
    return numOfAction1;
}

int *gameCard::getNumOfAction2() const {
    return numOfAction2;
}

bool *gameCard::getIsAnd() const {
    return isAnd;
}

void gameCard::setNumOfGood(int numOfGood) {
    gameCard::numOfGood = new int(numOfGood);
}

void gameCard::setGood(string good) {
    gameCard::good = new string(good);
}

void gameCard::setAction(string action) {
    gameCard::action = new string(action);
}

void gameCard::setNumOfAction(int numOfAction) {
    gameCard::numOfAction = new int(numOfAction);
}

void gameCard::setAction1(string action1) {
    gameCard::action1 = new string(action1);
}

void gameCard::setAction2(string action2) {
    gameCard::action2 = new string(action2);
}

void gameCard::setNumOfAction1(int numOfAction1) {
    gameCard::numOfAction1 = new int(numOfAction1);
}

void gameCard::setNumOfAction2(int numOfAction2) {
    gameCard::numOfAction2 = new int(numOfAction2);
}

void gameCard::setIsAnd(bool isAnd) {
    gameCard::isAnd = new bool(isAnd);
}

// operator<< overloading works for two versions of gameCard constructor
ostream &operator<<(ostream &os, const gameCard &card) {

    os << " : " << *card.numOfGood << " " << *card.good
       << " " << (*card.action != "" ? *card.action : "");

    if (*card.numOfAction != 0)
        os << " " << *card.numOfAction;
    else {
        os << " " << *card.action1 << " " << *card.numOfAction1
           << " " << (*card.isAnd ? "AND" : "OR")
           << " " << *card.action2
           << " " << *card.numOfAction2;
    }
    os << endl;

    return os;
}

gameCard *Card::create(string type) {
    std::string actions[5];
    actions[0] = "PLACE_NEW_ARMIES_ON_BOARD";
    actions[1] = "MOVE_OVER_GROUND";
    actions[2] = "MOVE_OVER_WATER";
    actions[3] = "BUILD_A_CITY";
    actions[4] = "DESTROY_ARMY";

    std::string goods[6];
    goods[0] = "Crystal";
    goods[1] = "Rock";
    goods[2] = "Carrot";
    goods[3] = "Tree";
    goods[4] = "Anvil";
    goods[5] = "Wild";

    if (type == "OneAction") {
        int good, numOfGood, action, numOfAction;
        // client customized good type
        for (int i=0; i < 6; i++) {
            std::cout << i+1 << ") " << goods[i] << endl;
        }
        std::cout << "Please indicate which good type of card which you would like to produce, \n";
        std::cout << "enter the corresponding integer of each good between 1 and 6: ";
        std::cin >> good;
        while (good < 1 || good > 6) {
            std::cout << "Invalid input: " << good << ". Please enter an integer between 1 and 6: ";
            std::cin >> good;
        }

        // client customized number of good
        std::cout << "Please indicate the number of good,\n";
        std::cout << "enter an integer either 1 or 2: ";
        std::cin >> numOfGood;
        while (numOfGood < 1 || numOfGood > 2) {
            std::cout << "Invalid input: " << numOfGood << ". Please enter an integer  either 1 or 2: ";
            std::cin >> numOfGood;
        }

        // client customized action
        for (int i=0; i < 5; i++) {
            std::cout << i+1 << ") " << actions[i] << endl;
        }
        std::cout << "Please indicate the action of this card, \n";
        std::cout << "enter the corresponding integer of each action between 1 and 5: ";
        std::cin >> action;
        while (action < 1 || action > 5) {
            std::cout << "Invalid input: " << action << ". Please enter an integer between 1 and 5: ";
            std::cin >> action;
        }

        // client customized number of action
        std::cout << "Please indicate the unit of action,\n";
        std::cout << "enter an integer between 1 and 6: ";
        std::cin >> numOfAction;
        while (numOfAction < 1 || numOfAction > 6) {
            std::cout << "Invalid input: " << numOfAction << ". Please enter an integer between 1 and 6: ";
            std::cin >> numOfAction;
        }

        gameCard* oneActionCard = new gameCard;

        oneActionCard->setGood(goods[good-1]);
        oneActionCard->setNumOfGood(numOfGood);
        oneActionCard->setAction(actions[action-1]);
        oneActionCard->setNumOfAction(numOfAction);

        std::cout << "\nOneAction CardFactory produced one card successfully"<< *oneActionCard << endl;
        return oneActionCard;
    }
    else if (type == "TwoAction") {

        int good, numOfGood, action, numOfAction, action2, numOfAction2, isAnd;
        // client customized good type
        for (int i=0; i < 6; i++) {
            std::cout << i+1 << ") " << goods[i] << endl;
        }
        std::cout << "Please indicate which good type of card which you would like to produce, \n";
        std::cout << "enter the corresponding integer of each good between 1 and 6: ";
        std::cin >> good;
        while (good < 1 || good > 6) {
            std::cout << "Invalid input: " << good << ". Please enter an integer between 1 and 6: ";
            std::cin >> good;
        }

        // client customized number of good
        std::cout << "Please indicate the number of good,\n";
        std::cout << "enter an integer either 1 or 2: ";
        std::cin >> numOfGood;
        while (numOfGood < 1 || numOfGood > 2) {
            std::cout << "Invalid input: " << numOfGood << ". Please enter an integer either 1 or 2: ";
            std::cin >> numOfGood;
        }

        // client customized action
        for (int i=0; i < 5; i++) {
            std::cout << i+1 << ") " << actions[i] << endl;
        }
        std::cout << "Please indicate the First action of this card, \n";
        std::cout << "enter the corresponding integer of each action between 1 and 5: ";
        std::cin >> action;
        while (action < 1 || action > 5) {
            std::cout << "Invalid input: " << action << ". Please enter an integer between 1 and 5: ";
            std::cin >> action;
        }

        // client customized number of action
        std::cout << "Please indicate the unit of the Fisrt action,\n";
        std::cout << "enter an integer between 1 and 6: ";
        std::cin >> numOfAction;
        while (numOfAction < 1 || numOfAction > 6) {
            std::cout << "Invalid input: " << numOfAction << ". Please enter an integer between 1 and 6: ";
            std::cin >> numOfAction;
        }

        // client customized action2
        for (int i=0; i < 5; i++) {
            std::cout << i+1 << ") " << actions[i] << endl;
        }
        std::cout << "Please indicate the Second action of this card, \n";
        std::cout << "enter the corresponding integer of each action between 1 and 5: ";
        std::cin >> action2;
        while (action2 < 1 || action2 > 5) {
            std::cout << "Invalid input: " << action2 << ". Please enter an integer between 1 and 5: ";
            std::cin >> action2;
        }

        // client customized number of action2
        std::cout << "Please indicate the unit of the Second action,\n";
        std::cout << "enter an integer between 1 and 6: ";
        std::cin >> numOfAction2;
        while (numOfAction2 < 1 || numOfAction2 > 6) {
            std::cout << "Invalid input: " << numOfAction2 << ". Please enter an integer between 1 and 6: ";
            std::cin >> numOfAction2;
        }

        // client customized the "AND" / "OR" action
        std::cout << "Please indicate the \"AND\" \/ \"OR\" relation between the two actions,\n";
        std::cout << "1) AND" << endl;
        std::cout << "2) OR" << endl;
        std::cout << "enter the corresponding integer either 1 or 2: ";
        std::cin >> isAnd;
        while (isAnd < 1 || isAnd > 2) {
            std::cout << "Invalid input: " << isAnd << ". Please enter an integer either 1 or 2: ";
            std::cin >> isAnd;
        }


        gameCard* twoActionCard = new gameCard;
        twoActionCard->setGood(goods[good-1]);
        twoActionCard->setNumOfGood(numOfGood);
        twoActionCard->setAction1(actions[action-1]);
        twoActionCard->setNumOfAction1(numOfAction);
        if (isAnd == 1)
            twoActionCard->setIsAnd(true);
        else
            twoActionCard->setIsAnd(false);
        twoActionCard->setAction2(actions[action2-1]);
        twoActionCard->setNumOfAction2(numOfAction2);

        std::cout << "\nTwoAction CardFactory produced one card successfully"<< *twoActionCard << endl;
        return twoActionCard;
    } else
        return nullptr;
}

std::vector<gameCard *> Card::createCardSet(string type) {
    std::string actions[5];
    actions[0] = "PLACE_NEW_ARMIES_ON_BOARD";
    actions[1] = "MOVE_OVER_GROUND";
    actions[2] = "MOVE_OVER_WATER";
    actions[3] = "BUILD_A_CITY";
    actions[4] = "DESTROY_ARMY";

    std::string goods[6];
    goods[0] = "Crystal";
    goods[1] = "Rock";
    goods[2] = "Carrot";
    goods[3] = "Tree";
    goods[4] = "Anvil";
    goods[5] = "Wild";

    std::vector<gameCard*> cardVector;
    std::vector<gameCard*> twoActionCardVector;
    std::vector<gameCard*> wildCardVector;

    if (type == "OneAction") {
        // Wild card
        cardVector.emplace_back(new gameCard(1, goods[5], actions[2], 2));
        cardVector.emplace_back(new gameCard(1, goods[5], actions[2], 2));
        cardVector.emplace_back(new gameCard(1, goods[5], actions[0], 2));
        // Crystal card
        cardVector.emplace_back(new gameCard(1, goods[0], actions[0], 2));
        cardVector.emplace_back(new gameCard(1, goods[0], actions[0], 2));
        cardVector.emplace_back(new gameCard(1, goods[0], actions[0], 2));
        cardVector.emplace_back(new gameCard(1, goods[0], actions[0], 1));
        cardVector.emplace_back(new gameCard(1, goods[0], actions[1], 2));
        // Rock card
        cardVector.emplace_back(new gameCard(1, goods[1], actions[1], 2));
        cardVector.emplace_back(new gameCard(1, goods[1], actions[2], 2));
        cardVector.emplace_back(new gameCard(1, goods[1], actions[2], 2));
        cardVector.emplace_back(new gameCard(1, goods[1], actions[2], 3));
        cardVector.emplace_back(new gameCard(1, goods[1], actions[0], 3));
        cardVector.emplace_back(new gameCard(1, goods[1], actions[0], 3));
        // Carrot card
        cardVector.emplace_back(new gameCard(1, goods[2], actions[3], 1));
        cardVector.emplace_back(new gameCard(1, goods[2], actions[0], 3));
        cardVector.emplace_back(new gameCard(1, goods[2], actions[1], 4));
        cardVector.emplace_back(new gameCard(1, goods[2], actions[1], 4));
        cardVector.emplace_back(new gameCard(1, goods[2], actions[1], 5));
        cardVector.emplace_back(new gameCard(1, goods[2], actions[3], 1));
        cardVector.emplace_back(new gameCard(1, goods[2], actions[2], 3));
        cardVector.emplace_back(new gameCard(1, goods[2], actions[0], 3));
        // Tree card
        cardVector.emplace_back(new gameCard(1, goods[3], actions[1], 5));
        cardVector.emplace_back(new gameCard(1, goods[3], actions[1], 6));
        cardVector.emplace_back(new gameCard(1, goods[3], actions[0], 3));
        cardVector.emplace_back(new gameCard(1, goods[3], actions[2], 4));
        cardVector.emplace_back(new gameCard(1, goods[3], actions[2], 3));
        cardVector.emplace_back(new gameCard(2, goods[3], actions[3], 1));
        // Anvil card
        cardVector.emplace_back(new gameCard(1, goods[4], actions[0], 3));
        cardVector.emplace_back(new gameCard(1, goods[4], actions[0], 3));
        cardVector.emplace_back(new gameCard(1, goods[4], actions[2], 3));
        cardVector.emplace_back(new gameCard(1, goods[4], actions[3], 1));
        cardVector.emplace_back(new gameCard(2, goods[4], actions[1], 4));
        cardVector.emplace_back(new gameCard(1, goods[4], actions[1], 5));
        cardVector.emplace_back(new gameCard(1, goods[4], actions[1], 4));

        cout << "OneAction Card Set CardFactory produced " << cardVector.size() << " cards. "<< endl;
        return cardVector;
    }
    else if (type == "TwoAction") {
        twoActionCardVector.emplace_back(new gameCard(1, goods[1], actions[0], 2, false, actions[3], 1));
        twoActionCardVector.emplace_back(new gameCard(1, goods[2], actions[4], 1, true, actions[0], 1));
        twoActionCardVector.emplace_back(new gameCard(1, goods[2], actions[0], 4, false, actions[1], 2));
        twoActionCardVector.emplace_back(new gameCard(1, goods[3], actions[0], 2, false, actions[1], 3));
        twoActionCardVector.emplace_back(new gameCard(1, goods[3], actions[4], 1, false, actions[3], 1));
        twoActionCardVector.emplace_back(new gameCard(1, goods[4], actions[0], 3, false, actions[1], 4));
        twoActionCardVector.emplace_back(new gameCard(1, goods[4], actions[0], 3, false, actions[1], 3));

        cout << "TwoAction Card Set CardFactory produced " << twoActionCardVector.size() << " cards. "<< endl;
        return twoActionCardVector;
    } else if (type == goods[0] || type == goods[1] || type == goods[2] || type == goods[3] || type == goods[4] || type == goods[5]) {
        int actionsIndex;
        int actionsIndex2; // for two-action card
        int numOfMoves;
        int numOfMoves2; // for two_action card
        int countOr = 0;
        // set different initial action and unit of action for each type of goods
        if (type == goods[0]) {
            actionsIndex = 0;
            numOfMoves = 2;
            actionsIndex2 = 2;
            numOfMoves2 = 3;
        }
        if (type == goods[1]) {
            actionsIndex = 1;
            numOfMoves = 2;
            actionsIndex2 = 3;
            numOfMoves2 = 4;
        }
        if (type == goods[2]) {
            actionsIndex = 2;
            numOfMoves = 3;
            actionsIndex2 = 4;
            numOfMoves2 = 1;
        }
        if (type == goods[3]) {
            actionsIndex = 3;
            numOfMoves = 3;
            actionsIndex2 = 0;
            numOfMoves2 = 1;
        }
        if (type == goods[4]) {
            actionsIndex = 4;
            numOfMoves = 4;
            actionsIndex2 = 1;
            numOfMoves2 = 1;
        }
        if (type == goods[5]) {
            actionsIndex = 4;
            numOfMoves = 5;
            actionsIndex2 = 3;
            numOfMoves2 = 1;
        }

        int sizeOfSet;
        int sizeOfTwoActionSet;
        std::cout << "How many one-action cards would you like to produce? (enter an integer between 0 and 10): " ;
        std::cin >> sizeOfSet;
        while (sizeOfSet < 0 || sizeOfSet > 10) {
            std::cout << "Invalid input: " << sizeOfSet << ". Please enter an integer between 1 and 10 : ";
            std::cin >> sizeOfSet;
        }
        std::cout << "How many two-action cards would you like to produce? (enter an integer between 0 and 10): " ;
        std::cin >> sizeOfTwoActionSet;
        while (sizeOfTwoActionSet < 0 || sizeOfTwoActionSet > 10) {
            std::cout << "Invalid input: " << sizeOfTwoActionSet << ". Please enter an integer between 1 and 10 : ";
            std::cin >> sizeOfTwoActionSet;
        }

        // produce one-action card set
        for (int i = 0; i < sizeOfSet; i++) {
            gameCard* c = new gameCard;
            c->setGood(type);
            c->setNumOfGood(1);
            actionsIndex++;
            if (actionsIndex > 4) {
                actionsIndex = 0;
                numOfMoves++;
            }
            // when build a city or destroy army, reset num = 1
            if (actionsIndex == 3 || actionsIndex == 4)
                numOfMoves = 1;
            c->setAction(actions[actionsIndex]);
            c->setNumOfAction(numOfMoves);

            wildCardVector.emplace_back(c);
            cout << *c ;
        }
        // produce two-action card set
        for (int i = 0; i < sizeOfTwoActionSet; i++) {

            gameCard* c = new gameCard;
            c->setGood(type);
            c->setNumOfGood(1);
            actionsIndex++;
            actionsIndex2++;
            if (actionsIndex > 4) {
                actionsIndex = 0;
                numOfMoves++;
            }
            if (actionsIndex2 > 4) {
                actionsIndex2 = 0;
                numOfMoves2++;
            }
            // when build a city or destroy army, reset num = 1
            if (actionsIndex == 3 || actionsIndex == 4)
                numOfMoves = 1;
            if (actionsIndex2 == 3 || actionsIndex2 == 4)
                numOfMoves2 = 1;
            c->setAction1(actions[actionsIndex]);
            c->setNumOfAction1(numOfMoves);
            c->setAction2(actions[actionsIndex2]);
            c->setNumOfAction2(numOfMoves2);
            countOr++;
            if (countOr >5 )
                c->setIsAnd(true);
            else
                c->setIsAnd(false);


            wildCardVector.emplace_back(c);
            cout << *c ;
        }
        cout << type << " Card Factory produced " <<  sizeOfSet + sizeOfTwoActionSet << " cards. " << endl;
        return wildCardVector;
    } else if (type == "Full") {
        // Wild card
        cardVector.emplace_back(new gameCard(1, goods[5], actions[2], 2, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[5], actions[2], 2, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[5], actions[0], 2, "", 0, false, "", 0));
        // Crystal card
        cardVector.emplace_back(new gameCard(1, goods[0], actions[0], 2, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[0], actions[0], 2, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[0], actions[0], 2, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[0], actions[0], 1, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[0], actions[1], 2, "", 0, false, "", 0));
        // Rock card
        cardVector.emplace_back(new gameCard(1, goods[1], actions[1], 2, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[1], actions[2], 2, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[1], actions[2], 2, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[1], actions[2], 3, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[1], actions[0], 3, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[1], actions[0], 3, "", 0, false, "", 0));
        // Carrot card
        cardVector.emplace_back(new gameCard(1, goods[2], actions[3], 1, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[2], actions[0], 3, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[2], actions[1], 4, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[2], actions[1], 4, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[2], actions[1], 5, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[2], actions[3], 1, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[2], actions[2], 3, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[2], actions[0], 3, "", 0, false, "", 0));
        // Tree card
        cardVector.emplace_back(new gameCard(1, goods[3], actions[1], 5, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[3], actions[1], 6, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[3], actions[0], 3, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[3], actions[2], 4, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[3], actions[2], 3, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(2, goods[3], actions[3], 1, "", 0, false, "", 0));
        // Anvil card
        cardVector.emplace_back(new gameCard(1, goods[4], actions[0], 3, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[4], actions[0], 3, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[4], actions[2], 3, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[4], actions[3], 1, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(2, goods[4], actions[1], 4, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[4], actions[1], 5, "", 0, false, "", 0));
        cardVector.emplace_back(new gameCard(1, goods[4], actions[1], 4, "", 0, false, "", 0));
        // TwoAction card
        cardVector.emplace_back(new gameCard(1, goods[1], "", 0, actions[0], 2, false, actions[3], 1));
        cardVector.emplace_back(new gameCard(1, goods[2], "", 0, actions[4], 1, true, actions[0], 1));
        cardVector.emplace_back(new gameCard(1, goods[2], "", 0, actions[0], 4, false, actions[1], 2));
        cardVector.emplace_back(new gameCard(1, goods[3], "", 0, actions[0], 2, false, actions[1], 3));
        cardVector.emplace_back(new gameCard(1, goods[3], "", 0, actions[4], 1, false, actions[3], 1));
        cardVector.emplace_back(new gameCard(1, goods[4], "", 0, actions[0], 3, false, actions[1], 4));
        cardVector.emplace_back(new gameCard(1, goods[4], "", 0, actions[0], 3, false, actions[1], 3));

        cout << "Full Card Set CardFactory produced " << cardVector.size() << " cards. "<< endl;
        return cardVector;
    } else
        return std::vector<gameCard *>();

}

void Card::display(string type, gameCard* card) {
    std::string goods[6];
    goods[0] = "Crystal";
    goods[1] = "Rock";
    goods[2] = "Carrot";
    goods[3] = "Tree";
    goods[4] = "Anvil";
    goods[5] = "Wild";

    if (type == "OneAction") {
        std::cout << " : " << *card->getNumOfGood() << " " << *card->getGood()
           << " " << *card->getAction()
           << " " << *card->getNumOfAction()
           << endl;
    }
    else if (type == "TwoAction") {
        std::cout << " : " << *card->getNumOfGood() << " " << *card->getGood()
           << " " << *card->getAction1() << " " << *card->getNumOfAction1()
           << " " << (*card->getIsAnd() ? "AND" : "OR")
           << " " << *card->getAction2()
           << " " << *card->getNumOfAction2()
           << endl;
    } else if (type == goods[0] || type == goods[1] || type == goods[2] || type == goods[3] || type == goods[4] || type == goods[5] || type == "Full") {
        std::cout << *card ;
    }
    else
        std::cout << "Undefined type. Please indicate \"Full\" or \"OneAction\" or \"TwoAction\" or \"Wild\" or \"Crystal\" or \"Rock\" or \"Carrot\" or \"Tree\" or \"Anvil\". " << endl;
}

void Card::display(std::vector<gameCard *> cardVector) {
    for (int i = 0; i < cardVector.size(); i++)
        std::cout << *cardVector[i];
}

void Card::destroy(std::vector<gameCard *> cv) {
    for (int i = 0; i < cv.size(); i++) {
        delete cv[i];
        cv[i] = nullptr;
    }
    cv.clear();
    std::cout << "The Vector was deleted. " <<endl;
}
