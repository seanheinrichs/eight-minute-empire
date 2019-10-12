#ifndef EIGHT_MINUTE_EMPIRE_BIDDINGFACILITY_H
#define EIGHT_MINUTE_EMPIRE_BIDDINGFACILITY_H

#include "Player.h"
#include <vector>

// Forward Declaration
class Player;

class BiddingFacility {

private:
    int* bid;

public:
    // Constructor
    BiddingFacility();

    // Deconstructor
    ~BiddingFacility();

    // Gameplay Methods
    static int biddingPhase(std::vector<Player*> players, int numberOfPlayers);

    // Accessors
    int *getBid() const;

    // Mutators
    void setBid(int bid);
};

#endif
