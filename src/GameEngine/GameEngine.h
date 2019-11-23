#ifndef EIGHT_MINUTE_EMPIRE_GAMEENGINE_H
#define EIGHT_MINUTE_EMPIRE_GAMEENGINE_H

#include <vector>
#include "../Player/Player.h"

class GameEngine {

private:
    bool * isTournamentGame;

public:
    // Gameplay methods
    bool selectGameMode();
    std::vector<Player *> createPlayers();
    void singleGame();
    void tournamentGame();

    // Accessor Methods
    bool getIsTournamentGame();

    // Mutator Methods
    void setIsTournamentGame();
};


#endif