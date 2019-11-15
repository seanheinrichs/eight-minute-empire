#pragma once
#include <iostream>
#include <vector>
#include "GameState.h"

class Observer
{
private:
    // id to identify the observer
    std::string *id;

public:
    // uniqueness of uid is enforced
    Observer(std::string uid);
    ~Observer();

    // getter for the unique id
    std::string getId();

    // update the observer with new data
    virtual void update(const GameState &state) = 0;
};

class PhaseObserver : public Observer
{
private:
    std::string *currentPlayer;
    std::string *action;

    void displayPhase();

public:
    PhaseObserver(std::string uid);
    ~PhaseObserver();

    virtual void update(const GameState &state);
};

class StatisticsObserver : Observer
{
private:
    void drawGraph();

public:
    StatisticsObserver();
    ~StatisticsObserver();
};

class Observable
{
private:
    std::vector<Observer *> *observers;

public:
    Observable();
    ~Observable();

    // pushes new observer onto vector
    bool attach(Observer *o);
    // erases observer by id from vector
    bool detach(std::string id);
    // calls update on all observers to notify of change
    void notify(const GameState &state);
};
