#pragma once
#include <iterator>
#include "Map.h"

// Inner Class Node Constructor and Deconstructor
Map::Node::Node(std::string regn, std::string cont, std::map<std::string, std::pair<int, int>> arm, std::vector<std::pair<std::string, bool>> conn)
{
    region = &regn;
    continent = &cont;
    armies = &arm;
    connectedTo = &conn;

    std::map<std::string, std::pair<int, int>>::iterator armyIterator = armies->begin();
    std::string tempOwner;
    int maxArmies = 0;
    for (armyIterator; armyIterator != arm.end(); armyIterator++)
    {
        if (armyIterator->second.first + armyIterator->second.second > maxArmies)
        {
            tempOwner = armyIterator->first;
            maxArmies = armyIterator->second.first + armyIterator->second.second;
        }
    }
    owner = &tempOwner;
}

Map::Node::~Node()
{
    delete region;
    delete continent;
    delete armies;
    delete owner;
    delete connectedTo;
}

// Node Class Methods
void Map::Node::updateOwner()
{
    std::map<std::string, std::pair<int, int>>::iterator armyIterator = armies->begin();
    std::string tempOwner;
    int maxArmies = 0;
    for (armyIterator; armyIterator != armies->end(); armyIterator++)
    {
        if (armyIterator->second.first + armyIterator->second.second > maxArmies)
        {
            tempOwner = armyIterator->first;
            maxArmies = armyIterator->second.first + armyIterator->second.second;
        }
    }
    owner = &tempOwner;
}

void Map::Node::addArmies(std::string player, std::pair<int, int> army)
{
    armies->at(player).first += army.first;
    if (armies->at(player).second == 0 && army.second == 1)
    {
        armies->at(player).second = 1;
    }
}
void Map::Node::removeArmies(std::string player, std::pair<int, int> army)
{
    armies->at(player).first -= army.first;
    if (armies->at(player).second == 1 && army.second == 1)
    {
        armies->at(player).second = 0;
    }
}

// Map Class Constructor and Deconstructor
Map::Map(std::string regions[], std::string continents[], std::map<std::string, std::pair<int, int>> armies[], std::vector<std::pair<std::string, bool>> connections[], std::string startingRegion)
{
    start = &startingRegion;
    std::string region, continent;

    for (int i = 0; i < regions->size(); i++)
    {
        region = regions[i];
        continent = continents[i];
        Map::Node node = Node(region, continent, armies[i], connections[i]);
        nodes->insert(std::pair<std::string, Map::Node>(region, node));
    }
}

Map::~Map()
{
    delete nodes;
    delete start;
}

// Map Class methods
void Map::updateOwnership()
{
    std::map<std::string, Map::Node>::iterator mapIterator = nodes->begin();
    for (mapIterator; mapIterator != nodes->end(); mapIterator++)
    {
        mapIterator->second.updateOwner();
    }
}

void Map::updateOwnership(std::string region)
{
    nodes->at(region).updateOwner();
}

void Map::addArmies(std::string region, std::string player, int armies)
{
    nodes->at(region).addArmies(player, std::pair<int, int>(armies, 0));
}

void Map::removeArmies(std::string player, std::string region, int armies)
{
    nodes->at(region).removeArmies(player, std::pair<int, int>(armies, 0));
}

void Map::addCity(std::string player, std::string region)
{
    nodes->at(region).addArmies(player, std::pair<int, int>(0, 1));
}

void Map::removeCity(std::string player, std::string region)
{
    nodes->at(region).removeArmies(player, std::pair<int, int>(0, 1));
}