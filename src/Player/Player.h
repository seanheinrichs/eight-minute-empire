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

    // Utility Methods
    std::string validateRegion(std::vector<std::string> placementRegions);

public:
    // Constructors
    Player(std::string name, int age);
    Player(std::string name, int numOfPlayers, int age);

    // Deconstructor
    ~Player();

    // Gameplay Methods
    bool payCoin(int cost);
    bool placeNewArmies(int totalArmies, Map &gameBoard);
    void moveArmies(int totalMoves, Map &gameBoard, bool waterMove);
    bool buildCity(Map &gameBoard);
    void destroyArmy(Map &gameBoard, std::vector<Player*> allPlayers);

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

