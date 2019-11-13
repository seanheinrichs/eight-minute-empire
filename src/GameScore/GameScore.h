#ifndef EIGHT_MINUTE_EMPIRE_GAMESCORE_H
#define EIGHT_MINUTE_EMPIRE_GAMESCORE_H

#include "Player.h"
#include "Cards.h"
#include "GameState.h"
#include "Map.h"

class GameScore {
private:
    // Utility Methods
    std::string validateGood();
    int countGoods(std::vector<Cards*> &gameHand, std::string good);
    void countPointsInHand(Player &player);
    int countTreePoints(int tree);
    int countAnvilPoints(int anvil);
    int countCarrotPoints(int carrot);
    int countRockPoints(int rock);
    int countCrystalPoints(int crystal);

public:

    // gameplay methods
    void generateWinner (std::vector<Player*> &players, Map &gameBoard);
};

#endif //EIGHT_MINUTE_EMPIRE_GAMESCORE_H
