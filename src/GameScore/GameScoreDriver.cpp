#pragma once

#include "GameScoreDriver.h"
#include "GameScore.h"
#include "Cards.h"
#include "Player.h"
#include "Map.h"

void gameScoreExample() {
    MapLoader loader;
    std::string fileLocation = "../assets/map1.map";
    Map m = loader.generateMap(fileLocation);
    auto regionOwners = m.getRegionOwners();
    auto continentOwners = m.getContinentOwners();

    Cards* cards01 = new Cards(1,"Rock", "MOVE_OVER_WATER 2");
    Cards* cards02 = new Cards(1,"Rock", "MOVE_OVER_WATER 2");
    Cards* cards03 = new Cards(1,"Rock", "PLACE_NEW_ARMIES_ON_BOARD 2");
    Cards* cards04 = new Cards(1,"Crystal", "PLACE_NEW_ARMIES_ON_BOARD 2");
    Cards* cards05 = new Cards(1,"Crystal", "PLACE_NEW_ARMIES_ON_BOARD 2");
    Cards* cards06 = new Cards(1,"Crystal", "PLACE_NEW_ARMIES_ON_BOARD 2");
    Cards* cards07 = new Cards(1,"Crystal", "PLACE_NEW_ARMIES_ON_BOARD 1");
    Cards* cards08 = new Cards(1,"Crystal", "MOVE_OVER_LAND 2");
    Cards* cards09 = new Cards(1,"Rock", "MOVE_OVER_LAND 2");
    Cards* cards10 = new Cards(1,"Rock", "MOVE_OVER_WATER 2");
    Cards* cards11 = new Cards(1,"Rock", "MOVE_OVER_WATER 2");
    Cards* cards12 = new Cards(1, "Rock", "MOVE_OVER_WATER 3");
    Cards* cards13 = new Cards(1,"Rock", "PLACE_NEW_ARMIES_ON_BOARD 3");
    Cards* cards14 = new Cards(1,"Rock", "PLACE_NEW_ARMIES_ON_BOARD 3");
    Cards* cards15 = new Cards(1,"Rock", "PLACE_NEW_ARMIES_ON_BOARD 2 OR BUILD_A_CITY 1");
    Cards* cards16 = new Cards(1,"Carrot", "BUILD_A_CITY 1");
    Cards* cards17 = new Cards(1,"Wild", "DESTROY_ARMY 1 AND PLACE_NEW_ARMIES_ON_BOARD 1");
    Cards* cards18 = new Cards(1,"Carrot", "PLACE_NEW_ARMIES_ON_BOARD 3");
    Cards* cards19 = new Cards(1,"Carrot", "MOVE_OVER_LAND 4");
    Cards* cards20 = new Cards(1,"Carrot", "MOVE_OVER_LAND 4");
    Cards* cards21 = new Cards(1,"Carrot","PLACE_NEW_ARMIES_ON_BOARD 4 OR MOVE_OVER_LAND 2");

    Player *sean = new Player("sean", 3, 15);
    Player *mike = new Player("mike", 3, 16);
    Player *jia = new Player("jia", 3, 17);
    std:: vector <Player*> playerVector = {sean, mike, jia};

    cout << "=========Build a Player's Hand ===============" << endl;
    playerVector.at(0)->getGameHand()->emplace_back(cards01);
    playerVector.at(0)->getGameHand()->emplace_back(cards02);
    playerVector.at(0)->getGameHand()->emplace_back(cards03);
    playerVector.at(0)->getGameHand()->emplace_back(cards04);
    playerVector.at(0)->getGameHand()->emplace_back(cards05);
    playerVector.at(0)->getGameHand()->emplace_back(cards06);
    playerVector.at(0)->getGameHand()->emplace_back(cards07);

    playerVector.at(1)->getGameHand()->emplace_back(cards08);
    playerVector.at(1)->getGameHand()->emplace_back(cards09);
    playerVector.at(1)->getGameHand()->emplace_back(cards10);
    playerVector.at(1)->getGameHand()->emplace_back(cards11);
    playerVector.at(1)->getGameHand()->emplace_back(cards12);
    playerVector.at(1)->getGameHand()->emplace_back(cards13);
    playerVector.at(1)->getGameHand()->emplace_back(cards14);
    playerVector.at(1)->getGameHand()->emplace_back(cards15);

    playerVector.at(2)->getGameHand()->emplace_back(cards15);
    playerVector.at(2)->getGameHand()->emplace_back(cards16);
    playerVector.at(2)->getGameHand()->emplace_back(cards17);
    playerVector.at(2)->getGameHand()->emplace_back(cards18);
    playerVector.at(2)->getGameHand()->emplace_back(cards19);
    playerVector.at(2)->getGameHand()->emplace_back(cards20);
    playerVector.at(2)->getGameHand()->emplace_back(cards21);

    playerVector.at(0)->addPoints(regionOwners.at("sean").size());
    playerVector.at(1)->addPoints(regionOwners.at("mike").size());
    playerVector.at(2)->addPoints(regionOwners.at("jia").size());

    for (int i=0; i < continentOwners.size(); i++) {
        if (continentOwners.at(i).second == "sean") {
            playerVector.at(0)->addPoints(1);
        } else if (continentOwners.at(i).second == "mike") {
            playerVector.at(1)->addPoints(1);
        } else if (continentOwners.at(i).second == "jia") {
            playerVector.at(2)->addPoints(1);
        }
    }

    std::vector<Cards*> *hand1 = playerVector.at(0)->getGameHand();
    std::vector<Cards*> *hand2 = playerVector.at(1)->getGameHand();
    std::vector<Cards*> *hand3 = playerVector.at(2)->getGameHand();
    GameScore gameScore;

    int* sum1 = gameScore.computeGameScore(*hand1);
    int* sum2 = gameScore.computeGameScore(*hand2);
    int* sum3 = gameScore.computeGameScore(*hand3);

    playerVector.at(0)->addPoints(*sum1);
    playerVector.at(1)->addPoints(*sum2);
    playerVector.at(2)->addPoints(10);

    cout << "=========Test GameScore( ) ===============" << endl;
    std::cout << "sean points: " << playerVector.at(0)->getPoints() << endl;
    std::cout << "mike points: " << playerVector.at(1)->getPoints() << endl;
    std::cout << "jia points: " << playerVector.at(2)->getPoints() << endl;

    int winningPlayerIndex = 0;

    for (int i = 0; i < playerVector.size()-1; i++) {
        if (playerVector.at(i)->getPoints() > playerVector.at(i+1)->getPoints()) {
            winningPlayerIndex = i;
        }
        else {
            winningPlayerIndex = i + 1;
        }
    }

    std::cout << endl << "winning player is: " << playerVector.at(winningPlayerIndex)->getName() << endl;



//    Deck deck1;
//    std::vector<Cards*> tb = deck1.topBoardGenetor(deck1);
//    std::vector<Cards*> *hand = new std::vector<Cards*>();
//    deck1.exchange(*hand, tb, deck1);
//    deck1.exchange(*hand, tb, deck1);
//    deck1.exchange(*hand, tb, deck1);
//    deck1.exchange(*hand, tb, deck1);
//    deck1.exchange(*hand, tb, deck1);
//    deck1.exchange(*hand, tb, deck1);
//    deck1.displayTopBoard(tb);
//    deck1.displayHand(*hand);
//    cout << "=========Test GameScore( ) ===============" << endl;
//    std::vector<Player*> *players = new vector<Player*> ();
//    GameScore gameScore;
//    int* sum = gameScore.computeGameScore(*players, *hand);
//    cout << "Game Score for player is " << *sum << " points" << endl;
}
