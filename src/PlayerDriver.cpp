#include <iostream>
#include "Player.h"

int PlayerDriver(int argc, char *argv[]) {

    // Local variables for testing purposes
    int numOfPlayers;
    int dateOfBirth;
    std::string name;

    // Get input for test user (assuming perfect responses from user)
    std::cout << "Welcome to Eight-Minute-Empire, how many Players will be playing?" << std::endl;
    std::cin >> numOfPlayers;
    std::cout << "What is your name?" << std::endl;
    std::cin >> name;
    std::cout << "How many years old are you? (eg. 18)" << std::endl;
    std::cin >> dateOfBirth;

    // Create user
    Player* testPlayer = new Player(name, numOfPlayers, dateOfBirth);

    // Output Information about the test user
    std::cout << "Hello " << *(testPlayer->getName()) << "You are " << *(testPlayer->getDateOfBirth()) << " years old." << std::endl;
    std::cout << "Each player will start with the following:" << std::endl;
    std::cout << "- " << *(testPlayer->getCoins()) << " coins." << std::endl;
    std::cout << "- " << *(testPlayer->getArmies()) << " armies." << std::endl;
    std::cout << "- " << *(testPlayer->getCities()) << " cities." << std::endl;

    // Method testing

    // Player::payCoin()
    testPlayer->payCoin(2);
    testPlayer->payCoin(2);
    testPlayer->payCoin(2);
    testPlayer->payCoin(2);
    testPlayer->payCoin(2);

    // Player::moveOverWater()
    testPlayer->moveOverWater(3);

    // Player::moveOverLand()
    testPlayer->moveOverLand(3);

    // Player::buildCity()
    testPlayer->buildCity();

    // Player::destroyArmy()
    testPlayer->destroyArmy();

    return 0;
}