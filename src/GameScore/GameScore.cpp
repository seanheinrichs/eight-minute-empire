
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
    if (*tree < 2) {
        point = new int(0);
    }
    else if (*tree < 4) {
        point = new int(1);
    }
    else if (*tree < 5) {
        point = new int(2);
    }
    else if (*tree < 6) {
        point = new int(3);
    }
    else {
        point = new int(5);
    }
    return point;
}

int *GameScore::countAnvilPoint(int *anvil) {
    if (*anvil < 2) {
        point = new int(0);
    }
    else if (*anvil < 4) {
        point = new int(1);
    }
    else if (*anvil < 5) {
        point = new int(2);
    }
    else if (*anvil < 6) {
        point = new int(3);
    }
    else {
        point = new int(5);
    }
    return point;
}

int *GameScore::countCarrotPoint(int *carrot) {
    if (*carrot < 2) {
        point = new int(0);
    }
    else if (*carrot < 4) {
        point = new int(1);
    }
    else if (*carrot < 5) {
        point = new int(2);
    }
    else if (*carrot < 6) {
        point = new int(3);
    }
    else {
        point = new int(5);
    }
    return point;
}

int *GameScore::countRockPoint(int *rock) {
    if (*rock < 2) {
        point = new int(0);
    }
    else if (*rock < 4) {
        point = new int(1);
    }
    else if (*rock < 5) {
        point = new int(2);
    }
    else if (*rock < 6) {
        point = new int(3);
    }
    else {
        point = new int(5);
    }
    return point;
}

int *GameScore::countCrystalPoint(int *crystal) {
    if (*crystal < 1) {
        point = new int(0);
    }
    else if (*crystal < 3) {
        point = new int(1);
    }
    else if (*crystal < 4) {
        point = new int(2);
    }
    else if (*crystal < 5) {
        point = new int(3);
    }
    else {
        point = new int(5);
    }
    return point;
}


int *GameScore::computeGameScore(std::vector<Cards *> &gameHand) {
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
    carrot = countCarrotPoint(numCarrot);
    tree = countTreePoint(numTree);

    *sum = *rock + *crystal + *anvil + *carrot + *tree;

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
            sum++;
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

void GameScore::winnerGenerator(std:: vector <Player*> playerVector) {
    auto mostScorePlayers = new std::vector<Player *>();
    int *max = new int(0);
    std::string *winner;

    mostScorePlayers->emplace_back(playerVector.at(0));
    *max = playerVector.at(0)->getPoints();  // max Points
    // 1st loop get Player vector with most Points, note the max # of players is 5 in this game
    for (int i = 1; i < playerVector.size(); i++) {
        // playerVector.at(0) already inside mostScore group
        if (playerVector.at(i)->getPoints() > *max) {
            for (int j = 0; j < mostScorePlayers->size(); j++)
                mostScorePlayers->pop_back();
            mostScorePlayers->emplace_back(playerVector.at(i));
            *max = playerVector.at(i)->getPoints();
        } else if (playerVector.at(i)->getPoints() == *max) {
            mostScorePlayers->emplace_back(playerVector.at(i));
        } else
            continue;
    }
    if (mostScorePlayers->size() == 1) {
        *winner = mostScorePlayers->at(0)->getName();
        std::cout << "Winner is " << *winner << endl;
        return;
    } else {
        *winner = mostScorePlayers->at(0)->getName();
        std::cout << "Winner is " << *winner << endl;
        return;
    }
}

