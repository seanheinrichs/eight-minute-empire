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
      map = new Map(loader.generateMap(fileLocation));
      validMap = true;
    }

    catch (const char *msg) {
      std::cout << "Error: Invalid map file. ";
      std::cout << msg << std::endl;
    }
  }

  // generate deck of cards
  deck = new Deck::Hand();

  // generate players
  int playerCount;
  std::string name;
  int age;
  std::cout << "How many people are playing? ";
  std::cin >> playerCount;
  std::cout << std::endl;

  // get player names and ages
  for (int i = 0; i < playerCount; i++) {
    std::cout << "What is your name? ";
    std::cin >> name;

    std::cout << "How old are you, in years? ";
    std::cin >> age;

    players->emplace_back(Player(name, playerCount, age));
    std::cout << "Inserted!" << std::endl;
  }
}

GameState::~GameState() {
  if (map) {
    delete map;
    map = NULL;
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