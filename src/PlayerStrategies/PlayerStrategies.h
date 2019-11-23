#ifndef EIGHT_MINUTE_EMPIRE_PLAYERSTRATEGIES_H
#define EIGHT_MINUTE_EMPIRE_PLAYERSTRATEGIES_H

#include "GameState.h"
#include <string>

// Forward Declaration
class Cards;
class GameState;

// Abstract Class
class PlayerStrategies {
public:
    virtual std::string selectAction(GameState &state, int turnIndex, std::vector<Cards*> &topBoard, int currentTurn) = 0;
    virtual std::string displayCurrentStrategy() = 0;
};

// Greedy Computer - all actions lean towards building Cities and Destroying Opponents
class GreedyComputer : public PlayerStrategies {
public:
    virtual std::string selectAction(GameState &state, int turnIndex, std::vector<Cards*> &topBoard, int currentTurn);
    virtual std::string displayCurrentStrategy();
};

// Human Player - all actions are made through user interactions
class HumanPlayer : public PlayerStrategies {
public:
    virtual std::string selectAction(GameState &state, int turnIndex, std::vector<Cards*> &topBoard, int currentTurn);
    virtual std::string displayCurrentStrategy();
};

// Moderate Computer - all actions lean towards controlling the starting region
class ModerateComputer : public PlayerStrategies {
public:
    virtual std::string selectAction(GameState &state, int turnIndex, std::vector<Cards*> &topBoard, int currentTurn);
    virtual std::string displayCurrentStrategy();
};

// Utility Functions
bool validateChangeStrategy();
void changePlayerStrategy(std::vector<Player*> players);

#endif
