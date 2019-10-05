#pragma once
#include <iostream>
#include <map>
#include <utility>
#include <vector>

class Map {
private:
  class Node {
    // region name
    std::string *region;
    // continent name
    std::string *continent;
    // key is playername
    // value is array of two ints: armies, cities
    std::map<std::string, std::pair<int, int>> *armies;
    // playername for owner
    std::string *owner;
    // array of regions it is connected to
    // first of pair is region name
    // second is true if water-crossing
    std::vector<std::pair<std::string, bool>> *connectedTo;

  public:
    Node(std::string regn, std::string cont,
         std::map<std::string, std::pair<int, int>> arm,
         std::vector<std::pair<std::string, bool>> conn);
    ~Node();
    // recalculates ownership of a region
    void updateOwner();
    // adds armies or cities to a region
    void addArmies(std::string player, std::pair<int, int> army);
    // removes armies or cities from a region
    void removeArmies(std::string player, std::pair<int, int> army);
  };

  // connected graph of Nodes
  std::map<std::string, Node> *nodes;
  // starting node
  std::string *start;

public:
  // struct containing data needed to instantiate Map
  struct MapInfo {
    std::string *regions;
    std::string *continents;
    std::map<std::string, std::pair<int, int>> *armies;
    std::vector<std::pair<std::string, bool>> *connections;
    int totalRegions;
    std::string startingRegion;
  };

  Map(MapInfo const &MapInfo);
  ~Map();

  // calculate and set the owner for all nodes
  void updateOwnership();
  // calculate and set the owner for all nodes
  void updateOwnership(std::string region);
  // add army to Node
  void addArmies(std::string player, std::string region, int armies);
  // remove armies from Node
  void removeArmies(std::string player, std::string region, int armies);
  // add cities to Node
  void addCity(std::string player, std::string region);
  // remove cities from Node
  void removeCity(std::string player, std::string region);
};