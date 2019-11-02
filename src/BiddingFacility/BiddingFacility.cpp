#include <iostream>
#include "BiddingFacility.h"

// Constructor

BiddingFacility::BiddingFacility() {
    BiddingFacility::bid = new int(0);
}

// Destructor

BiddingFacility::~BiddingFacility() {
    delete bid;
}

// Gameplay Methods

// TODO: Add verification to ensure that players can afford opening bid (for A1 assume user perfect inputs)
// Returns the index of the player who goes first (ie. to determine player order)
int BiddingFacility::biddingPhase(std::vector<Player*> players, int numberOfPlayers) {

    // Local Variables
    int bid, highestBid, highestBidder;

    // Each player gets a chance to enter a bid
    for (int i = 0; i < numberOfPlayers; i++) {
        std::cout << "How much would you like to bid " << *(players[i]->getName()) << "?" << std::endl;
        std::cin >> bid;
        players[i]->getBiddingFacility()->setBid(bid);
    }

    // Assume player 1 (index 0) has the highest bid
    highestBidder = 0;
    highestBid = *(players[0]->getBiddingFacility()->getBid());

    // Bids are compared and index of the highest bidder is going to be returned
    for (int i = 0; i < numberOfPlayers-1; i++){
        if (highestBid < *(players[i + 1]->getBiddingFacility()->getBid())) {
            highestBidder = i + 1;
            highestBid = *(players[i + 1]->getBiddingFacility()->getBid());
        }
        /* If bids are tied, the younger player becomes the higher bidder
           If they are the same age the "first" bidder is the higher bidder*/
        if (highestBid == *(players[i + 1]->getBiddingFacility()->getBid())
        && *(players[highestBidder]->getAge()) > *(players[i+1]->getAge())) {
            highestBidder = i + 1;
        }
    }

    // Highest bidder pays the cost
    players[highestBidder]->payCoin(*(players[highestBidder]->getBiddingFacility()->getBid()));

    return highestBidder;
}

// Accessors

int *BiddingFacility::getBid() const {
    return bid;
}

// Mutators

void BiddingFacility::setBid(int bid) {
    *BiddingFacility::bid = bid;
}
