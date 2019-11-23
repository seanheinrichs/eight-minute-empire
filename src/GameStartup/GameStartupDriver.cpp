#pragma once
#include "GameStartup.h"
#include "GameStartupDriver.h"
#include "GameState.h"

void gameStartupExample()
{
  GameState state();
  std::cout << "When the game state is created, the deck is shuffled.\n";
  std::cout << "At the same time 6 cards are drawn.\n";
  std::cout << "In the two game states below, the cards are shuffled different.\n";
  std::cout << "They are drawn from the top of shuffled deck and are therefore different.\n";
  std::cout << "==== MAKE SURE TO LOAD THE FOLLOWING EMPTY MAP: assets/map8.map ====\n";
  GameState state1 = GameState(false);
  GameState state2 = GameState(false);

  std::cout << "Now that we have loaded the map and created the game's state, let's start the game:\n";
  int firstPlayerIndex = startGame(state1);

  std::cout << "The startup phase is completed. Here's the map:\n";
  state1.map->printNodes();

  std::cout << "And here is the first player and their index in the vector of players: " << state1.players->at(firstPlayerIndex)->getName() << ", " << firstPlayerIndex << std::endl;

  std::cout << "Here are the details for each player:\n";
  for (int i = 0; i < state1.players->size(); i++)
  {
    std::cout << "Name: " << state1.players->at(i)->getName() << std::endl;
    std::cout << "Age: " << state1.players->at(i)->getAge() << std::endl;
    std::cout << "Armies: " << state1.players->at(i)->getArmies() << std::endl;
    std::cout << "Cities: " << state1.players->at(i)->getCities() << std::endl;
    std::cout << "Coins: " << state1.players->at(i)->getCoins() << "\n\n";
  }
}
