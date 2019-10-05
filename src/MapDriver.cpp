#include "Map.h"
#include <iostream>

int main() {
  // std::string regions[]
  // std::string continents[]
  // std::map<std::string, std::pair<int, int>> armies[]
  // std::vector<std::pair<std::string, bool>> connections[]
  // std::string startingRegion;

  std::string regions[2] = {"r1", "r2"};
  std::string continents[2] = {"nord", "sud"};

  std::map<std::string, std::pair<int, int>> r1_armies;
  std::map<std::string, std::pair<int, int>> r2_armies;
  r1_armies.insert(std::pair<std::string, std::pair<int, int>>(
      "red", std::pair<int, int>(10, 0)));
  r1_armies.insert(std::pair<std::string, std::pair<int, int>>(
      "blue", std::pair<int, int>(5, 1)));
  r2_armies.insert(std::pair<std::string, std::pair<int, int>>(
      "red", std::pair<int, int>(2, 1)));
  r2_armies.insert(std::pair<std::string, std::pair<int, int>>(
      "red", std::pair<int, int>(6, 0)));
  std::map<std::string, std::pair<int, int>> armies[] = {r1_armies, r2_armies};

  std::vector<std::pair<std::string, bool>> connections[std::size(regions)];
  std::vector<std::pair<std::string, bool>> r1_connections;
  //   r1_connections.insert(std::pair<std::string, bool>("r1", false));

  std::string startingRegion = "r1";
}