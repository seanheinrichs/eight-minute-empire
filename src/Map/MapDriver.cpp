#include <iostream>
#include "MapDriver.h"
using namespace std;

void mapSingletonTest() {
    cout << "============ Test Singleton ==============="<< endl;
    std::vector<std::string> regions = {"region1", "region2"};
    std::vector<std::string> continents = {"continent1"};
    std::vector<std::string> players = {"mike"};

    Node n1{};
    Node n2{};
    n1.region = "region1";
    n1.continent = "continent1";
    n1.owner = "mike";
    n1.armies.insert(make_pair("mike", std::pair<int, bool>(10, false)));
    n1.connectedTo.emplace_back(std::pair<std::string, bool>("region2", true));

    n2.region = "region2";
    n2.continent = "continent1";
    n2.owner = "mike";
    n2.armies.insert(make_pair("mike", std::pair<int, bool>(10, true)));
    n2.connectedTo.emplace_back(std::pair<std::string, bool>("region1", true));

    std::vector<Node> nodeVector;
    nodeVector.emplace_back(n1);
    nodeVector.emplace_back(n2);
    auto m1 = Map::getInstance(nodeVector, "region1", regions, continents, players);
    auto m2 = Map::getInstance(nodeVector, "region1", regions, continents, players);

    m1->addArmy("region1", "sean");

    if (m1 == m2) {
        cout <<"Singleton works, both have the same instance." << endl;
    } else {
        cout <<"Singleton failed, they are different instances." << endl;
    }
    cout << "============ --------------- ==============="<< endl;

    cout << "============ -------map 1-------- ==============="<< endl;
    m1->printNodes();
    cout << "============ -------map 2-------- ==============="<< endl;
    m2->printNodes();
    cout << "notice that map 2 also has sean's record, which prove singleton works fine." << endl;
    cout << "\n=============== Test resetMapInstance( ) ================"<< endl;
    Map::resetMapInstance();

    cout << "\n=============== Test getInstance( ) from filelocation ================"<< endl;
    cout << "Suggest file location: ../assets/map8.map      for CLion"<< endl;
    cout << "Suggest file location: assets/map8.map      for VSCode"<< endl;
    auto map = Map::getInstance();
    map->addArmy("Canada", "Player1");
    map->printNodes();
    cout <<"\n==== Test singleton map1 should be same as map ==========" << endl;
    auto map1 = Map::getInstance();
    map1->printNodes();
    Map::resetMapInstance();

}
