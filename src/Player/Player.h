#ifndef EIGHT_MINUTE_EMPIRE_PLAYER_H
#define EIGHT_MINUTE_EMPIRE_PLAYER_H

class Player {

private:
    // TODO: Add collection of regions / countries - Requires Part 1 & 2 to be complete
    // TODO: Add Player Hand of Game Cards - Requires Part 4 to be complete
    // TODO: Add Bidding Facility - Requires Part 5 to be complete

    int* coins;
    int* armies;
    int* cities;

public:
    // Constructors
    Player();                       // Default should never be called but will be set for a two player game
    Player(int numOfPlayers);       // The number of coins is dependent on the number of players:

    // Gameplay Methods
    void payCoin();                 // TODO: Implement to reflect cost of actual card
    void placeNewArmies();          // TODO: Require Map Implementation
    void moveArmies();              // TODO: Require Map Implementation
    void moveOverLand();            // TODO: Require Map Implementation
    void buildCity();               // TODO: Require Map Implementation
    void destroyArmy();             // TODO: Require Map Implementation

    // Accessors
    int* getCoins() const;
    int* getArmies() const;
    int* getCities() const;

    // Mutators
    void setCoins(int coins);
    void setArmies(int armies);
    void setCities(int cities);
};

#endif
