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

    cout << "From board " << playerVector.at(0)->getName() <<" gets " << playerVector.at(0)->getPoints() << " points" << endl;
    cout << "From board " << playerVector.at(1)->getName() <<" gets " << playerVector.at(1)->getPoints() << " points" << endl;
    cout << "From board " << playerVector.at(2)->getName() <<" gets " << playerVector.at(2)->getPoints() << " points" << endl;
    cout << "=======================================================\n"<< endl;

    cout << "============= adding cards' points===================" << endl;
    GameScore gameScore;

    int* sum1 = gameScore.computeGameScore(playerVector.at(0));
    int* sum2 = gameScore.computeGameScore(playerVector.at(1));
    int* sum3 = gameScore.computeGameScore(playerVector.at(2));

    cout << "From cards " << playerVector.at(0)->getName() <<" gets " << *sum1 << " points" << endl;
    cout << "From cards " << playerVector.at(1)->getName() <<" gets " << *sum2 << " points" << endl;
    cout << "From cards " << playerVector.at(2)->getName() <<" gets " << *sum3 << " points" << endl;

    playerVector.at(0)->addPoints(*sum1);
    playerVector.at(1)->addPoints(*sum2);
    playerVector.at(2)->addPoints(*sum3);

    cout << "=========Test GameScore( ) ===============" << endl;
    std::cout << playerVector.at(0)->getName() << "'s points: " << playerVector.at(0)->getPoints() << endl;
    std::cout << playerVector.at(1)->getName() << "'s points: " << playerVector.at(1)->getPoints() << endl;
    std::cout << playerVector.at(2)->getName() << "'s points: " << playerVector.at(2)->getPoints() << endl;
    cout << "=======================================================\n"<< endl;
    gameScore.winnerGenerator(playerVector);
    cout << "=======================================================\n"<< endl;

}
