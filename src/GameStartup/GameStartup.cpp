#pragma once
#include "GameStartup.h"
#include "BiddingFacility.h"

int startGame(GameState &state)
{
  // Add three armies for each player to map
  addArmiesToStart(state);

  // if two players add 10 netural armies
  if (state.players->size() == 2)
  {
    addNeutralArmies(state);
  }

  // Begin the bidding phase
  int firstPlayer = BiddingFacility::biddingPhase(*(state.players), state.players->size());

  return firstPlayer;
}

void addArmiesToStart(GameState &state)
{
  // add three armies for each player to the starting region
  // set army count to 11
  for (int i = 0; i < state.players->size(); i++)
  {
    state.map->addArmy(*(state.map->getStart()), state.players->at(i)->getName());
    state.map->addArmy(*(state.map->getStart()), state.players->at(i)->getName());
    state.map->addArmy(*(state.map->getStart()), state.players->at(i)->getName());
    state.players->at(i)->setArmies(11);
  }
}

void addNeutralArmies(GameState &state)
{
  std::cout << "In two player games, you each take turns adding five neutral armies each to any region.\n";

  // loop over players ten times to add armies
  for (int i = 1; i < 11; i++)
  {
    std::string neutralRegion;
    auto regionNames = state.map->getRegionNames();
    bool validName = false;

    // print the map so player can reference it
    std::cout << "Printing map's current state:\n";
    state.map->printNodes();

    // loop to add the army
    while (!validName)
    {
      // use i % 2 to alternate between 0 and 1
      std::cout << state.players->at(i % 2)->getName() << ", where do you want to place the army? ";
      std::cin >> neutralRegion;

      // validate region name
      for (int j = 0; j < regionNames.size(); j++)
      {
        if (regionNames.at(j) == neutralRegion)
        {
          validName = true;
          break;
        }
      }

      // inform user of error
      if (!validName)
      {
        std::cout << "Invalid region name. Please try again.\n";
      }
    }

    // add the neutral army to the region
    state.map->addArmy(neutralRegion, "neutral");
  }

  std::cout << "Neutral armies added, we're almost ready to play!\n";
}