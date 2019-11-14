#include "GameObservers.h"

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
        if (iter->id == o.id)
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
        if (iter->id == id)
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
    for (auto iter = observers->begin(); iter != observers->end(); iter++)
    {
        iter->update();
    }
}