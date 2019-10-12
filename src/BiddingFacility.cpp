#include <iostream>
#include "BiddingFacility.h"

BiddingFacility::BiddingFacility() {
    BiddingFacility::bid = new int(0);
}

int BiddingFacility::biddingPhase(std::vector<Player*> players, int numberOfPlayers) {

    int bid, max;
    // TODO: Loop through player array instead of this this new array
    int bidArray [numberOfPlayers];
    int highestBidder = 0;

    // Each player enters a bid
    for (int i = 0; i < numberOfPlayers; i++) {
        std::cout << "How much would you like to bid " << *(players[i]->getName()) << "?" << std::endl;
        std::cin >> bid;
        players[i]->getBiddingFacility()->setBid(bid);
        // TODO: Remove this sloppy code
        bidArray[i] = *(players[i]->getBiddingFacility()->getBid());
    }

    // Temp Code to display array
    for (int i = 0; i < numberOfPlayers; i++) {
        std::cout << *(players[i]->getName()) << " has bid " << bidArray[i] << " coins" << std::endl;
    }

    // set the max to the first array
    max = bidArray[0];

    // Bids are compared and index of the highest bidder is going to be returned
    for (int i = 0; i < numberOfPlayers-1; i++){
        if (max < bidArray[i + 1]) {
            highestBidder = i + 1;
            max = bidArray[i + 1];
        }
        // Younger player always prevails, if tied then the "first" bidder goes first
        if (max == bidArray[i + 1]) {
            if (*(players[highestBidder]->getDateOfBirth()) > *(players[i+1]->getDateOfBirth())) {
                highestBidder = i + 1;
            }
        }
    }

    players[highestBidder]->payCoin(*(players[highestBidder]->getBiddingFacility()->getBid()));

    return highestBidder;
}

int *BiddingFacility::getBid() const {
    return bid;
}

void BiddingFacility::setBid(int bid) {
    *BiddingFacility::bid = bid;
}
