#pragma once
#include "Cards.h"
#include "Map.h"
#include "MapLoader.h"
#include "Player.h"
#include <iostream>

class GameState {
public:
  // game state member variables public as their purpose is to be mutated
  // throughout the game

  // game map
  Map *map;

  // deck of cards and hand placed on table
  Deck::Hand *deck;

  // players
  std::vector<Player> *players;

  GameState();
  ~GameState();
};