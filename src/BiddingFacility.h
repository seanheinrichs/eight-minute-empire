#ifndef EIGHT_MINUTE_EMPIRE_BIDDINGFACILITY_H
#define EIGHT_MINUTE_EMPIRE_BIDDINGFACILITY_H

#include "Player.h"
#include <vector>

// TODO: Get rid of the this forward declaration. Current it's only to make the compiler happy.
class Player;

class BiddingFacility {

private:
    int* bid;

public:

    // Constructor
    BiddingFacility();

    // Gameplay Methods
    static int biddingPhase(std::vector<Player*> players, int numberOfPlayers);

    // Accessors
    int *getBid() const;

    // Mutators
    void setBid(int bid);
};

#endif