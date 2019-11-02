#include "Player.h"
#include "../BiddingFacility/BiddingFacility.h"
#include "../Map/Map.h"
#include <iostream>
#include <string>

// Constructors

Player::Player(std::string name, int dateOfBirth) {
  Player::cities = new int(3);
  Player::armies = new int(14);
  Player::coins = new int(14);
  Player::name = new std::string(name);
  Player::dateOfBirth = new int(dateOfBirth);
  Player::biddingFacility = new BiddingFacility();
  Player::gameHand = new std::vector<Cards>;
}

Player::Player(std::string name, int numOfPlayers, int dateOfBirth) {
  Player::cities = new int(3);
  Player::armies = new int(14);
  Player::name = new std::string(name);
  Player::dateOfBirth = new int(dateOfBirth);
  Player::biddingFacility = new BiddingFacility();
  Player::gameHand = new std::vector<Cards>;

  // Amount of coins available to Players is determined by # of Players
  switch (numOfPlayers) {
  case 2:
    Player::coins = new int(14);
    break;
  case 3:
    Player::coins = new int(11);
    break;
  case 4:
    Player::coins = new int(9);
    break;
  case 5:
    Player::coins = new int(8);
    break;
  }
}

// Deconstructor

Player::~Player() {
  if (coins) {
    delete coins;
    coins = NULL;
  }
  if (armies) {
    delete armies;
    armies = NULL;
  }
  if (cities) {
    delete cities;
    cities = NULL;
  }
  if (dateOfBirth) {
    delete dateOfBirth;
    dateOfBirth = NULL;
  }
  if (name) {
    delete name;
    name = NULL;
  }
  if (biddingFacility) {
    delete biddingFacility;
    biddingFacility = NULL;
  }
  if (regions) {
    delete regions;
    regions = NULL;
  }
  if (countries) {
    delete countries;
    countries = NULL;
  }
};

// Gameplay Methods

bool Player::payCoin(int cost) {
  if (*(this->getCoins()) < cost) {
    std::cout << "You don't have enough coins to purchase that." << std::endl;
    return false;
  } else {
    this->setCoins(*(this->getCoins()) - cost);
    std::cout << "Successful Purchase, you have " << *(this->getCoins())
              << " amount of coins remaining" << std::endl;
    return true;
  }
}

bool Player::placeNewArmies(int totalArmies, std::string regionName,
                            Map gameBoard) {
  return gameBoard.addArmy(regionName, *this->getName());
}

// TODO: Assignment 2
void Player::moveOverWater(int totalMoves) {
  std::cout << "This method will allow the player to move " << totalMoves
            << " armies across water." << std::endl;
}

// TODO: Assignment 2
void Player::moveOverLand(int totalMoves) {
  std::cout << "This method will allow the player to move " << totalMoves
            << " armies across land." << std::endl;
}

// TODO: Assignment 2
void Player::buildCity() {
  std::cout << "This method will allow the player to build 1 city."
            << std::endl;
}

// TODO: Assignment 2
void Player::destroyArmy() {
  std::cout
      << "This method will allow the player to destroy other player's armies."
      << std::endl;
}

// Accessors

int *Player::getCoins() const { return coins; }

int *Player::getArmies() const { return armies; }

int *Player::getCities() const { return cities; }

int *Player::getDateOfBirth() const { return dateOfBirth; }

std::string *Player::getName() const { return name; }

std::vector<Cards> *Player::getGameHand() const { return gameHand; }

BiddingFacility *Player::getBiddingFacility() const { return biddingFacility; }

// Mutators

void Player::setCoins(int coins) { *Player::coins = coins; }

void Player::setArmies(int armies) { *Player::armies = armies; }

void Player::setCities(int cities) { *Player::cities = cities; }

void Player::setDateOfBirth(int dateOfBirth) {
  *Player::dateOfBirth = dateOfBirth;
}

void Player::setName(std::string name) { *Player::name = name; }

void Player::addCards(Cards card) {
  gameHand->emplace_back(Cards(card.getGood(), card.getAction()));
}
