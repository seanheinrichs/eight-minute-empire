#include <iostream>
#include "GameState.h"

GameState::GameState()
{
    // generate map
    std::string fileLocation;
    std::cout << "Enter map file location: ";
    std::cin >> fileLocation;
    std::cout << std::endl;

    MapLoader loader;
    map = new Map(loader.generateMap(fileLocation));

    // generate deck of cards
    deck = new Deck();

    // generate players
}
GameState::~GameState()
{
    if (map)
    {
        delete map;
        map = NULL;
    }
    if (players)
    {
        delete players;
        players = NULL;
    }
    if (deck)
    {
        delete deck;
        deck = NULL;
    }
}