#pragma once
#include "GameState.h"

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

  // draw buyable cards

  // generate players
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