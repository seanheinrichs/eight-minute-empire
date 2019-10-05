#include "Map.h"
#include <iostream>

int main()
{
    // std::string regions[]
    std::string regions[2] = {"r1", "r2"};

    // std::string continents[]
    std::string continents[2] = {"nord", "sud"};

    // std::map<std::string, std::pair<int, int>> armies[]
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

    // std::vector<std::pair<std::string, bool>> connections[]
    std::vector<std::pair<std::string, bool>> connections[std::size(regions)];
    std::vector<std::pair<std::string, bool>> r1_connections;
    std::vector<std::pair<std::string, bool>> r2_connections;
    r1_connections.emplace_back(std::pair<std::string, bool>("r2", true));
    r2_connections.emplace_back(std::pair<std::string, bool>("r1", true));
    connections[0] = r1_connections;
    connections[1] = r2_connections;

    // std::string startingRegion;
    std::string startingRegion = "r1";

    Map::MapInfo mapData = Map::MapInfo{};
    mapData.armies = armies;
    mapData.connections = connections;
    mapData.continents = continents;
    mapData.startingRegion = startingRegion;
    mapData.totalRegions = std::size(regions);

    Map myMap(mapData);

    myMap.printNodes();
}