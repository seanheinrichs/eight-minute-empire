#pragma once
#include "MapLoader.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

MapLoader::MapLoader() {
  players = nullptr;
  regions = nullptr;
  continents = nullptr;
}

MapLoader::MapLoader(std::vector<std::string> playerVector,
                     std::vector<std::string> regionVector,
                     std::vector<std::string> continentVector) {
  players = new std::vector<std::string>(playerVector);
  regions = new std::vector<std::string>(regionVector);
  continents = new std::vector<std::string>(continentVector);
}

MapLoader::~MapLoader() {
  if (players) {
    delete players;
    players = NULL;
  }
  if (regions) {
    delete regions;
    regions = NULL;
  }
  if (continents) {
    delete continents;
    continents = NULL;
  }
}

std::vector<std::string> MapLoader::split(const std::string &input,
                                          char delimiter) {
  std::vector<std::string> output;
  std::stringstream stream(input);
  std::string chunk;
  while (std::getline(stream, chunk, delimiter)) {
    output.emplace_back(chunk);
  }
  return output;
}
Node MapLoader::generateNode(const std::vector<std::string> inputVector) {
  if (inputVector.size() != 5) {
    throw "Malformed line for NODE in file. Ensure you have 4 semi-colons.";
  }
  Node n{};

  // add strings to Node
  n.region = inputVector.at(0);
  n.continent = inputVector.at(1);
  n.owner = inputVector.at(2);

  // add armies to Node
  std::map<std::string, std::pair<int, bool>> armies;
  std::vector<std::string> rawArmies = split(inputVector.at(3), '/');
  std::vector<std::string> rawArmy;
  std::string playerName;
  int totalArmies;
  bool hasCity;

  for (int i = 0; i < rawArmies.size(); i++) {
    rawArmy = split(rawArmies.at(i), ',');
    {
      playerName = rawArmy.at(0);
      std::stringstream(rawArmy.at(1)) >> totalArmies;
      if (rawArmy.at(2) == "true") {
        hasCity = true;
      } else if (rawArmy.at(2) == "false") {
        hasCity = false;
      } else {
        throw "Ensure each city value is set to true or false in file.";
      }
      armies.insert(
          std::make_pair(playerName, std::make_pair(totalArmies, hasCity)));
    }
  }
  n.armies = armies;

  // add connections to Node
  std::vector<std::pair<std::string, bool>> connectedTo;
  auto rawConnections = split(inputVector.at(4), '/');
  std::vector<std::string> rawConnection;
  std::string region;
  bool waterConnection;

  for (int i = 0; i < rawConnections.size(); i++) {

    rawConnection = split(rawConnections.at(i), ',');
    region = rawConnection.at(0);
    if (rawConnection.at(1) == "true") {
      waterConnection = true;
    } else if (rawConnection.at(1) == "false") {
      waterConnection = false;
    } else {
      throw "Ensure each water/land transition is set to true or false in "
            "file.";
    }
    connectedTo.emplace_back(std::make_pair(region, waterConnection));
  }
  n.connectedTo = connectedTo;

  return n;
}

Map MapLoader::generateMap(const std::string &fileName) {
  // processing variables
  std::ifstream inputFile(fileName);
  std::string line;
  std::vector<std::string> rawData;
  Node n;

  // map generation variables
  std::vector<std::string> regionData;
  std::vector<std::string> continentData;
  std::vector<std::string> playerData;
  std::string start;
  std::vector<Node> nodes;

  if (inputFile.is_open()) {
    // process map file line by line
    while (getline(inputFile, line)) {
      rawData = split(line, '|');

      // get list of continents
      if (rawData.front() == "REGIONS") {
        rawData = split(rawData.at(1), ';');
        for (int i = 0; i < rawData.size(); i++) {
          regionData.emplace_back(rawData.at(i));
        }
      }

      // get list of continents
      else if (rawData.front() == "CONTINENTS") {
        rawData = split(rawData.at(1), ';');
        for (int i = 0; i < rawData.size(); i++) {
          continentData.emplace_back(rawData.at(i));
        }
      }

      // get list of players
      else if (rawData.front() == "PLAYERS") {
        rawData = split(rawData.at(1), ';');
        for (int i = 0; i < rawData.size(); i++) {
          playerData.emplace_back(rawData.at(i));
        }
      }

      // get starting region name
      else if (rawData.front() == "START") {
        start = rawData.at(1);
      }

      // get new node
      else if (rawData.front() == "NODE") {
        rawData = split(rawData.at(1), ';');
        n = generateNode(rawData);
        nodes.emplace_back(n);
      }
    }
    inputFile.close();

    // validate that there are regions, continents, and players
    if (regionData.empty()) {
      throw "No REGIONS in file.";
    }
    if (continentData.empty()) {
      throw "No CONTINENTS line in file.";
    }

    // if MapLoader doesn't have mapdata, add it
    if (!players) {
      players = new std::vector<std::string>(playerData);
    }
    if (!regions) {
      regions = new std::vector<std::string>(regionData);
    }
    if (!continents) {
      continents = new std::vector<std::string>(continentData);
    }

    // validate nodes
    for (int i = 0; i < nodes.size(); i++) {
      validateMapData(nodes.at(i));
    }

    // validate that there are no orphaned regions
    if (!validateGraph(nodes, start)) {
      throw "Graph not fully connected.";
    }

    return Map(nodes, start, regionData, continentData, playerData);
  } else {
    throw "File not found.";
  }
}

void MapLoader::validateMapData(const Node &n) {
  // validate region name
  if (!(find(regions->begin(), regions->end(), n.region) != regions->end())) {
    throw "Invalid region name in map file.";
  }

  // validate continent name
  if (!(find(continents->begin(), continents->end(), n.continent) !=
        continents->end())) {
    throw "Invalid continent name in map file.";
  }

  // validate region names in graph edges
  for (int i = 0; i < n.connectedTo.size(); i++) {
    if (!(find(regions->begin(), regions->end(), n.connectedTo.at(i).first) !=
          regions->end())) {
      throw "Invalid region name in region connections in map file.";
    }
  }

  // validate player names in armies
  auto armyIter = n.armies.begin();
  for (armyIter; armyIter != n.armies.end(); armyIter++) {
    if (!(find(players->begin(), players->end(), armyIter->first) !=
          players->end())) {
      throw "Invalid player name for army in map file.";
    }
  }
}

bool MapLoader::validateGraph(std::vector<Node> nodes, std::string startName) {
  // visited will be mutated by recursive calls of walkGraph
  std::vector<std::string> visited{};
  // initialize start node
  Node start{};

  // get the starting node
  for (int i = 0; i < nodes.size(); i++) {
    if (nodes[i].region == startName) {
      start = nodes[i];
      break;
    }
  }
  // walk graph to build vector visited
  walkGraph(start, nodes, visited);

  // the number of visited regions should equal total number of regions
  return nodes.size() == visited.size();
}

void MapLoader::walkGraph(Node node, std::vector<Node> nodes,
                          std::vector<std::string> &visited) {
  // mark region as visited
  visited.emplace_back(node.region);

  // attempt to visit all connected regions
  for (int i = 0; i < node.connectedTo.size(); i++) {

    // only visit regions that are not in visited
    if (!vectorContains(visited, node.connectedTo[i].first)) {
      // find the connected region's Node struct
      for (int j = 0; j < nodes.size(); j++) {
        if (nodes[j].region == node.connectedTo[i].first) {
          // walk node
          walkGraph(nodes[j], nodes, visited);
          break;
        }
      }
    }
  }
}

bool MapLoader::vectorContains(std::vector<std::string> inputVector,
                               std::string value) {
  for (int i = 0; i < inputVector.size(); i++) {
    if (inputVector[i] == value) {
      return true;
    }
  }
  return false;
}