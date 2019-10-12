#include <iostream>
#include "Map.h"

int main() {
    std::vector<std::string> regions = {"region1", "region2"};
    std::vector<std::string> continents = {"continent1"};
    std::vector<std::string> players = {"mike"};

    Node n1 = Node{};
    n1.region = "region1";
    n1.continent = "continent1";
    n1.owner = "mike";
    n1.armies.insert(make_pair("mike", std::pair<int, int>(10, false)));
    n1.connectedTo.emplace_back(std::pair<std::string, bool>("region2", true));

    Node n2 = Node{};
    n2.region = "region2";
    n2.continent = "continent1";
    n2.owner = "mike";
    n2.armies.insert(make_pair("mike", std::pair<int, int>(10, true)));
    n2.connectedTo.emplace_back(std::pair<std::string, bool>("region1", true));

    std::vector<Node> nodeVector;
    nodeVector.emplace_back(n1);
    nodeVector.emplace_back(n2);

    // Example of a valid map
    Map m1(nodeVector, "region1", regions, continents, players);
    m1.printNodes();

    // Example of map with invalid region name
    // nodeVector.at(0).region = "this is an invalid name";
    // Map m2(nodeVector, "region1", regions, continents, players);

    // Example of map with invalid continent name
    // nodeVector.at(0).continent = "this is an invalid continent name";
    // Map m3(nodeVector, "region1", regions, continents, players);

    // Example of map with invalid owner
    // nodeVector.at(0).owner = "this is an invalid owner name";
    // Map m4(nodeVector, "region1", regions, continents, players);

    // Example of map with invalid connections
    // nodeVector.at(0).connectedTo = std::vector<std::pair<std::string, bool>>();
    // Map m5(nodeVector, "region1", regions, continents, players);

    // Example of map with invalid starting region    
    // Map m6(nodeVector, "invalid region name", regions, continents, players);
    
    return 0;
}