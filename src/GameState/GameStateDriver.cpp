#pragma once
#include "GameStateDriver.h"
#include "GameState.h"
void gameStateDriver() {
  std::cout << "==== Game Start Driver ====" << std::endl;
  std::cout << "For an example of an invalid map: assets/map2.map" << std::endl;
  std::cout << "For an example of a valid map: assets/map1.map" << std::endl;
  GameState state = GameState();
}
