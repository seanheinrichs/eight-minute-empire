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
            rawData = split(line, '|');

            if (rawData.front() == "REGIONS")
            {
                rawData = split(rawData.at(1), ';');
                for (int i = 0; i < rawData.size(); i++)
                {
                    regions.emplace_back(rawData.at(i));
                }
            }
            else if (rawData.front() == "CONTINENTS")
            {
                rawData = split(rawData.at(1), ';');
                for (int i = 0; i < rawData.size(); i++)
                {
                    continents.emplace_back(rawData.at(i));
                }
            }
            else if (rawData.front() == "PLAYERS")
            {
                rawData = split(rawData.at(1), ';');
                for (int i = 0; i < rawData.size(); i++)
                {
                    players.emplace_back(rawData.at(i));
                }
            }
            else if (rawData.front() == "START")
            {
                start = rawData.at(1);
            }
            else if (rawData.front() == "NODE")
            {
                // TODO: Generate Node
            }
        }
        inputFile.close();
    }
}