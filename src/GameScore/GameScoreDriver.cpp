#pragma once

#include "GameScoreDriver.h"
#include "GameScore.h"
#include "Cards.h"
#include "Player.h"
#include "Map.h"

void gameScoreExample() {

    cout << "========= Setup game start from map ===============" << endl;
    MapLoader loader;
    std::string fileLocation = "../assets/map1.map"; // for CLion
//    std::string fileLocation = "assets/map1.map"; // for VSCode
    Map m = loader.generateMap(fileLocation);
    auto regionOwners = m.getRegionOwners();
    auto continentOwners = m.getContinentOwners();

    Player *sean = new Player("sean", 3, 15);
    Player *mike = new Player("mike", 3, 16);
    Player *jia = new Player("jia", 3, 17);
    std:: vector <Player*> playerVector = {sean, mike, jia};

    cout << "=========Test 3 Player's Armies on Board ===============" << endl;
    int seanArmies = m.getArmiesOnBoard(sean->getName());
    cout << "sean has "<< seanArmies << " armies on board." << endl;
    int jiaArmies = m.getArmiesOnBoard(jia->getName());
    cout << "jia has "<< jiaArmies << " armies on board." << endl;
    int mikeArmies = m.getArmiesOnBoard(mike->getName());
    cout << "mike has "<< mikeArmies << " armies on board." << endl;


//    cout << "=========Build 3 Player's Coins ===============" << endl;
//    sean->setCoins(11);
//    mike->setCoins(11);
//    jia->setCoins(11);

//    cout << "=========Build 3 Player's Armies ===============" << endl;
//    sean->setArmies(4);
//    mike->setArmies(4);
//    jia->setArmies(4);


    cout << "=========Build 3 Player's Hand ===============" << endl;
    Deck *deck1 = new Deck();
    std::vector<Cards*> topBoard = deck1->topBoardGenetor(*deck1);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            playerVector.at(i)->getGameHand()->emplace_back(deck1->draw());
        }
    }
    cout <<  sean->getName() << "'s hand: "<< endl;
    deck1->displayHand(*playerVector.at(0)->getGameHand());
    cout <<  mike->getName() << "'s hand: "<< endl;
    deck1->displayHand(*playerVector.at(1)->getGameHand());
    cout <<  jia->getName() << "'s hand: "<< endl;
    deck1->displayHand(*playerVector.at(2)->getGameHand());
    cout << "======================================================="<< endl;


//    playerVector.at(0)->addPoints(regionOwners.at("sean").size());
//    playerVector.at(1)->addPoints(regionOwners.at("mike").size());
//    playerVector.at(2)->addPoints(regionOwners.at("jia").size());

//    for (int i=0; i < continentOwners.size(); i++) {
//        if (continentOwners.at(i).second == "sean") {
//            playerVector.at(0)->addPoints(1);
//        } else if (continentOwners.at(i).second == "mike") {
//            playerVector.at(1)->addPoints(1);
//        } else if (continentOwners.at(i).second == "jia") {
//            playerVector.at(2)->addPoints(1);
//        }
//    }

//    cout << "============= get points from map-board ===================" << endl;
//    cout << "From board " << playerVector.at(0)->getName() <<" gets " << playerVector.at(0)->getPoints() << " points" << endl;
//    cout << "From board " << playerVector.at(1)->getName() <<" gets " << playerVector.at(1)->getPoints() << " points" << endl;
//    cout << "From board " << playerVector.at(2)->getName() <<" gets " << playerVector.at(2)->getPoints() << " points" << endl;
//    cout << "=======================================================\n"<< endl;
//
//    cout << "============= adding cards' points===================" << endl;
//    GameScore gameScore;

//    int* sum1 = gameScore.computeGameScore(playerVector.at(0));
//    int* sum2 = gameScore.computeGameScore(playerVector.at(1));
//    int* sum3 = gameScore.computeGameScore(playerVector.at(2));
//
//    cout << "From cards " << playerVector.at(0)->getName() <<" gets " << *sum1 << " points" << endl;
//    cout << "From cards " << playerVector.at(1)->getName() <<" gets " << *sum2 << " points" << endl;
//    cout << "From cards " << playerVector.at(2)->getName() <<" gets " << *sum3 << " points" << endl;
//
//    playerVector.at(0)->addPoints(*sum1);
//    playerVector.at(1)->addPoints(*sum2);
//    playerVector.at(2)->addPoints(*sum3);

    cout << "=========Test GameScore( ) ===============" << endl;
//    std::cout << playerVector.at(0)->getName() << "'s points: " << playerVector.at(0)->getPoints() << endl;
//    std::cout << playerVector.at(1)->getName() << "'s points: " << playerVector.at(1)->getPoints() << endl;
//    std::cout << playerVector.at(2)->getName() << "'s points: " << playerVector.at(2)->getPoints() << endl;
    cout << "=======================================================\n"<< endl;
//    gameScore.winnerGenerator(playerVector, m);
    cout << "=======================================================\n"<< endl;

//    auto regionOwners = gameBoard.getRegionOwners();
//    auto continentOwners = gameBoard.getContinentOwners();
//    for (int i = 0; i < playerVector.size(); i++) {
//        auto name = playerVector.at(i)->getName();
//        cout << name << " : " << endl;
//
//        // count points from hand
//        int *p3 = gameScore.computeGameScore(playerVector.at(i));
//        playerVector.at(i)->addPoints(*p3);
//        std::cout << "  hand points: " << *p3 << endl;
//
//        // count number of Armies on Board
//        auto p2 = m.getArmiesOnBoard(name);
//        playerVector.at(i)->setArmiesOnBoard(p2);
//        cout << "  # armies on board : " << playerVector.at(i)->getArmiesOnBoard() << endl;


//        cout << name << " : " << endl;
        // count points from regions
//        auto p1 = regionOwners.at(name).size();
//        playerVector.at(i)->addPoints(p1);
//        cout << "  regions : " << p1 << endl;
        // count number of Armies on Board
//        auto p2 = m.getArmiesOnBoard(name);
//        playerVector.at(i)->setArmiesOnBoard(p2);
//        cout << "  # armies on board : " << playerVector.at(i)->getArmiesOnBoard() << endl;
        // count number of regions controlled
//        playerVector.at(i)->setRegions(p1);
//        cout <<"  # regions : "<< playerVector.at(i)->getRegions() << endl;
        // count points from hand
//        int *p3 = gameScore.computeGameScore(playerVector.at(i));
//        playerVector.at(i)->addPoints(*p3);
//        std::cout << "  hand points: " << *p3 << endl;

//        cout << "------------ regions and hand points added, # armies on board, # regions got ------------" << endl;
//
//    }

    // count points from continents
//    for (int i = 0; i < continentOwners.size(); i++) {
//        if (continentOwners.at(i).second == playerVector.at(0)->getName()) {
//            playerVector.at(0)->addPoints(1);
//        }
//        else if (continentOwners.at(i).second == playerVector.at(1)->getName()) {
//            playerVector.at(1)->addPoints(1);
//        }
//        else if (playerVector.size() == 3 && continentOwners.at(i).second == playerVector.at(2)->getName()) {
//            playerVector.at(2)->addPoints(1);
//        }
//        else if (playerVector.size() == 4 && continentOwners.at(i).second == playerVector.at(3)->getName()) {
//            playerVector.at(3)->addPoints(1);
//        }
//        else if (playerVector.size() == 5 && continentOwners.at(i).second == playerVector.at(4)->getName()) {
//            playerVector.at(4)->addPoints(1);
//        }
//    }

//    // display final scores
//    std::cout << "Here are the final scores: " << endl;
//    for (int i = 0; i < playerVector.size(); i++) {
//        std::cout << playerVector.at(i)->getName() << ": " << playerVector.at(i)->getPoints() << endl;
//    }
//
//    // determine winner from 4 tie loops
//    // 1st loop most Points
//    auto mostScorePlayers = new std::vector<Player *>();
//    int *max = new int(0);
//    std::string winner;
//    // 2nd loop most Coins
//    auto mostScorePlayers1 = new std::vector<Player *>();
//    int *max1 = new int(0);
//    // 3rd loop most Armies on board
//    auto mostScorePlayers2 = new std::vector<Player *>();
//    int *max2 = new int(0);
//    // 4th loop most Regions
//    auto mostScorePlayers3 = new std::vector<Player *>();
//    int *max3 = new int(0);
//
//    mostScorePlayers->emplace_back(playerVector.at(0));
//    *max = playerVector.at(0)->getPoints();  // max Points
//    // 1st loop get Player vector with most Points, note the max # of players is 5 in this game
//    for (int i = 1; i < playerVector.size(); i++) {
//        // playerVector.at(0) already inside mostScore group
//        if (playerVector.at(i)->getPoints() > *max) {
//            for (int j = 0; j < mostScorePlayers->size(); j++)
//                mostScorePlayers->pop_back();
//            mostScorePlayers->emplace_back(playerVector.at(i));
//            *max = playerVector.at(i)->getPoints();
//        } else if (playerVector.at(i)->getPoints() == *max) {
//            mostScorePlayers->emplace_back(playerVector.at(i));
//        } else
//            continue;
//    }
//    if (mostScorePlayers->size() == 1) {
//        winner = mostScorePlayers->at(0)->getName();
//        std::cout << "Winner is " << winner << endl;
//        std::cout << "Most points : " << *max << endl;
////        return;
//    } else {
//        mostScorePlayers1->emplace_back(mostScorePlayers->at(0));
//        *max1 = mostScorePlayers->at(0)->getCoins();  // max Coins
//        // 2nd loop get Player vector with most Coins
//        for (int i = 1; i < mostScorePlayers->size(); i++) {
//            if (mostScorePlayers->at(i)->getCoins() > *max1) {
//                for (int j = 0; j < mostScorePlayers1->size(); j++)
//                    mostScorePlayers1->pop_back();
//                mostScorePlayers1->emplace_back(mostScorePlayers->at(i));
//                *max1 = mostScorePlayers->at(i)->getCoins();
//            } else if (mostScorePlayers->at(i)->getCoins() == *max1) {
//                mostScorePlayers1->emplace_back(mostScorePlayers->at(i));
//            } else
//                continue;
//        }
//        if (mostScorePlayers1->size() == 1) {
//            winner = mostScorePlayers1->at(0)->getName();
//            std::cout << "Winner is " << winner << endl;
//            std::cout << "Most coins : " << *max1 << endl;
////            return;
//        } else {
//            mostScorePlayers2->emplace_back(mostScorePlayers1->at(0));
//            *max2 = mostScorePlayers1->at(0)->getArmiesOnBoard();  // max Armies on Board
//            // 3rd loop get Player vector with most Armies on board, not getArmies()
//            for (int i = 1; i < mostScorePlayers1->size(); i++) {
//                if (mostScorePlayers1->at(i)->getArmiesOnBoard() > *max2) {
//                    for (int j = 0; j < mostScorePlayers2->size(); j++)
//                        mostScorePlayers2->pop_back();
//                    mostScorePlayers2->emplace_back(mostScorePlayers1->at(i));
//                    *max2 = mostScorePlayers1->at(i)->getArmiesOnBoard();
//                } else if (mostScorePlayers1->at(i)->getArmiesOnBoard() == *max2) {
//                    mostScorePlayers2->emplace_back(mostScorePlayers1->at(i));
//                } else
//                    continue;
//            }
//            if (mostScorePlayers2->size() == 1) {
//                winner = mostScorePlayers2->at(0)->getName();
//                std::cout << "Winner is " << winner << endl;
//                std::cout << "Most armies on Board : " << *max2 << endl;
////                return;
//            } else {
//                mostScorePlayers3->emplace_back(mostScorePlayers2->at(0));
//                *max3 = mostScorePlayers2->at(0)->getRegions();  // max Regions
//                // 4th loop get Player vector with most Regions
//                for (int i = 1; i < mostScorePlayers2->size(); i++) {
//                    if (mostScorePlayers2->at(i)->getRegions() > *max3) {
//                        for (int j = 0; j < mostScorePlayers3->size(); j++)
//                            mostScorePlayers3->pop_back();
//                        mostScorePlayers3->emplace_back(mostScorePlayers2->at(i));
//                        *max3 = mostScorePlayers2->at(i)->getRegions();
//                    } else if (mostScorePlayers2->at(i)->getRegions() == *max3) {
//                        mostScorePlayers3->emplace_back(mostScorePlayers2->at(i));
//                    } else
//                        continue;
//                }
//                if (mostScorePlayers3->size() == 1) {
//                    winner = mostScorePlayers3->at(0)->getName();
//                    std::cout << "Winner is " << winner << endl;
//                    std::cout << "Most regions : " << *max3 << endl;
////                    return;
//                } else {
//                    std::cout << "Tie, all are winners!" << endl;
//                    for (int i = 0; i < mostScorePlayers3->size(); i++)
//                        std::cout << "Tie, Winners : " << mostScorePlayers3->at(i)->getName() <<endl;
//                    std::cout << "Most points : " << *max << endl;
//                    std::cout << "Most coins : " << *max1 << endl;
//                    std::cout << "Most armies on Board : " << *max2 << endl;
//                    std::cout << "Most regions : " << *max3 << endl;
////                    return;
//                }
//            }
//        }
//    }

}
