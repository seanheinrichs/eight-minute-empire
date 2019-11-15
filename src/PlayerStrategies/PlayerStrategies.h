#ifndef EIGHT_MINUTE_EMPIRE_PLAYERSTRATEGIES_H
#define EIGHT_MINUTE_EMPIRE_PLAYERSTRATEGIES_H

class PlayerStrategies {
public:
    virtual void selectAction() = 0;
};

class GreedyComputer : public PlayerStrategies {
public:
    virtual void selectAction();
};

class HumanPlayer : public PlayerStrategies {
public:
    virtual void selectAction();
};

class ModerateComputer : public PlayerStrategies {
public:
    virtual void selectAction();
};

#endif
