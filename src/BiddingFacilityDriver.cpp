#include <iostream>
#include "Player.h"

int BiddingFacilityDriver(int argc, char *argv[]) {

    // local variables for testing
    int numOfPlayers;
    int dateOfBirth;
    int firstPlayer;
    std::string name;

    // Determine Number Of Players
    std::cout << "Welcome to Eight-Minute-Empire, how many Players will be playing?" << std::endl;
    std::cin >> numOfPlayers;

    std::vector<Player*> players;

    for(int i = 0; i < numOfPlayers; i++) {
        std::cout << "What is your name?" << std::endl;
        std::cin >> name;
        std::cout << "What is your date of birth? (YYMMDD)" << std::endl;
        std::cin >> dateOfBirth;

        players.push_back(new Player(name, numOfPlayers, dateOfBirth));
    }

    for(int i = 0; i < numOfPlayers; i++) {
        std::cout << "Hello " << *(players[i]->getName()) << ". You were born on " << *(players[i]->getDateOfBirth()) <<std::endl;
        std::cout << "You will start with the following:" << std::endl;
        std::cout << "- " << *(players[i]->getCoins()) << " coins." << std::endl;
        std::cout << "- " << *(players[i]->getArmies()) << " armies." << std::endl;
        std::cout << "- " << *(players[i]->getCities()) << " cities." << std::endl;
    }

    firstPlayer = BiddingFacility::biddingPhase(players, numOfPlayers);

    std::cout << "First Player is " << *(players[firstPlayer]->getName());

}