#ifndef EIGHT_MINUTE_EMPIRE_PLAYER_H
#define EIGHT_MINUTE_EMPIRE_PLAYER_H

#include <string>
#include <vector>
#include "../BiddingFacility/BiddingFacility.h"
#include "../Map/Map.h"
#include "../Cards/Cards.h"

// Forward Declaration
class BiddingFacility;

class Player {

private:
    int* coins;
    int* armies;
    int* cities;
    int* age;
    std::string* name;
    std::vector<std::string>* regions;          // TODO: Figure out why we need this
    std::vector<std::string>* countries;        // TODO: Figure out why we need this
    std::vector<Deck>* gameHand;
    BiddingFacility* biddingFacility;

public:
    // Constructors
    Player(std::string name, int age);
    Player(std::string name, int numOfPlayers, int age);

    // Deconstructor
    ~Player();

    // Gameplay Methods
    bool payCoin(int cost);
    bool placeNewArmies(int totalArmies, Map &gameMap);
    bool moveOverWater(int totalMoves);     // TODO: Fully implement in assignment 2
    bool moveOverLand(int totalMoves);      // TODO: Fully implement in assignment 2
    bool buildCity(Map &gameMap);
    bool destroyArmy();                     // TODO: Fully implement in assignment 2

    // Accessors
    int* getCoins() const;
    int* getArmies() const;
    int* getCities() const;
    int* getAge() const;
    std::string* getName() const;
    BiddingFacility* getBiddingFacility() const;

    // Mutators
    void setCoins(int coins);
    void setArmies(int armies);
    void setCities(int cities);
    void setAge(int age);
    void setName(std::string name);
};

#endif

