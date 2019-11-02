#pragma once
#include "GameStateDriver.h"
#include "GameState.h"
void gameStateDriver()
{
  std::cout << "==== Game Start Driver ====" << std::endl;
  std::cout << "For an example of an invalid map: assets/map2.map" << std::endl;
  std::cout << "For an example of a valid map: assets/map1.map" << std::endl;
  GameState state = GameState();

  // print card information
  std::cout << state.deck->getHandSize();
  std::cout << " cards have been drawn.\n";
  std::cout << state.deck->getDeckSize();
  std::cout << " cards remain in the deck.\n";

  // print player information
  for (int i = 0; i < state.players->size(); i++)
  {
    std::cout << *(state.players->at(i)->getName()) << " has ";
    std::cout << state.players->at(i)->getGameHand()->size()
              << " cards and has a bid of ";
    std::cout << *(state.players->at(i)->getBiddingFacility()->getBid()) << ".\n";
  }
}
