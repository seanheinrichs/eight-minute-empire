#pragma once

#include "GameScoreDriver.h"
#include "GameScore.h"
#include "Cards.h"
#include "Player.h"
#include "Map.h"

void gameScoreExample() {
    MapLoader loader;

    // std::string fileLocation = "../assets/map1.map"; // for CLION
    std::string fileLocation = "assets/map1.map";       // for VSCODE
    
    Map m = loader.generateMap(fileLocation);

    Cards* cards01 = new Cards(1,"Rock", "MOVE_OVER_WATER 2");
    Cards* cards02 = new Cards(1,"Rock", "MOVE_OVER_WATER 2");
    Cards* cards03 = new Cards(1,"Rock", "PLACE_NEW_ARMIES_ON_BOARD 2");
    Cards* cards04 = new Cards(1,"Crystal", "PLACE_NEW_ARMIES_ON_BOARD 2");
    Cards* cards05 = new Cards(1,"Crystal", "PLACE_NEW_ARMIES_ON_BOARD 2");
    Cards* cards06 = new Cards(1,"Crystal", "PLACE_NEW_ARMIES_ON_BOARD 2");
    Cards* cards07 = new Cards(1,"Crystal", "PLACE_NEW_ARMIES_ON_BOARD 1");
    Cards* cards08 = new Cards(1,"Crystal", "MOVE_OVER_GROUND 2");
    Cards* cards09 = new Cards(1,"Rock", "MOVE_OVER_GROUND 2");
    Cards* cards10 = new Cards(1,"Rock", "MOVE_OVER_WATER 2");
    Cards* cards11 = new Cards(1,"Rock", "MOVE_OVER_WATER 2");
    Cards* cards12 = new Cards(1, "Rock", "MOVE_OVER_WATER 3");
    Cards* cards13 = new Cards(1,"Rock", "PLACE_NEW_ARMIES_ON_BOARD 3");
    Cards* cards14 = new Cards(1,"Rock", "PLACE_NEW_ARMIES_ON_BOARD 3");
    Cards* cards15 = new Cards(1,"Rock", "PLACE_NEW_ARMIES_ON_BOARD 2 OR BUILD_A_CITY 1");
    Cards* cards16 = new Cards(1,"Carrot", "BUILD_A_CITY 1");
    Cards* cards17 = new Cards(1,"Wild", "DESTROY_ARMY 1 AND PLACE_NEW_ARMIES_ON_BOARD 1");
    Cards* cards18 = new Cards(1,"Carrot", "PLACE_NEW_ARMIES_ON_BOARD 3");
    Cards* cards19 = new Cards(1,"Carrot", "MOVE_OVER_GROUND 4");
    Cards* cards20 = new Cards(1,"Carrot", "MOVE_OVER_GROUND 4");
    Cards* cards21 = new Cards(1,"Carrot","PLACE_NEW_ARMIES_ON_BOARD 4 OR MOVE_OVER_GROUND 2");

    Player *sean = new Player("sean", 3, 15);
    Player *mike = new Player("mike", 3, 16);
    Player *jia = new Player("jia", 3, 17);
    std:: vector <Player*> playerVector = {jia, mike, sean};

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

    GameScore gameScore;
    gameScore.generateWinner(playerVector, m);
}