#include <iterator>
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
            else if (ownerError)
            {
                throw "Invalid owner name.";
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
}

bool Map::addArmy(std::string regionName, std::string playerName)
{
    int nodeIndex = getNodeIndex(regionName);
    if (nodeIndex == -1)
    {
        return false;
    }

    nodes->at(nodeIndex).armies[playerName].first++;
    return true;
}