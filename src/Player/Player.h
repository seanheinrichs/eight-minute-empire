#ifndef EIGHT_MINUTE_EMPIRE_PLAYER_H
#define EIGHT_MINUTE_EMPIRE_PLAYER_H

#include "../BiddingFacility/BiddingFacility.h"
#include "PlayerStrategies/PlayerStrategies.h"
#include "../Map/Map.h"
#include <string>
#include <vector>


// Forward Declaration
class Cards;
class BiddingFacility;
class PlayerStrategies;

class Player
{

private:
  int *coins;
  int *armies;
  int *cities;
  int *age;
  int *points;
  std::string *name;
  std::vector<Cards*> *gameHand;
  BiddingFacility *biddingFacility;
  PlayerStrategies *playerStrategy;

  // Utility Methods
  std::string validateRegion(std::vector<std::string> placementRegions);
  int validateActionSelection();

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
  void destroyArmy(Map &gameBoard, std::vector<Player *> allPlayers);
  bool ignore();
  void andOrAction(std::string action, Map &gameBoard, std::vector<Player *> &allPlayers);
  void takeAction(std::string action, Map &gameBoard, std::vector<Player *> &allPlayers);

  // Accessors
  int getCoins() const;
  int getArmies() const;
  int getCities() const;
  int getAge() const;
  int getPoints() const;
  std::string getName() const;
  std::vector<Cards*> *getGameHand() const;
  BiddingFacility *getBiddingFacility() const;
  PlayerStrategies *getPlayerStrategies() const;

  // Mutators
  void setCoins(int coins);
  void setArmies(int armies);
  void setCities(int cities);
  void setAge(int age);
  void setName(std::string name);
  void setPlayerStrategy(PlayerStrategies* newPlayerStrategy);
  void addPoints(int additionalPoints);
};

#endif
