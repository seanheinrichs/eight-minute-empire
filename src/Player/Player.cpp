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

    if (*coins < cost) {
        std::cout << "You don't have enough coins to purchase that." << std::endl;
        return false;
    }
    else {
        this->setCoins(*coins - cost);
        std::cout << "Successful Purchase, you have " << *coins << " amount of coins remaining" << std::endl;
        return true;
    }
}

// TODO: Main should be calling this one army at a time.
bool Player::placeNewArmies(int totalArmies, Map &gameBoard) {

    // Loval Variables
    std::string regionName;
    int spendableArmies;

    // If user has no available armies, end turn
    if (*armies == 0) {
        std:: cout << "Sorry, you have no more available armies to place." << endl;
        return false;
    }

    // If user doesn't have enough armies to fulfill the value on card, place remaining armies
    if (totalArmies > *armies) {
        spendableArmies = *armies;
    }
    else {
        spendableArmies = totalArmies;
    }

    std::cout << "You have " << spendableArmies << " armies to place on the map." << endl;
    std::cout << "Here are the areas in which you may place an army: " << endl;
    // TODO: Create method to retrieve areas in which a player can place a unit (only start or cities)

    // Place a single unit on each iteration of the loop
    for (int i = 0; i < spendableArmies; i++) {
        std::cout << "Where would you like to place your army? " << endl;
        // TODO: Validate regionName to ensure its one of the available locations
        std::cin >> regionName;

        (*armies)--;
        gameBoard.addArmy(regionName, *name);
    }

    return true;
}

// TODO: Assignment 2
bool Player::moveOverWater(int totalMoves) {
    std::cout << "This method will allow the player to move " << totalMoves << " armies across water." << std::endl;
    return true;
}

// TODO: Assignment 2
bool Player::moveOverLand(int totalMoves) {
    std::cout << "This method will allow the player to move " << totalMoves << " armies across land." << std::endl;
    return true;
}

bool Player::buildCity(Map &gameBoard) {

    std::string regionName;

    std::cout << "Here are the areas in which you may place a city: " << std::endl;
    // TODO: Create method to retrieve areas in which a player can place a unit (only start or cities)
    std::cin >> regionName;

    gameBoard.addCity(regionName, *name);

    return true;
}

// TODO: Assignment 2
bool Player::destroyArmy() {
    std::cout << "This method will allow the player to destroy other player's armies." << std::endl;
    return true;
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
