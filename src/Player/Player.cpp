#include "Player.h"
#include "../BiddingFacility/BiddingFacility.h"
#include "../Map/Map.h"
#include <iostream>
#include <string>

// Constructors

Player::Player(std::string name, int age)
{
    Player::cities = new int(3);
    Player::armies = new int(14);
    Player::coins = new int(14);
    Player::points = new int(0);
    Player::name = new std::string(name);
    Player::age = new int(age);
    Player::gameHand = new std::vector<Cards*>();
    Player::biddingFacility = new BiddingFacility();
    Player::playerStrategy = new HumanPlayer();
}

Player::Player(std::string name, int numOfPlayers, int age)
{
    Player::cities = new int(3);
    Player::armies = new int(14);
    Player::points = new int(0);
    Player::name = new std::string(name);
    Player::age = new int(age);
    Player::gameHand = new std::vector<Cards*>();
    Player::biddingFacility = new BiddingFacility();
    Player::playerStrategy = new HumanPlayer();

    // Amount of coins available to Players is determined by # of Players
    switch (numOfPlayers)
    {
        case 2:
            Player::coins = new int(14);
            break;
        case 3:
            Player::coins = new int(11);
            break;
        case 4:
            Player::coins = new int(9);
            break;
        case 5:
            Player::coins = new int(8);
            break;
    }
}

// Deconstructor

Player::~Player()
{
    if (coins) {
        delete coins;
        coins = NULL;
    }

    if (armies) {
        delete armies;
        armies = NULL;
    }
    if (cities) {
        delete cities;
        cities = NULL;
    }
    if (age) {
        delete age;
        age = NULL;
    }
    if (points) {
        delete points;
        points = NULL;
    }
    if (name) {
        delete name;
        name = NULL;
    }
    if (gameHand) {
        delete gameHand;
        gameHand = NULL;
    }
    if (biddingFacility) {
        delete biddingFacility;
        biddingFacility = NULL;
    }
    if (playerStrategy) {
        delete playerStrategy;
        playerStrategy = NULL;
    }
};

// General Gameplay Methods

bool Player::payCoin(int cost)
{
    if (*coins < cost) {
        std::cout << "You don't have enough coins to purchase that." << std::endl;
        return false;
    }
    else {
        setCoins(*coins - cost);
        std::cout << "Successful purchase " << *name << ", you have " << *coins << " coins remaining in your pile." << std::endl << std::endl;
        return true;
    }
}

// Player Methods

void Player::placeNewArmies(int totalArmies, Map &gameBoard)
{
    // check to see if player has available armies to place
    if (*armies == 0) {
        std::cout << "Sorry, " << *name << " you have no more available armies." << std::endl;
        return;
    }

    int spendableArmies;
    std::string regionName;
    std::vector<std::string> placementRegions;

    // if player doesn't have enough armies to fulfill the value on card, place remaining armies
    if (totalArmies > *armies) {
        spendableArmies = *armies;
    }
    else {
        spendableArmies = totalArmies;
    }

    for (int i = 0; i < spendableArmies; i++) {
        // Human Player Logic - User Interaction
        if (playerStrategy->displayCurrentStrategy() == "Human Player") {
            // inform player where they can place units (ie. starting area and where they have cities)
            if (spendableArmies == 1) {
                std::cout << *name << ", you have " << spendableArmies << " army to place on the map." << std::endl;
            }
            else {
                std::cout << *name << ", you have " << spendableArmies << " armies to place on the map." << std::endl;
            }
            std::cout << "Here are the areas in which you may place an army: " << std::endl;
            placementRegions = gameBoard.getRegionsToAddArmies(*name);
            for (int i = 0; i < placementRegions.size(); i++) {
                std::cout << "- " << placementRegions.at(i) << std::endl;
            }

            // place new armies
            {
                std::cout << "Select a region in which you like to place an army: ";
                regionName = validateRegion(placementRegions);
            }
        }
            // Greedy Computer Logic - Randomly Select a Region to Place Unit
        else if (playerStrategy-> displayCurrentStrategy() == "Greedy Computer") {
            placementRegions = gameBoard.getRegionsToAddArmies(*name);
            for (int i = 0; i < spendableArmies; i++){
                regionName = placementRegions.at(rand() % placementRegions.size());
            }
        }
            // Moderate Computer Logic - Only Place Armies on the Starting Area
        else {
            for (int i = 0; i < spendableArmies; i++) {
                regionName = *gameBoard.getStart();
            }
        }
        (*armies)--;
        gameBoard.addArmy(regionName, *name);
        std::cout << "Successfully added an army to " << regionName << "." << std::endl
                  << std::endl;
    }
}

void Player::moveArmies(int totalMoves, Map &gameBoard, bool waterMove)
{
    std::string origin;
    std::string destination;
    std::vector<std::string> regionsWithArmies;
    std::vector<std::string> connections;

    for (int i = 0; i < totalMoves; i++) {
        // Human Logic - User Interaction
        if (playerStrategy->displayCurrentStrategy() == "Human Player") {
            // display regions where player currently has armies
            std::cout << *name << ", you have armies in the following locations: " << std::endl;
            regionsWithArmies = gameBoard.getRegionsWithArmies(*name);
            for (int i = 0; i < regionsWithArmies.size(); i++) {
                std::cout << "- " << regionsWithArmies.at(i) << std::endl;
            }

            // player selects a region to move an army from
            std::cout << "Please select a region in which to move an army from: ";
            origin = validateRegion(regionsWithArmies);

            // display connected regions
            std::cout << "The following regions are connected to " << origin << ": " << std::endl;
            if (waterMove) {
                connections = gameBoard.getRegionsConnectedByLandAndWater(origin);
            }
            else {
                connections = gameBoard.getRegionsConnectedByLand(origin);
            }
            for (int i = 0; i < connections.size(); i++) {
                std::cout << "- " << connections.at(i) << std::endl;
            }

            // player selects a region to move an army to
            std::cout << "Please select a region in which to move an army to: ";
            destination = validateRegion(connections);
        }
        // Greedy and Moderate Computer - Randomly Moves Troops
        else {
            // randomly select a possible origin
            regionsWithArmies = gameBoard.getRegionsWithArmies(*name);
            origin = regionsWithArmies.at(rand() % regionsWithArmies.size());

            // check to see if water move
            if (waterMove) {
                connections = gameBoard.getRegionsConnectedByLandAndWater(origin);
            }
            else {
                connections = gameBoard.getRegionsConnectedByLand(origin);
                // ensure that a connection exists
                while (connections.size() == 0){
                    origin = regionsWithArmies.at(rand() % regionsWithArmies.size());
                    connections = gameBoard.getRegionsConnectedByLand(origin);
                }
            }

            // randomly select a possible destination
            destination = connections.at(rand() % connections.size());
        }
        // move army
        gameBoard.moveArmy(origin, destination, *name);
        std::cout << "Sucessfully moved 1 troop from " << origin << " to " << destination << "." << std::endl
                  << std::endl;
    }
}

void Player::buildCity(Map &gameBoard)
{
    // check to see if player has available cities to place
    if (*cities == 0) {
        std::cout << "Sorry, " << *name << "you have no more available cities." << std::endl;
        return;
    }

    std::string regionName;
    std::vector<std::string> placementRegions;

    if (playerStrategy->displayCurrentStrategy() == "Human Player") {
        // inform player where they can place a city
        std::cout << *name << ", here are the regions in which you may place a city: " << std::endl;
        placementRegions = gameBoard.getRegionsToAddCities(*name);
        for (int i = 0; i < placementRegions.size(); i++) {
            std::cout << "- " << placementRegions.at(i) << std::endl;
        }
        // place new city
        std::cout << "Please select a region to place a city: ";
        regionName = validateRegion(placementRegions);
    }
    // Greedy Computer and Moderate Computer - Place a City Randomly on the Map
    else {
        placementRegions = gameBoard.getRegionsToAddCities(*name);
        regionName = placementRegions.at(rand() % placementRegions.size());
    }
    (*cities)--;
    gameBoard.addCity(regionName, *name);
    std::cout << "Successfully added a city to " << regionName << "." << std::endl
              << std::endl;
}

void Player::destroyArmy(Map &gameBoard, std::vector<Player *> allPlayers)
{
    std::string playerName;
    std::string regionName;
    std::vector<std::string> regionsWithEnemies;
    bool invalidPlayerName = false;

    // Human Player Logic - User Interaction
    if (playerStrategy->displayCurrentStrategy() == "Human Player") {
        // select another player whose army will be destroyed
        std::cout << *name << ", please select a player to destroy one of their armies: ";
        do
        {
            std::cin >> playerName;
            for (int i = 0; i < allPlayers.size(); i++) {
                if (playerName == *name || playerName != allPlayers.at(i)->getName()) {
                    invalidPlayerName = true;
                }
                else {
                    invalidPlayerName = false;
                    break;
                }
            }
            if (invalidPlayerName) {
                std::cout << "ERROR: Invalid player name provided. Please select another player: ";
            }
        } while (invalidPlayerName);

        // inform player where the armies from the targeted player are
        std::cout << *name << ", here are the regions where " << playerName << " has armies." << std::endl;
        regionsWithEnemies = gameBoard.getRegionsWithArmies(playerName);
        for (int i = 0; i < regionsWithEnemies.size(); i++) {
            std::cout << "- " << regionsWithEnemies.at(i) << std::endl;
        }

        // select a region to destroy a unit
        std::cout << "Please select a region to remove an army from: ";
        regionName = validateRegion(regionsWithEnemies);
    }
    // Greedy Computer and Moderate Computer Logic - Destroy Random Player's Army
    else {
        for (int i = 0; i < allPlayers.size(); i++){
            if (allPlayers.at(i)->getName() == *name){
                continue;
            }
            else {
                playerName = allPlayers.at(i)->getName();
            }
        }
        regionsWithEnemies = gameBoard.getRegionsWithArmies(playerName);
        regionName = regionsWithEnemies.at(rand() % regionsWithEnemies.size());
    }
    gameBoard.destroyArmy(regionName, playerName);
    std::cout << "Successfully removed one of " << playerName << "'s armies from " << regionName << "." << std::endl
              << std::endl;
}

bool Player::ignore()
{
    bool invalidAnswer = true;
    std::string answer;
    std::cout << "Would you like to use the action listed on the card (y/n)? ";
    do {
        std::cin >> answer;
        if (answer == "y" || answer == "n") {
            invalidAnswer = false;
        }
        else {
            std::cout << "Invalid answer. Please response with \'y\' or \'n\': ";
        }
    } while (invalidAnswer);
    std::cout << std::endl;
    return (answer == "n");
}

void Player::takeAction(std::string action, Map &gameBoard, std::vector<Player*> &allPlayers)
{
    // get region owners at start of turn
    auto startOwners = gameBoard.getRegionOwners();

    std::string playerAction = action.substr(0, action.find(" "));
    int quantity = std::stoi(action.substr(action.find(" ") + 1));

    if (playerAction == "MOVE_OVER_WATER") {
        moveArmies(quantity, gameBoard, true);
    }
    else if (playerAction == "MOVE_OVER_GROUND") {
        moveArmies(quantity, gameBoard, false);
    }
    else if (playerAction == "PLACE_NEW_ARMIES_ON_BOARD") {
        placeNewArmies(quantity, gameBoard);
    }
    else if (playerAction == "BUILD_A_CITY") {
        buildCity(gameBoard);
    }
    else if (playerAction == "DESTROY_ARMY") {
        destroyArmy(gameBoard, allPlayers);
    }

    // get region owners at end of turn
    auto endOwners = gameBoard.getRegionOwners();

    // loop over players once, taking the difference in regions owned
    for (int i = 0; i < allPlayers.size(); i++) {
        int startTotal = 0;
        int endTotal = 0;

        // get how many regions the player owns at the start of the turn
        if (!(startOwners.find(allPlayers.at(i)->getName()) == startOwners.end())) {
            startTotal = startOwners.at(allPlayers.at(i)->getName()).size();   
        }
        
        // get how many regions the player owns at the end of the turn
        if (!(endOwners.find(allPlayers.at(i)->getName()) == endOwners.end())) {
            endTotal = endOwners.at(allPlayers.at(i)->getName()).size();   
        }

        // take the difference and add/subtract that amount
        allPlayers.at(i)->addPoints(startTotal - endTotal);
    }

}

void Player::andOrAction(std::string action, Map &gameBoard, std::vector<Player*> &allPlayers)
{
    int answer;

    // Human Player Logic - User Interaction
    if (playerStrategy->displayCurrentStrategy() == "Human Player") {
        // OR Card Type
        if (action.find("OR") != std::string::npos) {
            // split string into two halves
            std::string firstAction = action.substr(0, action.find("OR"));
            std::string secondAction = action.substr(action.find("OR") + 3);

            std::cout << "Here are your following choices: " << std::endl;
            std::cout << "1) " << firstAction << std::endl;
            std::cout << "2) " << secondAction << std::endl;
            std::cout << "Please select one of the following by entering '1' or '2': ";

            answer = validateActionSelection();

            if (answer == 1) {
                takeAction(firstAction, gameBoard, allPlayers);
            }
            else {
                takeAction(secondAction, gameBoard, allPlayers);
            }
        }
        // AND Card Type
        else {
            // split string into two halves
            std::string firstAction = action.substr(0, action.find("AND"));
            std::string secondAction = action.substr(action.find("AND") + 4);

            std::cout << "Here are your following choices: " << std::endl;
            std::cout << "1) " << firstAction << std::endl;
            std::cout << "2) " << secondAction << std::endl;
            std::cout << "Would you prefer to take '1' or '2' actions? : ";

            // validate user selection
            answer = validateActionSelection();

            // player only wants to use one of the actions
            if (answer == 1) {
                std::cout << "Please select one of the above actions by entering '1' or '2': ";
                answer = validateActionSelection();
                if (answer == 1) {
                    takeAction(firstAction, gameBoard, allPlayers);
                }
                else {
                    takeAction(secondAction, gameBoard, allPlayers);
                }
            }
                // player wants to use both actions
            else {
                std::cout << "Which action would you like to use first? Please select one of the above actions by entering '1' or '2': ";
                answer = validateActionSelection();
                if (answer == 1) {
                    takeAction(firstAction, gameBoard, allPlayers);
                    takeAction(secondAction, gameBoard, allPlayers);
                }
                else {
                    takeAction(secondAction, gameBoard, allPlayers);
                    takeAction(firstAction, gameBoard, allPlayers);
                }
            }
        }
    }
    // Greedy Computer Logic - OR (Always Choose BUILD_A_CITY or DESTROY_ARMY) | AND (Do First Action then Second)
    else if (playerStrategy->displayCurrentStrategy() == "Greedy Computer") {
        // OR Card Type
        if (action.find("OR") != std::string::npos) {
            // split string into two halves
            std::string firstAction = action.substr(0, action.find("OR"));
            std::string secondAction = action.substr(action.find("OR") + 3);
            if (firstAction.find("CITY") != std::string::npos || firstAction.find("DESTROY")){
                takeAction(secondAction, gameBoard, allPlayers);
            }
            else {
                takeAction(firstAction, gameBoard, allPlayers);
            }
        }
        // AND Card Type
        else {
            // split string into two halves
            std::string firstAction = action.substr(0, action.find("AND"));
            std::string secondAction = action.substr(action.find("AND") + 4);

            takeAction(firstAction, gameBoard, allPlayers);
            takeAction(secondAction, gameBoard, allPlayers);
        }
    }
    // Moderate Computer Logic - OR (Always Choose PLACE_NEW_ARMIES) | AND (Do First Action then Second)
    else {
        // OR Card Type
        if (action.find("OR") != std::string::npos) {
            // split string into two halves
            std::string firstAction = action.substr(0, action.find("OR"));
            std::string secondAction = action.substr(action.find("OR") + 3);

            if (firstAction.find("PLACE_NEW_ARMIES_ON_BOARD") != std::string::npos){
                takeAction(firstAction, gameBoard, allPlayers);
            }
            else {
                takeAction(secondAction, gameBoard, allPlayers);
            }
        }
        // AND Card Type
        else {
            // split string into two halves
            std::string firstAction = action.substr(0, action.find("AND"));
            std::string secondAction = action.substr(action.find("AND") + 4);

            takeAction(firstAction, gameBoard, allPlayers);
            takeAction(secondAction, gameBoard, allPlayers);
        }
    }
}

// Utility Methods

std::string Player::validateRegion(std::vector<std::string> placementRegions)
{
    bool invalidInput = true;
    std::string regionName;

    // accept and validate user input
    do {
        std::cin >> regionName;
        for (int i = 0; i < placementRegions.size(); i++) {
            if (placementRegions.at(i) == regionName) {
                invalidInput = false;
                break;
            }
        }
        if (invalidInput) {
            std::cout << "ERROR: Invalid region. Please enter a region from the list. " << std::endl;
        }
    } while (invalidInput);

    return regionName;
}

int Player::validateActionSelection() {
    int answer;
    bool invalidAnswer = true;

    do {
        std::cin >> answer;
        if (answer < 0 || answer > 2) {
            std::cout << "ERROR: Please enter either a '1' or a '2': ";
        }
        else {
            invalidAnswer = false;
        }
    } while (invalidAnswer);

    return answer;
}

// Accessors

int Player::getCoins() const { return *coins; }

int Player::getArmies() const { return *armies; }

int Player::getCities() const { return *cities; }

int Player::getAge() const { return *age; }

int Player::getPoints() const { return *points; }

std::string Player::getName() const { return *name; }

std::vector<Cards*> *Player::getGameHand() const { return gameHand; }

BiddingFacility *Player::getBiddingFacility() const { return biddingFacility; }

PlayerStrategies *Player::getPlayerStrategies() const { return playerStrategy; }

// Mutators

void Player::setCoins(int coins) { *Player::coins = coins; }

void Player::setArmies(int armies) { *Player::armies = armies; }

void Player::setCities(int cities) { *Player::cities = cities; }

void Player::setAge(int age) { *Player::age = age; }

void Player::setName(std::string name) { *Player::name = name; }

void Player::setPlayerStrategy(PlayerStrategies *newPlayerStrategy) { this->playerStrategy = newPlayerStrategy; }

void Player::addPoints(int additionalPoints) { *Player::points += additionalPoints; }