#pragma once
#include <iostream>
#include "MapLoader.h"
#include "Map.h"
#include "Player.h"
#include "Cards.h"

class GameState 
{
    public:
    // game state member variables public as their purpose is to be mutated throughout the game
    Map *map;
    Deck *deck;
    std::map<std::string, Player> *players;
    
    GameState();
    ~GameState();    
};