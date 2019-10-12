#pragma once
#include <iostream>
#include <fstream>
#include "Map.h"

class MapLoader
{
private:
    // TODO: add variables for players, regions, continents

    // creates a node struct with raw string from file
    static Node generateNode(const std::vector<std::string> inputVector);
    // validates node to ensure there is consistency
    static bool validateMapData(const Node &n);
    // split string into vector of strings
    static std::vector<std::string> split(const std::string &input, char delimiter);

public:
    // called to create a map from a file
    static Map generateMap(const std::string &fileName);
};
