#pragma once
#include "MapLoader.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

MapLoader::MapLoader()
{
    players = nullptr;
    regions = nullptr;
    continents = nullptr;
}

MapLoader::MapLoader(
    std::vector<std::string> playerVector,
    std::vector<std::string> regionVector,
    std::vector<std::string> continentVector)
{
    players = new std::vector<std::string>(playerVector);
    regions = new std::vector<std::string>(regionVector);
    continents = new std::vector<std::string>(continentVector);
}

MapLoader::~MapLoader()
{
    if (players)
    {
        delete players;
        players = NULL;
    }
    if (regions)
    {
        delete regions;
        regions = NULL;
    }
    if (continents)
    {
        delete continents;
        continents = NULL;
    }
}

std::vector<std::string>
MapLoader::split(const std::string &input, char delimiter)
{
    std::vector<std::string> output;
    std::stringstream stream(input);
    std::string chunk;
    while (std::getline(stream, chunk, delimiter))
    {
        output.emplace_back(chunk);
    }
    return output;
}
Node MapLoader::generateNode(const std::vector<std::string> inputVector)
{
    // TODO: Add size, it must always be five or this will crash
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

    for (int i = 0; i < rawArmies.size(); i++)
    {
        rawArmy = split(rawArmies.at(i), ',');
        {
            playerName = rawArmy.at(0);
            std::stringstream(rawArmy.at(1)) >> totalArmies;
            if (rawArmy.at(2) == "true")
            {
                hasCity = true;
            }
            else if (rawArmy.at(2) == "false")
            {
                hasCity = false;
            }
            else
            {
                // TODO: throw error on invalid value
            }
            armies.insert(std::make_pair(playerName, std::make_pair(totalArmies, hasCity)));
        }
    }
    n.armies = armies;

    // add connections to Node
    std::vector<std::pair<std::string, bool>> connectedTo;
    auto rawConnections = split(inputVector.at(4), '/');
    std::vector<std::string> rawConnection;
    std::string region;
    bool waterConnection;

    for (int i = 0; i < rawConnections.size(); i++)
    {

        rawConnection = split(rawConnections.at(i), ',');
        region = rawConnection.at(0);
        if (rawConnection.at(1) == "true")
        {
            waterConnection = true;
        }
        else if (rawConnection.at(1) == "false")
        {
            waterConnection = false;
        }
        else
        {
            // TODO: throw error on invalid value
        }
        connectedTo.emplace_back(std::make_pair(region, waterConnection));
    }
    n.connectedTo = connectedTo;

    return n;
}

Map MapLoader::generateMap(const std::string &fileName)
{
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

    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            rawData = split(line, '|');

            if (rawData.front() == "REGIONS")
            {
                rawData = split(rawData.at(1), ';');
                for (int i = 0; i < rawData.size(); i++)
                {
                    regionData.emplace_back(rawData.at(i));
                }
            }
            else if (rawData.front() == "CONTINENTS")
            {
                rawData = split(rawData.at(1), ';');
                for (int i = 0; i < rawData.size(); i++)
                {
                    continentData.emplace_back(rawData.at(i));
                }
            }
            else if (rawData.front() == "PLAYERS")
            {
                rawData = split(rawData.at(1), ';');
                for (int i = 0; i < rawData.size(); i++)
                {
                    playerData.emplace_back(rawData.at(i));
                }
            }
            else if (rawData.front() == "START")
            {
                start = rawData.at(1);
            }
            else if (rawData.front() == "NODE")
            {
                rawData = split(rawData.at(1), ';');
                n = generateNode(rawData);
                nodes.emplace_back(n);
            }
        }
        inputFile.close();

        // if MapLoader doesn't have mapdata, add it
        if (!players)
        {
            players = new std::vector<std::string>(playerData);
        }
        if (!regions)
        {
            regions = new std::vector<std::string>(regionData);
        }
        if (!continents)
        {
            continents = new std::vector<std::string>(continentData);
        }

        return Map(nodes, start, regionData, continentData, playerData);
    }
}
