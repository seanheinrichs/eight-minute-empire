#pragma once
#include <iostream>
#include <vector>
#include "GameState.h"

// Abstract class for Observers
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
    virtual void update(const GameState &state, std::string playerName, std::string playerAction) = 0;
};

// Provides information on current phase
class PhaseObserver : public Observer
{
private:
    std::string *currentPlayer;
    std::string *action;

public:
    PhaseObserver(std::string uid);
    ~PhaseObserver();

    // Updates instance variables, displays phase
    virtual void update(const GameState &state, std::string playerName, std::string playerAction);
};

class StatisticsObserver : public Observer
{
private:
    // makes a graph row
    std::string graphRow(std::string header, int width, int value);

public:
    StatisticsObserver(std::string uid);
    ~StatisticsObserver();

    // Updates data, draws graph
    virtual void update(const GameState &state, std::string playerName, std::string playerAction);
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
    void notify(const GameState &state, std::string playerName, std::string playerAction);
};
