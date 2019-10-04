#pragma once
#include <iostream>
#include <map>
#include <utility>
#include "Map.h"

// Inner Class Node Constructor and Deconstructor
Map::Node::Node(std::string regn, std::string cont, std::map<std::string, std::pair<int, int>> arm, std::vector<std::pair<std::string, bool>> conn)
{
    region = &regn;
    continent = &cont;
    armies = &arm;
    connectedTo = &conn;

    // set the thing below to arm.begin's key
    // iterate over it and switch it up as it gets larger
    std::string *owner;
}

Map::Node::~Node()
{
    std::cout << "yup" << std::endl;
}

// Map Class Constructor and Deconstructor
Map::Map(std::string regions[], std::string continents[], std::map<std::string, std::pair<int, int>> armies[], std::pair<std::string, bool> connections[], std::string startingRegion)
{
    for (int i = 0; i < regions->size(); i++)
    {
    }
}
Map::~Map()
{
    std::cout << "yup" << std::endl;
}

// Map Class methods
// Node Map::getNode(std::string region)
// {
//     std::cout << "yup" << std::endl;
// }

void Map::updateOwnership()
{
    std::cout << "yup" << std::endl;
}

void Map::updateOwnership(std::string region)
{
    std::cout << "yup" << std::endl;
}

void Map::addArmies(std::string player, std::string region, int armies)
{
    std::cout << "yup" << std::endl;
}

void Map::removeArmies(std::string player, std::string region, int armies)
{
    std::cout << "yup" << std::endl;
}

void Map::addCity(std::string player, std::string region)
{
    std::cout << "yup" << std::endl;
}

void Map::removeCity(std::string player, std::string region)
{
    std::cout << "yup" << std::endl;
}