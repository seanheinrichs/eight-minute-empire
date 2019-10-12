#pragma once
#include "MapLoader.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

std::vector<std::string> MapLoader::split(const std::string &input, char delimiter)
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

void MapLoader::generateMap(const std::string &fileName)
{
    // processing variables
    std::ifstream inputFile(fileName);
    std::string line;
    std::vector<std::string> rawData;

    // map generation variables
    std::vector<std::string> regions;
    std::vector<std::string> continents;
    std::vector<std::string> players;
    std::string start;
    std::vector<Node> nodes;

    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            rawData = split(line, ',');

            if (rawData.at(0) == "REGIONS")
            {
                // TODO: Generate regions
            }
            else if (rawData.at(0) == "CONTINENTS")
            {
                // TODO: Generate continents
            }
            else if (rawData.at(0) == "PLAYERS")
            {
                // TODO: Generate players
            }
            else if (rawData.at(0) == "START")
            {
                // TODO: Generate start
            }
            else if (rawData.at(0) == "NODE")
            {
                // TODO: Generate Node
            }
        }
        inputFile.close();
    }
}