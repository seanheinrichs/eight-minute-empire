#ifndef EIGHT_MINUTE_EMPIRE_GAMEENGINE_H
#define EIGHT_MINUTE_EMPIRE_GAMEENGINE_H

#include <vector>
#include "../Player/Player.h"

class GameEngine {

public:

    // Gameplay methods
    bool selectGameMode();
    void singleGame();
    void tournamentGame();
};


#endif