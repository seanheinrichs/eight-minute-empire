#pragma once
#include "GameState.h"
#include <utility>

GameState::GameState() {
  // generate map
  std::string fileLocation;
  std::cout << "Enter map file location: ";
  std::cin >> fileLocation;
  std::cout << std::endl;

  // load map
  MapLoader loader;
  map = new Map(loader.generateMap(fileLocation));

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
    std::cout << std::endl;

    std::cout << "How old are you, in years? ";
    std::cin >> age;
    std::cout << std::endl;

    players->insert(
        std::pair<std::string, Player>(name, Player(name, playerCount, age)));
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