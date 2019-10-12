#include <iostream>
#include "Player.h"

int BiddingFacilityDriver(int argc, char *argv[]) {

    // Local variables for testing
    int numOfPlayers;
    int dateOfBirth;
    int firstPlayer;
    std::string name;

    // Determine Number Of Players
    std::cout << "Welcome to Eight-Minute-Empire, how many Players will be playing?" << std::endl;
    std::cin >> numOfPlayers;
    std::vector<Player*> players;

    // Create all Players in Player vector
    for(int i = 0; i < numOfPlayers; i++) {
        std::cout << "What is your name?" << std::endl;
        std::cin >> name;
        std::cout << "How many years old are you? (eg 18)" << std::endl;
        std::cin >> dateOfBirth;

        players.push_back(new Player(name, numOfPlayers, dateOfBirth));
    }

    // Determine the first Player within the bidding phase
    firstPlayer = BiddingFacility::biddingPhase(players, numOfPlayers);
    std::cout << "First Player is " << *(players[firstPlayer]->getName());

}