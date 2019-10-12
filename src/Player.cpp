#include <iostream>
#include <string>
#include "Player.h"
#include "Map.h"
#include "BiddingFacility.h"

Player::Player(std::string name, int dateOfBirth) {
    Player::cities = new int(3);
    Player::armies = new int(14);
    Player::coins = new int(14);
    Player::name = new std::string(name);
    Player::dateOfBirth = new int(dateOfBirth);
    Player::biddingFacility = new BiddingFacility();
}

Player::Player(std::string name, int numOfPlayers, int dateOfBirth) {
    Player::cities = new int(3);
    Player::armies = new int(14);
    Player::name = new std::string(name);
    Player::dateOfBirth = new int(dateOfBirth);
    Player::biddingFacility = new BiddingFacility();

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
// TODO: Should return a boolean that triggers the Player to make a new purchase
void Player::payCoin(int cost) {

    if (*(this->getCoins()) < cost) {
        std::cout << "You don't have enough coins to purchase that" << std::endl;
    } else {
        this->setCoins(*(this->getCoins()) - cost);
        std::cout << "Successful Purchase. You have " << *(this->getCoins()) << " amount of coins remaining" << std::endl;
    }
}

bool Player::placeNewArmies(int totalArmies, std::string regionName, Map gameBoard) {
    return gameBoard.addArmy(regionName, *this->getName());
}

//bool moveOverWater(int totalMoves) {
//    if () {
//        return true;
//    } else {
//        return false
//    }
//}
//
//bool moveOverLand(int totalMoves) {
//    if () {
//        return true;
//    } else {
//        return false
//    }
//}
//
//bool buildCity() {
//    if () {
//        return true;
//    } else {
//        return false
//    }
//}
//
//bool destroyArmy() {
//    if () {
//        return true;
//    } else {
//        return false
//    }
//}

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

int *Player::getDateOfBirth() const {
    return dateOfBirth;
}

std::string *Player::getName() const {
    return name;
}

void Player::setDateOfBirth(int dateOfBirth) {
    *Player::dateOfBirth = dateOfBirth;
}

void Player::setName(std::string name) {
    *Player::name = name;
}

BiddingFacility *Player::getBiddingFacility() const {
    return biddingFacility;
}
