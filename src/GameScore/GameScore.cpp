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
        std::cout << "You have wild: " << *numWild << ", rock: " << numRock <<
                  ", tree: " << numTree << ", crystal: " << numCrystal << ", carrot: " << numCarrot
                  << ", anvil card: " << numAnvil << endl;
        for (auto i = 0; i <= *numWild; i++) {
            std::string input;

            std::cout << "Which card would you like to exchange? Please input in lowercase (Eg. rock tree crystal carrot anvil)" << endl;
            std::cin >> input;
            if (input.compare("rock") == 0)
                *numRock++;
            else if (input.compare("tree") == 0)
                *numTree++;
            else if (input.compare("crystal") == 0)
                *numCrystal++;
            else if (input.compare("carrot") == 0)
                *numCarrot++;
            else if (input.compare("anvil") == 0)
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
