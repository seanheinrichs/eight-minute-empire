#include <iostream>

#include "PlayerStrategiesDriver.h"
#include "Player.h"

void playerStrategiesDriver() {

    Player* player1 = new Player("Sean", 3, 55);

    player1->getPlayerStrategies()->selectAction();

    player1->setPlayerStrategy(new GreedyComputer);

    player1->getPlayerStrategies()->selectAction();

    player1->setPlayerStrategy(new ModerateComputer);

    player1->getPlayerStrategies()->selectAction();
}