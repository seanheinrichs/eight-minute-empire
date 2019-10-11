#include <iostream>
#include "Player.h"

int PlayerDriver(int argc, char *argv[]) {

    int numOfPlayers;

    std::cout << "Welcome to Eight-Minute-Empire, how many Players will be playing?" << std::endl;
    std::cin >> numOfPlayers;

    Player *testPlayer = new Player(numOfPlayers);

    std::cout << "Each player will start with the following:" << std::endl;
    std::cout << "- " << *(testPlayer->getCoins()) << " coins." << std::endl;
    std::cout << "- " << *(testPlayer->getArmies()) << " armies." << std::endl;
    std::cout << "- " << *(testPlayer->getCities()) << " cities." << std::endl;

    // payCoin() method testing
    testPlayer->payCoin();
    testPlayer->payCoin();
    testPlayer->payCoin();
    testPlayer->payCoin();
    testPlayer->payCoin();
    
}