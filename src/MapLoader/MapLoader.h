#pragma once
#include <iostream>
#include <fstream>
#include "../Map/Map.h"

class MapLoader
{
private:
    // used in validation
    std::vector<std::string> *players;
    std::vector<std::string> *regions;
    std::vector<std::string> *continents;

    // creates a node struct with raw string from file
    Node generateNode(const std::vector<std::string> inputVector);
    // validates node to ensure there is consistency
    void validateMapData(const Node &n);
    // split string into vector of strings
    std::vector<std::string> split(const std::string &input, char delimiter);

public:
    MapLoader();

    // constructor which takes in validation data
    MapLoader(std::vector<std::string> playerVector,
              std::vector<std::string> regionVector,
              std::vector<std::string> continentVector);

    ~MapLoader();

    // called to create a map from a file
    Map generateMap(const std::string &fileName);
};
