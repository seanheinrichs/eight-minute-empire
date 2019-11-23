#pragma once
#include "GameStateDriver.h"
#include "GameState.h"
void gameStateDriver()
{
  std::cout << "==== Game Start Driver ====" << std::endl;
  std::cout << "For an example of an invalid map: assets/map2.map" << std::endl;
  std::cout << "For an example of a valid map: assets/map1.map" << std::endl;
  GameState state1 = GameState(false);
  GameState state2 = GameState(false);

  auto topBoard1 = state1.deck->topBoardGenetor(*state1.deck);
  auto topBoard2 = state2.deck->topBoardGenetor(*state2.deck);

  state1.deck->displayTopBoard(topBoard1);
  state2.deck->displayTopBoard(topBoard2);

  // print player information
  for (int i = 0; i < state1.players->size(); i++)
  {
    std::cout << state1.players->at(i)->getName() << " has ";
    std::cout << state1.players->at(i)->getGameHand()->size()
              << " cards and has a bid of ";
    std::cout << state1.players->at(i)->getBiddingFacility()->getBid() << ".\n";
  }
}
