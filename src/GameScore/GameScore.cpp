//
// Created by steve on 11/3/2019.
//

#include "GameScore.h"
#include "Player.h"
#include "Cards.h"
#include "GameState.h"
#include "Map.h"

GameScore::GameScore() {}

GameScore::~GameScore() {

}

GameScore::GameScore(const vector<Cards *> &gameHand, const vector<Player *> &players) : gameHand(gameHand),
                                                                                         players(players) {}


int *GameScore::countTreePoint(int *tree) {
    switch (*tree)
    {
        case 2:
            point = new int(1);
            break;
        case 4:
            point = new int(2);
            break;
        case 5:
            point = new int(3);
            break;
        case 6:
            point = new int(5);
            break;
    }
    return point;
}

int *GameScore::countAnvilPoint(int *anvil) {
    switch (*anvil)
    {
        case 2:
            point = new int(1);
            break;
        case 4:
            point = new int(2);
            break;
        case 6:
            point = new int(3);
            break;
        case 7:
            point = new int(5);
            break;
    }
    return point;
}

int *GameScore::countCarrotPoint(int *carrot) {
    switch (*carrot)
    {
        case 3:
            point = new int(1);
            break;
        case 5:
            point = new int(2);
            break;
        case 7:
            point = new int(3);
            break;
        case 8:
            point = new int(5);
            break;
    }
    return point;
}

int *GameScore::countRockPoint(int *rock) {
    switch (*rock)
    {
        case 2:
            point = new int(1);
            break;
        case 3:
            point = new int(2);
            break;
        case 4:
            point = new int(3);
            break;
        case 5:
            point = new int(5);
            break;
    }
    return point;
}

int *GameScore::countCrystalPoint(int *crystal) {
    switch (*crystal)
    {
        case 1:
            point = new int(1);
            break;
        case 2:
            point = new int(2);
            break;
        case 3:
            point = new int(3);
            break;
        case 4:
            point = new int(5);
            break;
    }
    return point;
}


int *GameScore::computeGameScore(std::vector<Player *> &players, std::vector<Cards *> &gameHand) {
    int* sum = new int(0);
    int* rock = new int(0);
    int* crystal = new int(0);
    int* anvil = new int(0);
    int* wild = new int(0);
    int* carrot = new int(0);
    int* tree = new int(0);

    int* numTree = numOfTree(gameHand);
    int* numRock = numOfRock(gameHand);
    int* numCrystal = numOfCrystal(gameHand);
    int* numCarrot = numOfCarrot(gameHand);
    int* numAnvil = numOfAnvil(gameHand);
    int* numWild = numOfWild(gameHand);

    // check if player's hand has Wild cards
    if (*numWild > 0) {
        std::cout << "You have wild: " << *numWild << ", rock: " << *numRock <<
                  ", tree: " << *numTree << ", crystal: " << *numCrystal << ", carrot: " << *numCarrot
                  << ", anvil card: " << *numAnvil << endl;
        for (auto i = 0; i < *numWild; i++) {
            std::string input;

            std::cout << "You have wild cards which can exchange to other cards if you hold at least one card of the same good type." << endl;
            std::cout << "Please note if you input the one that actually you don't have that type of good card, your wild card will be forfeit : )" << endl;
            std::cout << "Which card would you like to exchange? Please input in lowercase (Eg. rock tree crystal carrot anvil)" << endl;
            std::cin >> input;
            if (*numRock >0  && input.compare("rock") == 0)
                *numRock++;
            else if (*numTree > 0 && input.compare("tree") == 0)
                *numTree++;
            else if (*numCrystal > 0 && input.compare("crystal") == 0)
                *numCrystal++;
            else if (*numCarrot > 0 && input.compare("carrot") == 0)
                *numCarrot++;
            else if (*numAnvil > 0 && input.compare("anvil") == 0)
                *numAnvil++;
            else
                continue;
        }
    }
    rock = countRockPoint(numRock);
    crystal = countCrystalPoint(numCrystal);
    anvil = countAnvilPoint(numAnvil);
    carrot = countCarrotPoint(carrot);
    tree = countTreePoint(tree);
    *sum = *rock + *crystal + *anvil + *carrot + *tree;

    // TODO: sum up regions and continents

    return sum;

}

int *GameScore::numOfTree(std::vector<Cards*> &gameHand) {
    int* num = new int(0); int* sum = new int(0);
    for (int i = 0; i < gameHand.size(); i++) {
         if (gameHand[i]->getGood()->compare("Tree") == 0) {
            num = gameHand[i]->getNumOfGood();
            *sum += *num;
         }
    }
    return sum;
}

int *GameScore::numOfAnvil(std::vector<Cards *> &gameHand) {
    int* num = new int(0); int* sum = new int(0);
    for (int i = 0; i < gameHand.size(); i++) {
        if (gameHand[i]->getGood()->compare("Anvil") == 0) {
            num = gameHand[i]->getNumOfGood();
            *sum += *num;
        }
    }
    return sum;
}

int *GameScore::numOfCarrot(std::vector<Cards *> &gameHand) {
    int* num = new int(0); int* sum = new int(0);
    for (int i = 0; i < gameHand.size(); i++) {
        if (gameHand[i]->getGood()->compare("Carrot") == 0) {
            num = gameHand[i]->getNumOfGood();
            *sum += *num;
        }
    }
    return sum;
}

int *GameScore::numOfRock(std::vector<Cards *> &gameHand) {
    int* num = new int(0); int* sum = new int(0);
    for (int i = 0; i < gameHand.size(); i++) {
        if (gameHand[i]->getGood()->compare("Rock") == 0) {
            num = gameHand[i]->getNumOfGood();
            *sum += *num;
        }
    }
    return sum;
}

int *GameScore::numOfCrystal(std::vector<Cards *> &gameHand) {
    int* num = new int(0); int* sum = new int(0);
    for (int i = 0; i < gameHand.size(); i++) {
        if (gameHand[i]->getGood()->compare("Crystal") == 0) {
            num = gameHand[i]->getNumOfGood();
            *sum += *num;
        }
    }
    return sum;
}

int *GameScore::numOfWild(std::vector<Cards *> &gameHand) {
    int* num = new int(0); int* sum = new int(0);
    for (int i = 0; i < gameHand.size(); i++) {
        if (gameHand[i]->getGood()->compare("Wild") == 0) {
            num = gameHand[i]->getNumOfGood();
            *sum += *num;
        }
    }
    return sum;
}

void GameScore::winnerGenerator() {
    std::string* winner;
    Player* p1 = new Player("JJ", 39);
    Player* p2 = new Player("MM", 23);
    Player* p3 = new Player("SS", 23);
    Player* p4 = new Player("TT", 21);
    auto Armiesp1 = p1->getArmies();
    auto Coinp1 = p1->getCoins();
    auto Citiesp1 = p1->getCities();
    auto Armiesp2 = p2->getArmies();
    auto Coinp2 = p2->getCoins();
    auto Citiesp2 = p2->getCities();
    auto Armiesp3 = p3->getArmies();
    auto Coinp3 = p3->getCoins();
    auto Citiesp3 = p3->getCities();
    auto Armiesp4 = p4->getArmies();
    auto Coinp4 = p4->getCoins();
    auto Citiesp4 = p4->getCities();
    // p1.points -> pp1
    int *pp1, *pp2, *pp3, *pp4;


    vector<Player*> ps {p1, p2, p3, p4};
    int* point;
    int* numOfRegions;
    int* numOfContinents;
    int* numOfCoins;
    int* numOfArmies;
    // Rules priotity: mostPoints ->  mostCoins -> mostArmies -> mostRegions
    int* mostPoints;
    int* mostCoins;
    int* mostArmies;
    int* mostRegions;

    // logic of generate a Winner
    if (pp1 == pp2) {
        if (Coinp1 < Coinp2) {
            *winner = p2->getName();
            return;
        } else if (Coinp1 == Coinp2) {
            if (Armiesp1 < Armiesp2) {
                *winner = p2->getName();
                return;
            } else if (Armiesp1 == Armiesp2) {
                if ( Citiesp1 < Citiesp2 ) {
                    *winner = p2->getName();
                    return;
                } else if (Citiesp1 == Citiesp2) {
                    cout << "We have 2 winner !! Impossible !!! " << endl;
                    return;
                } else {
                    *winner = p1->getName();
                    return;
                }
            } else {
                *winner = p1->getName();
                return;
            }
        } else {
            *winner = p1->getName();
            return;
        }
    }
}
