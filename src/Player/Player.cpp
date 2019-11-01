#include <iostream>
#include <string>
#include "Player.h"
#include "../Map/Map.h"
#include "../BiddingFacility/BiddingFacility.h"

//Constructors

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

// Deconstructor

Player::~Player() {
    delete this->coins;
    delete this->armies;
    delete this->cities;
    delete this->dateOfBirth;
    delete this->name;
    delete this->biddingFacility;
};

// Gameplay Methods

bool Player::payCoin(int cost) {
    if (*(this->getCoins()) < cost) {
        std::cout << "You don't have enough coins to purchase that." << std::endl;
        return false;
    } else {
        this->setCoins(*(this->getCoins()) - cost);
        std::cout << "Successful Purchase, you have " << *(this->getCoins()) << " amount of coins remaining" << std::endl;
        return true;
    }
}

bool Player::placeNewArmies(int totalArmies, std::string regionName, Map gameBoard) {
    return gameBoard.addArmy(regionName, *this->getName());
}

// TODO: Assignment 2
void Player::moveOverWater(int totalMoves) {
    std::cout << "This method will allow the player to move " << totalMoves << " armies across water." << std::endl;
}

// TODO: Assignment 2
void Player::moveOverLand(int totalMoves) {
    std::cout << "This method will allow the player to move " << totalMoves << " armies across land." << std::endl;
}

// TODO: Assignment 2
void Player::buildCity() {
    std::cout << "This method will allow the player to build 1 city." << std::endl;
}

// TODO: Assignment 2
void Player::destroyArmy() {
    std::cout << "This method will allow the player to destroy other player's armies." << std::endl;
}

// Accessors

int* Player::getCoins() const {
    return coins;
}

int* Player::getArmies() const {
    return armies;
}

int* Player::getCities() const {
    return cities;
}

int *Player::getDateOfBirth() const {
    return dateOfBirth;
}

std::string *Player::getName() const {
    return name;
}

BiddingFacility *Player::getBiddingFacility() const {
    return biddingFacility;
}

// Mutators

void Player::setCoins(int coins) {
    *Player::coins = coins;
}

void Player::setArmies(int armies) {
    *Player::armies = armies;
}

void Player::setCities(int cities) {
    *Player::cities = cities;
}

void Player::setDateOfBirth(int dateOfBirth) {
    *Player::dateOfBirth = dateOfBirth;
}

void Player::setName(std::string name) {
    *Player::name = name;
}
