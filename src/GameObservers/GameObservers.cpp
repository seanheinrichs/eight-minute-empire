#include "GameObservers.h"

// Observer definitions
Observer::Observer(std::string uid) : id(new std::string(uid)) {}

Observer::~Observer()
{
    if (id)
    {
        delete id;
        id = NULL;
    }
}

std::string Observer::getId()
{
    return *id;
}

// PhaseObserver definitions
PhaseObserver::PhaseObserver(std::string uid) : Observer::Observer(uid)
{
    currentPlayer = new std::string();
    action = new std::string();
}

PhaseObserver::~PhaseObserver()
{
    if (currentPlayer)
    {
        delete currentPlayer;
        currentPlayer = NULL;
    }

    if (action)
    {
        delete action;
        action = NULL;
    }
}

void PhaseObserver::update(const GameState &state)
{
    std::cout << "It is " << *currentPlayer << "'s turn: " << *action << std::endl;
}

// StatisticsObserver definitions
StatisticsObserver::StatisticsObserver(std::string uid) : Observer::Observer(uid){};

std::string StatisticsObserver::graphRow(std::string header, int width, int value)
{
    // Start with the header of the row
    std::string row = header;

    // Add enough spaces so that all rows are equal length
    for (int i = 0; i < (width - header.length()); i++)
    {
        row += " ";
    }

    // Add a symbol to display the end of the row
    row += "|";

    // Build the bar in the bar graph
    for (int i = 0; i < value; i++)
    {
        row += "0";
    }

    // Return the row with a newline character on the end
    return row + "\n";
}

void StatisticsObserver::update(const GameState &state)
{
    auto regionOwners = state.map->getRegionOwners();
    auto continentOwners = state.map->getContinentOwners();

    // Header
    std::cout << "== Game Standings ==" << std::endl;

    // Display graph of players
    for (auto i = 0; i < state.players->size(); i++)
    {
        // get number of continents owned
        int ownedRegions = 0;
        if (regionOwners.find(state.players->at(i)->getName()) != regionOwners.end())
        {
            ownedRegions = regionOwners.find(state.players->at(i)->getName())->second.size();
        }

        // get number of continents owned
        int ownedContinents = 0;
        for (int j = 0; j < continentOwners.size(); j++)
        {
            if (continentOwners.at(j).second == state.players->at(i)->getName())
            {
                ownedContinents++;
            }
        }

        // Print the graph rows
        std::cout << state.players->at(i)->getName() << ":\n";
        std::cout << graphRow("Points", 11, state.players->at(i)->getPoints());
        std::cout << graphRow("Regions", 11, ownedRegions);
        std::cout << graphRow("Continents", 11, ownedContinents);
        std::cout << graphRow("Armies", 11, (14 - state.players->at(i)->getArmies()));
        std::cout << graphRow("Cities", 11, (3 - state.players->at(i)->getCities()));
        std::cout << std::endl;
    }

    // Display region owners
    std::cout << "Region Owners:" << std::endl;
    for (auto regionIter = regionOwners.begin(); regionIter != regionOwners.end(); regionIter++)
    {
        // display the player's name
        std::cout << regionIter->first << ": ";

        // display each continent they own separated by comma, up to second last
        for (int j = 0; j < regionIter->second.size() - 1; j++)
        {
            std::cout << regionIter->second.at(j) << ", ";
        }
        // display last one with with newline at end
        std::cout << regionIter->second.at(regionIter->second.size() - 1) << std::endl;
    }

    // Display continent owners
    std::cout << "\nContinent Owners:" << std::endl;
    for (auto continentIter = continentOwners.begin(); continentIter != continentOwners.end(); continentIter++)
    {
        // continent's name followed by the owner's name
        std::cout << continentIter->first << ": " << continentIter->second << std::endl;
    }
}

// Observable definitions
Observable::Observable()
{
    observers = new std::vector<Observer *>();
}

Observable::~Observable()
{
    if (observers)
    {
        delete observers;
        observers = NULL;
    }
}

bool Observable::attach(Observer *o)
{
    for (auto iter = observers->begin(); iter != observers->end(); iter++)
    {
        if ((*iter)->getId() == o->getId())
        {
            // failure: id not unique
            return false;
        }
    }
    // success: id is unique
    observers->emplace_back(o);
    return true;
};

bool Observable::detach(std::string id)
{
    for (auto iter = observers->begin(); iter != observers->end(); iter++)
    {
        if ((*iter)->getId() == id)
        {
            // success: id found
            observers->erase(iter);
            return true;
        }
    }
    // failure: id not found
    return false;
};

void Observable::notify(const GameState &state)
{
    // loop over each observer and call notify
    for (auto iter = observers->begin(); iter != observers->end(); iter++)
    {
        (*iter)->update(state);
    }
}
