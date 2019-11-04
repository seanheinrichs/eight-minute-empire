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


int *GameScore::countTreePoint(int tree) {
    switch (tree)
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

int *GameScore::countAnvilPoint(int anvil) {
    switch (anvil)
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

int *GameScore::countCarrotPoint(int carrot) {
    switch (carrot)
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

int *GameScore::countRockPoint(int rock) {
    switch (rock)
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

int *GameScore::countCrystalPoint(int crystal) {
    switch (crystal)
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
    // num of good
    int rock = 0;
    int crystal = 0;
    int anvil = 0;
    int wild = 0;
    int carrot = 0;
    int tree = 0;
    //TODO: Are you going to replace wild card convert with which card?
    // num of tree
    switch (tree)
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
    switch (anvil)
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
    switch (carrot)
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
    switch (rock)
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
    switch (crystal)
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





    return nullptr;
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
