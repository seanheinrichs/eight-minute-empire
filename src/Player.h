#ifndef EIGHT_MINUTE_EMPIRE_PLAYER_H
#define EIGHT_MINUTE_EMPIRE_PLAYER_H

#include <string>
#include "BiddingFacility.h"

// TODO: Get rid of the this forward declaration. Current it's only to make the compiler happy.
class BiddingFacility;

class Player {

private:
    // TODO: Add collection of regions / countries - Requires Part 1 & 2 to be complete
    // TODO: Add Player Hand of Game Cards - Requires Part 4 to be complete

    int* coins;
    int* armies;
    int* cities;
    int* dateOfBirth;
    std::string* name;
    BiddingFacility* biddingFacility;

public:

    // Constructors
    Player(std::string name, int dateOfBirth);                       // Default should never be called but will be set for a two player game
    Player(std::string name, int numOfPlayers, int dateOfBirth);     // The number of coins is dependent on the number of players:

    // Gameplay Methods
    void payCoin(int cost);         // TODO: Implement to reflect cost of actual card
    void placeNewArmies();          // TODO: Require Map Implementation
    void moveArmies();              // TODO: Require Map Implementation
    void moveOverLand();            // TODO: Require Map Implementation
    void buildCity();               // TODO: Require Map Implementation
    void destroyArmy();             // TODO: Require Map Implementation

    // Accessors
    int* getCoins() const;
    int* getArmies() const;
    int* getCities() const;
    int* getDateOfBirth() const;
    std::string* getName() const;
    BiddingFacility* getBiddingFacility() const;

    // Mutators
    void setCoins(int coins);
    void setArmies(int armies);
    void setCities(int cities);
    void setDateOfBirth(int dateOfBirth);
    void setName(std::string name);

};

#endif