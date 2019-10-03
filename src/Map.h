#pragma once
#include <iostream>
#include <map>
#include <utility>
#include "Map.h"

// Class: Map
// Node: Struct (refactor to inner classl later?)
// Store in a map, with a unique id as the key
// Constructor: add them, then set connectedTo?
// The map file I'll be given NEEDS a uid, so use whatever that is
// ^ Otherwise it couldn't do it itself either

// TODO: Find a way to make this private
// TODO: Make this into a subclass with pointers and a constructor.
struct Node {
    // region name
    std::string region;
    // continent name
    std::string continent;
    // key is playername
    // value is array of two ints: armies, cities
    std::map<std::string, std::pair<int, int>> armies;
    // playername for owner
    std::string owner;
    // array of regions it is connected to
    // first of pair is region name
    // second is true if water-crossing
    std::pair<std::string, bool> connectedTo[];
};

class Map {
    private:
        std::map<Node, int[]>* nodes;

        // returns a node. Helper function for the public methods
        Node getNode(std::string region);
    public:
        // TODO: parameterized constructors
        Map();
        // calculate and set the owner for a node
        void updateOwnership(); // update all
        void updateOwnership(Node n); // update one
        // add army to Node
        void addArmies(std::string player, std::string region, int armies);
        // remove armies from Node
        void removeArmies(std::string player, std::string region, int armies);
        // add cities to Node
        void addCity(std::string player, std::string region);
        // remove cities from Node
        void removeCity(std::string player, std::string region);
        
        // TODO: Destructor
};