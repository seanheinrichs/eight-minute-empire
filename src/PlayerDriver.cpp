#include <iostream>
#include "Player.h"

int PlayerDriver(int argc, char *argv[]) {

    // local variables for testing
    int numOfPlayers;
    int dateOfBirth;
    std::string name;

    // Get input for test user
    std::cout << "Welcome to Eight-Minute-Empire, how many Players will be playing?" << std::endl;
    std::cin >> numOfPlayers;
    std::cout << "What is your name?" << std::endl;
    std::cin >> name;
    std::cout << "What is your date of birth? (YYMMDD)" << std::endl;
    std::cin >> dateOfBirth;

    // Create user
    Player* testPlayer = new Player(name, numOfPlayers, dateOfBirth);

    // Output Information about the test user
    std::cout << "Hello " << *(testPlayer->getName()) << "You were born on " << *(testPlayer->getDateOfBirth()) <<std::endl;
    std::cout << "Each player will start with the following:" << std::endl;
    std::cout << "- " << *(testPlayer->getCoins()) << " coins." << std::endl;
    std::cout << "- " << *(testPlayer->getArmies()) << " armies." << std::endl;
    std::cout << "- " << *(testPlayer->getCities()) << " cities." << std::endl;

    // payCoin() method testing
    testPlayer->payCoin(2);
    testPlayer->payCoin(2);
    testPlayer->payCoin(2);
    testPlayer->payCoin(2);
    testPlayer->payCoin(2);

    return 0;
}