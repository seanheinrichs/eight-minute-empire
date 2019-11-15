#include "GameObservers.h"

Observer::Observer(std::string uid) : id(new std::string(uid)) {}

Observer::~Observer()
{
    if (id)
    {
        delete id;
        id = NULL;
    }
}

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

void PhaseObserver::displayPhase()
{
    std::cout << "It is " << *currentPlayer << "'s turn: " << *action << std::endl;
}

Observable::Observable()
{
    observers = new std::vector<Observer>();
}

Observable::~Observable()
{
    if (observers)
    {
        delete observers;
        observers = NULL;
    }
}

bool Observable::attach(Observer o)
{
    for (auto iter = observers->begin(); iter != observers->end(); iter++)
    {
        if (iter->getId() == o.getId())
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
        if (iter->getId() == id)
        {
            // success: id found
            observers->erase(iter);
            return true;
        }
    }
    // failure: id not found
    return false;
};

void Observable::notify()
{
    // loop over each observer and call notify
    for (auto iter = observers->begin(); iter != observers->end(); iter++)
    {
        iter->update();
    }
}
