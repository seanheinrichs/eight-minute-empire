#pragma once
#include <iostream>
#include <vector>
class Observable
{
private:
    std::vector<Observer> *observers;

public:
    Observable();
    ~Observable();

    // pushes new observer onto vector
    bool attach(Observer o);
    // erases observer by id from vector
    bool detach(std::string id);
    // calls update on all observers to notify of change
    void notify();
};

class Observer
{
    // Observable::notify needs access to update()
    friend void Observable::notify();
    // Observable::detach needs access to id
    friend bool Observable::detach(std::string id);
    // Observable::attach needs access to the id to check for uniqueness
    friend bool Observable::attach(Observer o);

private:
    // id to identify the observer
    std::string *id;
    // update method
    void update();

public:
    Observer(std::string uid);
    ~Observer();
};

class PhaseObserver : Observer
{
private:
    std::string *currentPlayer;
    std::string *action;

    void displayPhase();

public:
    PhaseObserver();
    ~PhaseObserver();
};

class StatisticsObserver : Observer
{
private:
    void drawGraph();

public:
    StatisticsObserver();
    ~StatisticsObserver();
};