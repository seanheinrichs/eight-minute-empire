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

    Player *sean = new Player("sean", 3, 15);
    Player *mike = new Player("mike", 3, 16);
    Player *jia = new Player("jia", 3, 17);
    std:: vector <Player*> playerVector = {sean, mike, jia};

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

    cout << "=========Test GameScore( ) ===============" << endl;
    GameScore gameScore;
    cout << "=======================================================\n"<< endl;
    gameScore.winnerGenerator(playerVector, m);
    cout << "=======================================================\n"<< endl;

}
