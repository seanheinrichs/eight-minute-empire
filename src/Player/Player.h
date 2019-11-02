#ifndef EIGHT_MINUTE_EMPIRE_PLAYER_H
#define EIGHT_MINUTE_EMPIRE_PLAYER_H

#include "../BiddingFacility/BiddingFacility.h"
#include "../Cards/Cards.h"
#include "../Map/Map.h"
#include <string>
#include <vector>

// Forward Declaration
class BiddingFacility;

class Player {

private:
  int *coins;
  int *armies;
  int *cities;
  int *dateOfBirth;
  std::string *name;
  std::vector<std::string> *regions;   // TODO: Figure out why we need this
  std::vector<std::string> *countries; // TODO: Figure out why we need this
  // std::vector<Cards> *gameHand;
  BiddingFacility *biddingFacility;

public:
  // Constructors
  Player(std::string name, int dateOfBirth);
  Player(std::string name, int numOfPlayers, int dateOfBirth);

  // Deconstructor
  ~Player();

  // Gameplay Methods
  bool payCoin(int cost);
  bool placeNewArmies(int totalArmies, std::string regionName, Map gameMap);
  void moveOverWater(int totalMoves); // TODO: Fully implement in assignment 2
  void moveOverLand(int totalMoves);  // TODO: Fully implement in assignment 2
  void buildCity();                   // TODO: Fully implement in assignment 2
  void destroyArmy();                 // TODO: Fully implement in assignment 2

  // Accessors
  int *getCoins() const;
  int *getArmies() const;
  int *getCities() const;
  int *getDateOfBirth() const;
  std::string *getName() const;
  void getGameHand() const;
  // std::vector<Cards> *getGameHand() const;
  BiddingFacility *getBiddingFacility() const;

  // Mutators
  void setCoins(int coins);
  void setArmies(int armies);
  void setCities(int cities);
  void setDateOfBirth(int dateOfBirth);
  void setName(std::string name);
  void addCards(Cards card);
};

#endif