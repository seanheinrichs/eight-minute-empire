#pragma once
#include <iostream>
#include <vector>
#include <map>

struct Node {
    // region name
    std::string region ="";

    // continent name
    std::string continent = "";

    // key is playername
    // playername for owner
    std::string owner = "";

    // value is array of two ints: armies, cities
    std::map<std::string, std::pair<int, bool>> armies = std::map<std::string, std::pair<int, bool>>();

    // array of regions it is connected to
    // first of pair is region name
    // second is true if water-crossing
    std::vector<std::pair<std::string, bool>> connectedTo = std::vector<std::pair<std::string, bool>>();
};

class Map
{
private:
    // connected graph of Nodes
    std::vector<Node> *nodes;
    // starting node
    std::string *start;

    // find a node's index
    int getNodeIndex(std::string regionName);

public:
    // constructors and destructors
    Map(std::vector<Node> inputNodes, std::string startRegion, std::vector<std::string> regions, std::vector<std::string> continents, std::vector<std::string> players);
    Map(Map const &m);
    ~Map();

    // print details of each node
    void printNodes();

    // add one army, return true on success
    bool addArmy(std::string regionName, std::string playerName);
    // move one army, return true on success
    bool moveArmy(std::string origin, std::string destination, std::string playerName, int totalMoves, bool isWaterMove);
    // add city, return true on scucess
    bool addCity(std::string regionName, std::string playerName);
    // destroy one army, return true on sucess
    bool destroyArmy(std::string regionName, std::string playerName);
    // determine possible regions to place army, return vector of regions
    std::vector<std::string> getArmyPlacementRegions(std::string playerName);
};