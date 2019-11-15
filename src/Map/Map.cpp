#pragma once
#include <iterator>
#include <bits/stdc++.h>
#include <MapLoader.h>
#include "Map.h"

Map::Map(std::vector<Node> inputNodes, std::string startRegion, std::vector<std::string> regions, std::vector<std::string> continents, std::vector<std::string> players)
{
    bool connetionError;
    bool regionError;
    bool continentError;
    bool ownerError;
    std::vector<std::string>::iterator regionIter;
    std::vector<std::string>::iterator continentIter;
    std::vector<std::string>::iterator playerIter;
    std::map<std::string, std::pair<int, bool>>::iterator armyIter;

    auto nodeIter = inputNodes.begin();
    try
    {
        while (nodeIter != inputNodes.end())
        {
            regionIter = regions.begin();
            continentIter = continents.begin();
            playerIter = players.begin();
            connetionError = true;
            regionError = true;
            continentError = true;
            ownerError = true;

            if (nodeIter->connectedTo.size() > 0)
            {
                connetionError = false;
            }

            while (regionIter != regions.end())
            {
                if (*regionIter == nodeIter->region)
                {
                    regionError = false;
                    break;
                }
                regionIter++;
            }

            while (continentIter != continents.end())
            {
                if (*continentIter == nodeIter->continent)
                {
                    continentError = false;
                    break;
                }
                continentIter++;
            }

            while (playerIter != players.end())
            {
                if (*playerIter == nodeIter->owner || playerIter->empty())
                {
                    ownerError = false;
                    break;
                }
                playerIter++;
            }

            if (connetionError)
            {
                throw "Region has no connections.";
            }
            else if (regionError)
            {
                throw "Invalid region name";
            }
            else if (continentError)
            {
                throw "Invalid continent name.";
            }
            nodeIter++;
        }
        regionIter = regions.begin();
        regionError = true;
        while (regionIter != regions.end())
        {
            if (*regionIter == startRegion)
            {
                regionError = false;
                break;
            }
            regionIter++;
        }
        if (regionError)
        {
            throw "Invalid starting region name";
        }
    }

    catch (const char *msg)
    {
        std::cerr << msg << std::endl;
        exit(1);
    }

    nodes = new std::vector<Node>;
    *nodes = inputNodes;
    start = new std::string(startRegion);
    this->continents = new std::vector<std::string>(continents);
}

Map::~Map()
{
    if (start)
    {
        delete start;
        start = NULL;
    }
    if (nodes)
    {
        delete nodes;
        start = NULL;
    }
}

Map::Map(Map const &m)
{
    nodes = new std::vector<Node>();
    *nodes = *m.nodes;

    start = new std::string;
    *start = *m.start;
}

void Map::printNodes()
{
    std::vector<Node>::iterator nodeIter = nodes->begin();
    std::vector<std::pair<std::string, bool>>::iterator connectionIter;
    std::map<std::string, std::pair<int, bool>>::iterator armyIter;

    while (nodeIter != nodes->end())
    {
        connectionIter = nodeIter->connectedTo.begin();
        armyIter = nodeIter->armies.begin();
        std::cout << "Region: " << nodeIter->region << std::endl;
        std::cout << "Continent: " << nodeIter->continent << std::endl;

        if (nodeIter->owner.empty())
        {
            std::cout << "No owner yet." << std::endl;
        }
        else
        {
            std::cout << "Owner: " << nodeIter->owner << std::endl;
        }

        while (connectionIter != nodeIter->connectedTo.end())
        {
            std::cout << "Connected to " << connectionIter->first;
            if (connectionIter->second)
            {
                std::cout << " by sea." << std::endl;
            }
            else
            {
                std::cout << " by land." << std::endl;
            }
            connectionIter++;
        }

        while (armyIter != nodeIter->armies.end())
        {
            std::cout << armyIter->first << " has " << armyIter->second.first << " armies and ";
            if (armyIter->second.second)
            {
                std::cout << "1 city." << std::endl;
            }
            else
            {
                std::cout << "no cities." << std::endl;
            }
            armyIter++;
        }
        std::cout << std::endl;
        nodeIter++;
    }
}

int Map::getNodeIndex(std::string regionName)
{
    auto nodeIter = nodes->begin();
    int result = -1;
    int index = 0;
    while (nodeIter != nodes->end())
    {
        if (nodeIter->region == regionName)
        {
            result = index;
            break;
        }
        index++;
        nodeIter++;
    }
    return result;
}

std::string *Map::getStart() const
{
    return start;
}
std::map<std::string, std::vector<std::string>> Map::getRegionOwners() 
{
    std::map<std::string, std::vector<std::string>> regionOwners{};

    for (int i=0; i < nodes->size(); i++) {
        // if player is not in map, add them and the region they own
        if (regionOwners.find(nodes->at(i).owner) == regionOwners.end()) {
            std::vector<std::string> regions;
            regions.emplace_back(nodes->at(i).region);
            regionOwners.insert(std::make_pair(nodes->at(i).owner, regions));
        }
        // push region onto vector if owner already in map
        else {
            regionOwners.at(nodes->at(i).owner).emplace_back(nodes->at(i).region);
        }
    }
    return regionOwners;
}

std::vector<std::pair<std::string, std::string>> Map::getContinentOwners()
{
    auto rawData = getRegionOwners().begin();
    auto swapped = getRegionOwners();
    std::vector<std::pair<std::string, std::string>> continentOwners{};

    // Set up output vector of pairs fo continent and owner
    for (int i=0; i < continents->size(); i++) {
        continentOwners.emplace_back(std::make_pair(continents->at(i), "No owner"));
    }

    // takes regionOwners and swaps each region name with its continent name
    while (rawData != swapped.end()) {
        for (int j=0; j < swapped.at(rawData->first).size(); j++) {
            swapped.at(rawData->first).at(j) = nodes->at(getNodeIndex(swapped.at(rawData->first).at(j))).continent;
        }
        rawData++;
    }

    for (int i=0; i < continentOwners.size(); i++) {
        auto iter = swapped.begin();
        std::string owner = "No owner";
        int totalOwned = 0;
        while (iter != swapped.end()) {
            int count = std::count(iter->second.begin(), iter->second.end(), continentOwners.at(i).first);
            
            if (count > totalOwned) {
                continentOwners.at(i).second = iter->first;
                owner = iter->first;
                totalOwned = count;
            }
            else if (count == totalOwned) {
                continentOwners.at(i).second = "No owner";
            }
            iter++;
        }
    }
    return continentOwners;
}

int Map::getArmiesOnBoard(std::string playerName) {
    int numArmiesOnBoard = 0;
    std::vector<Node>::iterator nodeIter = nodes->begin();
    std::map<std::string, std::pair<int, bool>>::iterator armyIter;
    while (nodeIter != nodes->end()) {
        armyIter = nodeIter->armies.begin();
        while (armyIter != nodeIter->armies.end()) {
            if (armyIter->first == playerName) {
                numArmiesOnBoard += armyIter->second.first;
            }
            armyIter++;
        }
        nodeIter++;
    }
    return numArmiesOnBoard;
}

std::vector<std::string> Map::getRegionNames()
{
    std::vector<std::string> output;
    for (int i = 0; i < nodes->size(); i++)
    {
        output.emplace_back(nodes->at(i).region);
    }
    return output;
}

std::vector<std::string> Map::getRegionsToAddArmies(std::string playerName)
{
    std::vector<std::string> regionNames = {*start};

    auto nodeIter = nodes->begin();
    while (nodeIter != nodes->end())
    {
        // if player has a city on a region, add it to the list (don't add starting region twice)
        if (nodeIter->armies[playerName].second == true && nodeIter->region != *start)
        {
            regionNames.push_back(nodeIter->region);
        }
        nodeIter++;
    }

    return regionNames;
}

std::vector<std::string> Map::getRegionsToAddCities(std::string playerName)
{
    std::vector<std::string> regionNames;

    auto nodeIter = nodes->begin();
    while (nodeIter != nodes->end())
    {
        // if player has an army on a region, add it to the list (unless they already have a city there)
        if (nodeIter->armies[playerName].first > 0 && nodeIter->armies[playerName].second != true)
        {
            regionNames.push_back(nodeIter->region);
        }
        nodeIter++;
    }

    return regionNames;
}

std::vector<std::string> Map::getRegionsWithArmies(std::string playerName)
{
    std::vector<std::string> regionNames;

    auto nodeIter = nodes->begin();
    while (nodeIter != nodes->end())
    {
        // if player has an army on a region, add it to the list
        if (nodeIter->armies[playerName].first > 0)
        {
            regionNames.push_back(nodeIter->region);
        }
        nodeIter++;
    }

    return regionNames;
}

std::vector<std::string> Map::getRegionsConnectedByLand(std::string regionName)
{
    std::vector<std::string> regionNames;
    int nodeIndex = getNodeIndex(regionName);

    for (int i = 0; i < nodes->at(nodeIndex).connectedTo.size(); i++)
    {
        if (!nodes->at(nodeIndex).connectedTo.at(i).second)
            regionNames.push_back(nodes->at(nodeIndex).connectedTo.at(i).first);
    }

    return regionNames;
}

std::vector<std::string> Map::getRegionsConnectedByLandAndWater(std::string regionName)
{
    std::vector<std::string> regionNames;
    int nodeIndex = getNodeIndex(regionName);

    for (int i = 0; i < nodes->at(nodeIndex).connectedTo.size(); i++)
    {
        regionNames.push_back(nodes->at(nodeIndex).connectedTo.at(i).first);
    }

    return regionNames;
}

void Map::addArmy(std::string regionName, std::string playerName)
{
    int nodeIndex = getNodeIndex(regionName);
    nodes->at(nodeIndex).armies[playerName].first++;
    updateOwner(nodeIndex);
}

void Map::addCity(std::string regionName, std::string playerName)
{
    int nodeIndex = getNodeIndex(regionName);
    nodes->at(nodeIndex).armies[playerName].second = true;
    updateOwner(nodeIndex);
}

void Map::destroyArmy(std::string regionName, std::string playerName)
{
    int nodeIndex = getNodeIndex(regionName);
    nodes->at(nodeIndex).armies[playerName].first--;
    updateOwner(nodeIndex);
}

void Map::moveArmy(std::string origin, std::string destination, std::string playerName)
{
    int nodeIndex = getNodeIndex(origin);
    nodes->at(nodeIndex).armies[playerName].first--;
    updateOwner(nodeIndex);

    nodeIndex = getNodeIndex(destination);
    nodes->at(nodeIndex).armies[playerName].first++;
    updateOwner(nodeIndex);
}

void Map::updateOwner(int index)
{
    // Iterator of armies
    auto iter = nodes->at(index).armies.begin();

    // string for top player
    std::string ownerName = "";
    // string for top score
    int ownerScore = 0;
    // bool for tie
    bool isTie = false;

    // loop over al player armies
    while (iter != nodes->at(index).armies.end())
    {
        // calculate score for armies
        int score = iter->second.first;

        // add a point for a cities
        if (iter->second.second)
        {
            score++;
        }

        if (score == ownerScore)
        {
            isTie = true;
        }
        else if (score > ownerScore)
        {
            ownerName = iter->first;
            ownerScore = score;
            isTie = false;
        }
        iter++;
    }

    // if it's a tie, no owner
    if (isTie)
    {
        nodes->at(index).owner = "";
    }
    // set owner if no tie
    else
    {
        nodes->at(index).owner = ownerName;
    }
}

Singleton::~Singleton() {
    if (map) {
        delete map;
        map = nullptr;
    }
    if (_instance) {
        delete _instance;
        _instance = nullptr;
    }
}

Singleton* Singleton::_instance = nullptr;

Singleton* Singleton::instance() {
    if (!_instance) {
        _instance = new Singleton();
    }
    return _instance;
}

Singleton::Singleton() {
    // generate map
    bool validMap = false;

    // will run until a valid map is provided
    while (!validMap) {
        try {
            // get file location
            std::string fileLocation;
            std::cout << "Enter map file location: ";
            std::cin >> fileLocation;

            // load map
            MapLoader loader;
            map = new Map(loader.generateMap(fileLocation));
            validMap = true;
        }

        catch (const char *msg) {
            std::cout << "Error: Invalid map file. ";
            std::cout << msg << std::endl;
        }
    }
}

void Singleton::resetInstance() {
    if (_instance) {
        delete _instance;
        _instance = nullptr;
    }
}
