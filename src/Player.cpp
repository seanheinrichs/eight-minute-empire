#include "Player.h"

Player::Player(int numOfPlayers) {
    int numOfCoins;
    int numOfCities = 3;
    int numOfArmies = 14;
    
    switch (numOfPlayers) {
        case 2 :
            numOfCoins = 14;
            Player::coins = &numOfCoins;
            break;
        case 3 :
            numOfCoins = 11;
            Player::coins = &numOfCoins;
            break;
        case 4 :
            numOfCoins = 9;
            Player::coins = &numOfCoins;
            break;
        case 5 :
            numOfCoins = 8;
            Player::coins = &numOfCoins;
            break;
    }
    Player::cities = &numOfCities;
    Player::armies = &numOfArmies;
}

int *Player::getCoins() const {
    return coins;
}

void Player::setCoins(int* coins) {
    Player::coins = coins;
}

int *Player::getArmies() const {
    return armies;
}

void Player::setArmies(int* armies) {
    Player::armies = armies;
}

int *Player::getCities() const {
    return cities;
}

void Player::setCities(int* cities) {
    Player::cities = cities;
}
