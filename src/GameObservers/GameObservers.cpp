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

void StatisticsObserver::update(const GameState &state)
{
    // Header
    std::cout << "== Game Standings ==" << std::endl;

    // Display player bar graphs
    std::cout << "Mike:" << std::endl;
    std::cout << "Points     |"
              << "000000" << std::endl;
    std::cout << "Regions    |"
              << "000" << std::endl;
    std::cout << "Continents |"
              << "00000" << std::endl;
    std::cout << "Armies     |"
              << "00000000" << std::endl;
    std::cout << "Cities     |"
              << "0" << std::endl;

    std::cout << std::endl;
    // Display region and continent owners
    std::cout << "Region Owners:" << std::endl;
    std::cout << "Canada | "
              << "Mike" << std::endl;
    std::cout << "USA    | "
              << "Michael" << std::endl;
    std::cout << "UK     | "
              << "Mikey" << std::endl;

    // Display region and continent owners
    std::cout << "Continent Owners:" << std::endl;
    std::cout << "North America | "
              << "Mike" << std::endl;
    std::cout << "Europe        | "
              << "Michael" << std::endl;
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
