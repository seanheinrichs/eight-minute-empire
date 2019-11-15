#include "GameScore.h"
#include "Player.h"
#include "Cards.h"
#include "GameState.h"
#include "Map.h"

GameScore::GameScore() {}

GameScore::~GameScore() {
    if (point) {
        delete point;
        point = NULL;
    }
}

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
    else if (*anvil < 6) {
        point = new int(2);
    }
    else if (*anvil < 7) {
        point = new int(3);
    }
    else {
        point = new int(5);
    }
    return point;
}

int *GameScore::countCarrotPoint(int *carrot) {
    if (*carrot < 3) {
        point = new int(0);
    }
    else if (*carrot < 5) {
        point = new int(1);
    }
    else if (*carrot < 7) {
        point = new int(2);
    }
    else if (*carrot < 8) {
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
    else if (*rock < 3) {
        point = new int(1);
    }
    else if (*rock < 4) {
        point = new int(2);
    }
    else if (*rock < 5) {
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
    else if (*crystal < 2) {
        point = new int(1);
    }
    else if (*crystal < 3) {
        point = new int(2);
    }
    else if (*crystal < 4) {
        point = new int(3);
    }
    else {
        point = new int(5);
    }
    return point;
}

// compute the points from player's hand's cards
int *GameScore::computeGameScore(Player * &players) {
    auto gameHand = players->getGameHand();
    int* sum = new int(0);
    int* rock = new int(0);
    int* crystal = new int(0);
    int* anvil = new int(0);
    int* wild = new int(0);
    int* carrot = new int(0);
    int* tree = new int(0);

    int* numTree = numOfTree(*gameHand);
    int* numRock = numOfRock(*gameHand);
    int* numCrystal = numOfCrystal(*gameHand);
    int* numCarrot = numOfCarrot(*gameHand);
    int* numAnvil = numOfAnvil(*gameHand);
    int* numWild = numOfWild(*gameHand);

    // check if player's hand has Wild cards
    if (*numWild > 0) {
        std::cout << players->getName() << ", you have wild: " << *numWild << ", rock: " << *numRock <<
                  ", tree: " << *numTree << ", crystal: " << *numCrystal << ", carrot: " << *numCarrot
                  << ", anvil card: " << *numAnvil << endl;
        for (auto i = 0; i < *numWild; i++) {
            std::string input;

            std::cout << "You have wild cards which can exchange to other cards if you hold at least one card of the same good type." << endl;
            std::cout << "Please note if you input the one that actually you don't have that type of good card, your wild card will be forfeit : )" << endl;
            std::cout << players->getName() << ", which card would you like to exchange? Please input in lowercase (Eg. rock tree crystal carrot anvil)" << endl;
            std::cin >> input;
            if (*numRock >0  && input == "rock") {
                *numRock += 1;
            }
            else if (*numTree > 0 && input == "tree")
                *numTree += 1;
            else if (*numCrystal > 0 && input == "crystal")
                *numCrystal += 1;
            else if (*numCarrot > 0 && input == "carrot"){
                *numCarrot += 1;
            }
            else if (*numAnvil > 0 && input == "anvil")
                *numAnvil += 1;
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

// determine winner from 4 tie loops: points -> coins -> armies on board -> regions controlled by player
void GameScore::winnerGenerator(std:: vector <Player*> &playerVector, Map &gameBoard) {
    auto regionOwners = gameBoard.getRegionOwners();
    auto continentOwners = gameBoard.getContinentOwners();
    for (int i = 0; i < playerVector.size(); i++) {
        auto name = playerVector.at(i)->getName();
        cout << name << " : " << endl;
        // count points from regions
        int p1 = regionOwners.at(name).size();
        playerVector.at(i)->addPoints(p1);
        cout << "  regions : " << p1 << endl;
        // count number of Armies on Board
        auto p2 = gameBoard.getArmiesOnBoard(name);
        playerVector.at(i)->setArmiesOnBoard(p2);
        cout << "  # armies on board : " << playerVector.at(i)->getArmiesOnBoard() << endl;
        // count number of regions controlled
        playerVector.at(i)->setRegions(p1);
        cout <<"  # regions : "<< playerVector.at(i)->getRegions() << endl;
        // count points from hand
        int *p3 = computeGameScore(playerVector.at(i));
        playerVector.at(i)->addPoints(*p3);
        std::cout << "  hand points: " << *p3 << endl;
        cout << "------------ regions and hand points added, # armies on board, # regions got ------------" << endl;

    }

    // count points from continents
    for (int i = 0; i < continentOwners.size(); i++) {
        if (continentOwners.at(i).second == playerVector.at(0)->getName()) {
            playerVector.at(0)->addPoints(1);
        }
        else if (continentOwners.at(i).second == playerVector.at(1)->getName()) {
            playerVector.at(1)->addPoints(1);
        }
        else if (playerVector.size() == 3 && continentOwners.at(i).second == playerVector.at(2)->getName()) {
            playerVector.at(2)->addPoints(1);
        }
        else if (playerVector.size() == 4 && continentOwners.at(i).second == playerVector.at(3)->getName()) {
            playerVector.at(3)->addPoints(1);
        }
        else if (playerVector.size() == 5 && continentOwners.at(i).second == playerVector.at(4)->getName()) {
            playerVector.at(4)->addPoints(1);
        }
    }

    // display final scores
    std::cout << "Here are the final scores: " << endl;
    for (int i = 0; i < playerVector.size(); i++) {
        std::cout << playerVector.at(i)->getName() << ": " << playerVector.at(i)->getPoints() << endl;
    }

    // determine winner from 4 tie loops
    // 1st loop most Points
    auto mostScorePlayers = new std::vector<Player *>();
    int *max = new int(0);
    std::string winner;
    // 2nd loop most Coins
    auto mostScorePlayers1 = new std::vector<Player *>();
    int *max1 = new int(0);
    // 3rd loop most Armies on board
    auto mostScorePlayers2 = new std::vector<Player *>();
    int *max2 = new int(0);
    // 4th loop most Regions
    auto mostScorePlayers3 = new std::vector<Player *>();
    int *max3 = new int(0);

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
        }
    }
    if (mostScorePlayers->size() == 1) {
        winner = mostScorePlayers->at(0)->getName();
        std::cout << "Winner is " << winner << endl;
        std::cout << "Most points : " << *max << endl;
        return;
    } else {
        mostScorePlayers1->emplace_back(mostScorePlayers->at(0));
        *max1 = mostScorePlayers->at(0)->getCoins();  // max Coins
        // 2nd loop get Player vector with most Coins
        for (int i = 1; i < mostScorePlayers->size(); i++) {
            if (mostScorePlayers->at(i)->getCoins() > *max1) {
                for (int j = 0; j < mostScorePlayers1->size(); j++)
                    mostScorePlayers1->pop_back();
                mostScorePlayers1->emplace_back(mostScorePlayers->at(i));
                *max1 = mostScorePlayers->at(i)->getCoins();
            } else if (mostScorePlayers->at(i)->getCoins() == *max1) {
                mostScorePlayers1->emplace_back(mostScorePlayers->at(i));
            }
        }
        if (mostScorePlayers1->size() == 1) {
            winner = mostScorePlayers1->at(0)->getName();
            std::cout << "Winner is " << winner << endl;
            std::cout << "Most coins : " << *max1 << endl;
            return;
        } else {
            mostScorePlayers2->emplace_back(mostScorePlayers1->at(0));
            *max2 = mostScorePlayers1->at(0)->getArmiesOnBoard();  // max Armies on Board
            // 3rd loop get Player vector with most Armies on board, not getArmies()
            for (int i = 1; i < mostScorePlayers1->size(); i++) {
                if (mostScorePlayers1->at(i)->getArmiesOnBoard() > *max2) {
                    for (int j = 0; j < mostScorePlayers2->size(); j++)
                        mostScorePlayers2->pop_back();
                    mostScorePlayers2->emplace_back(mostScorePlayers1->at(i));
                    *max2 = mostScorePlayers1->at(i)->getArmiesOnBoard();
                } else if (mostScorePlayers1->at(i)->getArmiesOnBoard() == *max2) {
                    mostScorePlayers2->emplace_back(mostScorePlayers1->at(i));
                }
            }
            if (mostScorePlayers2->size() == 1) {
                winner = mostScorePlayers2->at(0)->getName();
                std::cout << "Winner is " << winner << endl;
                std::cout << "Most armies on Board : " << *max2 << endl;
                return;
            } else {
                mostScorePlayers3->emplace_back(mostScorePlayers2->at(0));
                *max3 = mostScorePlayers2->at(0)->getRegions();  // max Regions
                // 4th loop get Player vector with most Regions
                for (int i = 1; i < mostScorePlayers2->size(); i++) {
                    if (mostScorePlayers2->at(i)->getRegions() > *max3) {
                        for (int j = 0; j < mostScorePlayers3->size(); j++)
                            mostScorePlayers3->pop_back();
                        mostScorePlayers3->emplace_back(mostScorePlayers2->at(i));
                        *max3 = mostScorePlayers2->at(i)->getRegions();
                    } else if (mostScorePlayers2->at(i)->getRegions() == *max3) {
                        mostScorePlayers3->emplace_back(mostScorePlayers2->at(i));
                    }
                }
                if (mostScorePlayers3->size() == 1) {
                    winner = mostScorePlayers3->at(0)->getName();
                    std::cout << "Winner is " << winner << endl;
                    std::cout << "Most regions : " << *max3 << endl;
                    return;
                } else {
                    std::cout << "Tie, all are winners!" << endl;
                    for (int i = 0; i < mostScorePlayers3->size(); i++)
                        std::cout << "Tie, Winners : " << mostScorePlayers3->at(i)->getName() <<endl;
                    std::cout << "Most points : " << *max << endl;
                    std::cout << "Most coins : " << *max1 << endl;
                    std::cout << "Most armies on Board : " << *max2 << endl;
                    std::cout << "Most regions : " << *max3 << endl;
                    return;
                }
            }
        }
    }
}

//    Game rules:
//    players: coins : 5 -> 8, 4 -> 9, 3 -> 11, 2 -> 14
//    players: armies:  1 p -> 14 (cubes)  if 2 players, place 10 armies of a 3-rd party armies in turn on map
//    players: cities: 1p -> 3 cities (discs)
