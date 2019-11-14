#pragma once
#include <iostream>
#include <vector>
class Observable
{
private:
    std::vector<Observer *> *observers;

public:
    void attach(Observer o);
    void detach(Observer o);
    void notify();
};

class Observer
{
    friend void Observable::notify();

private:
    void update();
};

class PhaseObserver : Observer
{
private:
    std::string currentPlayer;
    std::string action;
};

class StatisticsObserver : Observer
{
private:
    void drawGraph();
};