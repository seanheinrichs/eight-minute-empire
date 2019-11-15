#include "GameScore.h"
#include "Player.h"
#include "Cards.h"
#include "GameState.h"
#include "Map.h"

void GameScore::generateWinner(std::vector<Player *> &players, Map &gameBoard) {

    auto regionOwners = gameBoard.getRegionOwners();
    auto continentOwners = gameBoard.getContinentOwners();

    // count points from regions
    for (int i = 0; i < players.size(); i++) {
        players.at(i)->addPoints(regionOwners.at(players.at(i)->getName()).size());
    }

    // count points from continents
    for (int i = 0; i < continentOwners.size(); i++) {
        if (continentOwners.at(i).second == players.at(0)->getName()) {
            players.at(0)->addPoints(1);
        }
        else if (continentOwners.at(i).second == players.at(1)->getName()) {
            players.at(1)->addPoints(1);
        }
        else if (players.size() == 3 && continentOwners.at(i).second == players.at(2)->getName()) {
            players.at(2)->addPoints(1);
        }
        else if (players.size() == 4 && continentOwners.at(i).second == players.at(3)->getName()) {
            players.at(3)->addPoints(1);
        }
        else if (players.size() == 5 && continentOwners.at(i).second == players.at(4)->getName()) {
            players.at(4)->addPoints(1);
        }
    }

    // count points from hand
    for (int i = 0; i < players.size(); i++) {
        countPointsInHand(*players.at(i));
    }

    // display final scores
    std::cout << "Here are the final scores: " << endl;
    for (int i = 0; i < players.size(); i++) {
        std::cout << players.at(i)->getName() << ": " << players.at(i)->getPoints() << endl;
    }

    // calculate winner
    int winningPlayerIndex = 0;

    for (int i = 0; i < players.size() - 1; i++) {
        if (players.at(winningPlayerIndex)->getPoints() < players.at(i + 1)->getPoints()) {
            winningPlayerIndex = i + 1;
        }
    }

    std::cout << endl << "The winner is: " << players.at(winningPlayerIndex)->getName() << "!" << endl;
}

// Utility Methods

void GameScore::countPointsInHand(Player &player) {

    // goods to be counted
    int rocks = countGoods(*player.getGameHand(), "Rock");
    int crystals = countGoods(*player.getGameHand(), "Crystal");
    int anvils = countGoods(*player.getGameHand(), "Anvil");
    int carrots = countGoods(*player.getGameHand(), "Carrot");
    int trees = countGoods(*player.getGameHand(), "Tree");
    int wilds = countGoods(*player.getGameHand(), "Wild");

    // display player's hand
    std::cout << player.getName() <<  ", you have the following goods: " <<endl;
    std::cout << "- Rocks: " << rocks << endl;
    std::cout << "- Crystals: " << crystals << endl;
    std::cout << "- Anvils: " << anvils << endl;
    std::cout << "- Carrots: " << carrots << endl;
    std::cout << "- Trees: " << trees << endl;
    std::cout << "- Wilds: " << wilds << endl;

    // if the user has wilds, allow them to exchange
    if (wilds > 0) {
        std::cout << "You can make your wild cards any of the following: Rock | Crystal | Anvil | Carrot | Tree " << endl;
        for (int i = 0; i < wilds; i++) {

            std::string wildExchange = validateGood();

            if (wildExchange == "Rock") {
                rocks++;
            }
            else if (wildExchange == "Tree") {
                trees++;
            }
            else if (wildExchange == "Crystal") {
                crystals++;
            }
            else if (wildExchange == "Carrot") {
                carrots++;
            }
            else if (wildExchange == "Anvil") {
                anvils++;
            }
        }
    }

    // calculate point totals for each good
    rocks = countRockPoints(rocks);
    crystals = countCrystalPoints(crystals);
    anvils = countAnvilPoints(anvils);
    carrots = countCarrotPoints(carrots);
    trees = countTreePoints(trees);

    player.addPoints(rocks + crystals + anvils + carrots + trees);
}

int GameScore::countTreePoints(int tree) {
    if (tree < 2) {
        return 0;
    }
    else if (tree < 4) {
        return 1;
    }
    else if (tree == 4) {
        return 2;
    }
    else if (tree == 5) {
        return 3;
    }
    else {
        return 5;
    }
}

int GameScore::countAnvilPoints(int anvil) {
    if (anvil < 2) {
        return 0;
    }
    else if (anvil < 4) {
        return 1;
    }
    else if (anvil < 6) {
        return 2;
    }
    else if (anvil == 6) {
        return 3;
    }
    else {
        return 5;
    }
}

int GameScore::countCarrotPoints(int carrot) {
    if (carrot < 2) {
        return 0;
    }
    else if (carrot < 5) {
        return 1;
    }
    else if (carrot < 7) {
        return 2;
    }
    else if (carrot == 7) {
        return 3;
    }
    else {
        return 5;
    }
}

int GameScore::countRockPoints(int rock) {
    if (rock < 2) {
        return 0;
    }
    else if (rock < 3) {
        return 1;
    }
    else if (rock < 4) {
        return 2;
    }
    else if (rock == 4) {
        return 3;
    }
    else {
        return 5;
    }
}

int GameScore::countCrystalPoints(int crystal) {
    if (crystal < 1) {
        return 0;
    }
    else if (crystal == 1) {
        return 1;
    }
    else if (crystal == 2) {
        return 2;
    }
    else if (crystal == 3) {
        return 3;
    }
    else {
        return 4;
    }
}

int GameScore::countGoods(std::vector<Cards*> &gameHand, std::string good) {
    int sum = 0;
    for (int i = 0; i < gameHand.size(); i++) {
        if (*gameHand[i]->getGood() == good) {
            sum += *gameHand[i]->getNumOfGood();
        }
    }
    return sum;
}

std::string GameScore::validateGood() {
    bool invalidGood = false;
    std::string good;

    std::cout << "Which card would you like to choose: ";
    do {
        std::cin >> good;
        if (good == "Tree" || good == "Rock" || good == "Anvil" || good == "Crystal" || good == "Carrot") {
            invalidGood = false;
        }
        else {
            invalidGood = true;
            cout << "That is an invalid selection. Please choose another good: ";
        }
    } while (invalidGood);

    return good;
}