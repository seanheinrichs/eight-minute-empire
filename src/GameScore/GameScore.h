
#ifndef EIGHT_MINUTE_EMPIRE_GAMESCORE_H
#define EIGHT_MINUTE_EMPIRE_GAMESCORE_H

#include "Player.h"
#include "Cards.h"
#include "GameState.h"
#include "Map.h"

class GameScore {
    int* point;

public:
    GameScore();

    virtual ~GameScore();

    // compute points of cards with the same good type
    int* countTreePoint(int *tree);

    int* countAnvilPoint(int *anvil);

    int* countCarrotPoint(int *carrot);

    int* countRockPoint(int *rock);

    int* countCrystalPoint(int *crystal);

    // first count number of the same good type
    int* numOfTree(std::vector<Cards*> &gameHand);

    int* numOfAnvil(std::vector<Cards*> &gameHand);

    int* numOfCarrot(std::vector<Cards*> &gameHand);

    int* numOfRock(std::vector<Cards*> &gameHand);

    int* numOfCrystal(std::vector<Cards*> &gameHand);

    int* numOfWild(std::vector<Cards*> &gameHand);

    int* computeGameScore(Player* &players);

    void winnerGenerator ( std:: vector <Player*> &playerVector, Map &gameBoard);

};


#endif //EIGHT_MINUTE_EMPIRE_GAMESCORE_H
