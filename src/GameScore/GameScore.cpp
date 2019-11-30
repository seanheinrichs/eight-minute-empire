#include <string> 
#include <algorithm>
#include "GameScore.h"
#include "Player.h"
#include "Cards.h"
#include "GameState.h"
#include "Map.h"

void GameScore::generateWinner(std::vector<Player *> &players, Map &gameBoard) {

    auto continentOwners = gameBoard.getContinentOwners();

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

    // display the table of the game's stats once it has ended
    gameResultTable(players);

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
    
    // If a computer has wildcards, assign them to the good they have the most of
    if (player.getPlayerStrategies()->displayCurrentStrategy().compare("Human Player") != 0 && wilds > 0) {
        // Find the good the player has the most of
        int maxGood = std::max({rocks, crystals, anvils, carrots, trees});

        // note that this is not a switch statement since the values being compared are not constants
        if (maxGood == rocks) {
            rocks += maxGood;
        }
        else if (maxGood == crystals) {
            crystals += maxGood;
        }
        else if (maxGood == anvils) {
            anvils += maxGood;
        }
        else if (maxGood == carrots) {
            carrots += maxGood;
        }
        else if (maxGood == trees) {
            trees += maxGood;
        }
    }

    // If a human player, display relevant information and allow them to choose to allocate wilds
    else if (player.getPlayerStrategies()->displayCurrentStrategy().compare("Human Player") == 0) {
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

    void GameScore::gameResultTable(std::vector<Player*> &players) {
        // width for each cell of the table
        // added one char to length to space out columns
        int playerWidth = 8;
        int cardsWidth = 6;
        int pointsWidth = 15;
        int coinsWidth = 6;

        // widen the Player column if a player has a long name
        for (int i=0; i < players.size(); i++) {
            int size = players.at(i)->getName().length();
            if (++size > playerWidth) {
                playerWidth = size;
            }
        }
        // add any needed padding to the player header
        std::string playerHeader = paddedTableEntry("Player", playerWidth);

        // make the underline the correct length
        std::string playerHeaderUnderline = "";
        for (int i=0; i < playerWidth; i++) {
            playerHeaderUnderline += "-";
        }

        // print the headers
        std::cout << "|" << playerHeader << "|Cards " << "|Victory Points " << "|Coins |" << std::endl;
        std::cout << "|" << playerHeaderUnderline << "|------" << "|---------------" << "|------|" << std::endl;

        // loop over each player and print their stats
        for (int i=0; i < players.size(); i++) {
            // get padded table entries
            std::string name = paddedTableEntry(players.at(i)->getName(), playerWidth);
            std::string cards = paddedTableEntry(players.at(i)->getGameHand()->size(), cardsWidth);
            std::string points = paddedTableEntry(players.at(i)->getPoints(), pointsWidth);
            std::string coins = paddedTableEntry(players.at(i)->getCoins(), coinsWidth);

            // print the column
            std::cout << "|" << name << "|" << cards << "|" << points << "|" << coins << "|" << std::endl;
        }
        
    }

// utility method to pad table entries such that columns align
std::string GameScore::paddedTableEntry(std::string data, int length) {
    int pad = length - data.length();

    for (int i=0; i < pad; i++) {
        data += " ";
    }

    return data;
}

// handle case where an int needs to be padded with spaces
std::string GameScore::paddedTableEntry(int data, int length) {
    std::string castData = std::to_string(data);
    return paddedTableEntry(castData, length);
}