#pragma once
#include <iostream>
#include <map>
#include <utility>
#include "Map.h"

// TODO: Make this into a subclass with pointers and a constructor.
class Node {
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
        class Node {
        // region name
        std::string* region;
        // continent name
        std::string* continent;
        // key is playername
        // value is array of two ints: armies, cities
        std::map<std::string, std::pair<int, int>>* armies;
        // playername for owner
        std::string* owner;
        // array of regions it is connected to
        // first of pair is region name
        // second is true if water-crossing
        std::pair<std::string, bool>* connectedTo[];

        Node(std::string r, std::string c, std::string players[], int armies[][2]);
        ~Node();
        };

        // connected graph of Nodes
        std::map<Node, int[]>* nodes;
        // starting node
        std::string* start;
        // returns a node. Helper function for the public methods
        Node getNode(std::string region);
    public:
        // TODO: parameterized constructors
        Map();
        ~Map();
        // calculate and set the owner for a node
        void updateOwnership(); // update all
        void updateOwnership(std::string region); // update one
        // add army to Node
        void addArmies(std::string player, std::string region, int armies);
        // remove armies from Node
        void removeArmies(std::string player, std::string region, int armies);
        // add cities to Node
        void addCity(std::string player, std::string region);
        // remove cities from Node
        void removeCity(std::string player, std::string region);
};