#pragma once
#include "GameState.h"
#include "Player.h"
#include <utility>

GameState::GameState() {

  // generate map
  bool validMap = false;

  // will run until a valid map is provided
  while (!validMap) {
    try {
      // get file location
      std::string fileLocation;
      std::cout << "Enter map file location: ";
      std::cin >> fileLocation;

      // load map
      MapLoader loader;
      //map = new Map(loader.generateMap(fileLocation));
      map = loader.generateMap(fileLocation);
      validMap = true;
    }

    catch (const char *msg) {
      std::cout << "Error: Invalid map file. ";
      std::cout << msg << std::endl;
    }
  }

  // generate deck of cards
  deck = new Deck();

  // generate players
  players = new std::vector<Player *>();
  int playerCount;
  std::cout << "How many people are playing (2-5)? ";
  std::cin >> playerCount;
  while (playerCount < 2 || playerCount > 5) {
      std::cout << "Invalid player count, please select a number between 2 and 5: ";
      std::cin >> playerCount;
  }
  std::cout << std::endl;

  // get player names and ages
  for (int i = 0; i < playerCount; i++) {
    std::string name;
    int age;

    std::cout << "What is your name? ";
    std::cin >> name;

    std::cout << "How old are you, in years? ";
    std::cin >> age;

    players->emplace_back(new Player(name, playerCount, age));
  }
}

GameState::~GameState() {
  if (map) {
      Map::resetMapInstance();
//    delete map;
//    map = NULL;
  }
  if (players) {
    delete players;
    players = NULL;
  }
  if (deck) {
    delete deck;
    deck = NULL;
  }
}

int GameState::determineGameLength() {
    switch (players->size()) {
        case (2):
            return 13;
        case (3):
            return 10;
        case (4):
            return 8;
        case (5):
            return 7;
    }
}