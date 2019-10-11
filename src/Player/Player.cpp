#include "Player.h"
#include <iostream>

Player::Player() {
    Player::cities = new int(3);
    Player::armies = new int(14);
    Player::coins = new int(14);
}

Player::Player(int numOfPlayers) {
    Player::cities = new int(3);
    Player::armies = new int(14);

    // Amount of coins available to Players is determined by # of Players
    switch (numOfPlayers) {
        case 2 :
            Player::coins = new int(14);
            break;
        case 3 :
            Player::coins = new int(11);
            break;
        case 4 :
            Player::coins = new int(9);
            break;
        case 5 :
            Player::coins = new int(8);
            break;
    }
}

// Gameplay Methods

// TODO: Amount of coins should reflect cost of card
// TODO: Discuss with team whether this method should implement not having enough coins to purchase logic (throw exception?)
void Player::payCoin() {
    int exampleCardCost = 2;

    if (*(this->getCoins()) < exampleCardCost) {
        std::cout << "You don't have enough coins to purchase that" << std::endl;
    } else {
        this->setCoins(*(this->getCoins()) - exampleCardCost);
        std::cout << "Successful Purchase. You have " << *(this->getCoins()) << " amount of coins remaining" << std::endl;
    }
}

// Accessor and Mutator Methods

int* Player::getCoins() const {
    return coins;
}

void Player::setCoins(int coins) {
    *Player::coins = coins;
}

int* Player::getArmies() const {
    return armies;
}

void Player::setArmies(int armies) {
    *Player::armies = armies;
}

int* Player::getCities() const {
    return cities;
}

void Player::setCities(int cities) {
    *Player::cities = cities;
}
