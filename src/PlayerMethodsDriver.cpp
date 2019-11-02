#include "Map/Map.h"
#include "MapLoader/MapLoader.h"
#include "Cards/Cards.h"
#include "Player/Player.h"
#include "BiddingFacility/BiddingFacility.h"

void PlayerMethodsDriver() {

    Player *sean = new Player("Sean", 2, 21);
    Player *mike = new Player("Mike", 2, 30);
    std:: vector <Player*> playerVector = {sean, mike};

    std::vector<std::string> regions = {"region1", "region2", "region3"};
    std::vector<std::string> continents = {"continent1"};
    std::vector<std::string> players = {"mike"};

    Node n1{};
    Node n2{};
    Node n3{};
    n1.region = "region1";
    n1.continent = "continent1";
    n1.owner = *playerVector.at(0)->getName();
    n1.armies.insert(make_pair(*playerVector.at(0)->getName(), std::pair<int, bool>(10, false)));
    n1.connectedTo.emplace_back(std::pair<std::string, bool>("region2", true));
    n1.connectedTo.emplace_back(std::pair<std::string, bool>("region3", true));

    n2.region = "region2";
    n2.continent = "continent1";
    n2.owner = *playerVector.at(1)->getName();
    n2.armies.insert(make_pair(*playerVector.at(1)->getName(), std::pair<int, bool>(10, true)));
    n2.connectedTo.emplace_back(std::pair<std::string, bool>("region1", true));

    n3.region = "region3";
    n3.continent = "continent1";
    n3.owner = *playerVector.at(1)->getName();
    n3.armies.insert(make_pair(*playerVector.at(1)->getName(), std::pair<int, bool>(10, true)));
    n3.connectedTo.emplace_back(std::pair<std::string, bool>("region1", true));

    std::vector<Node> nodeVector;
    nodeVector.emplace_back(n1);
    nodeVector.emplace_back(n2);
    nodeVector.emplace_back(n3);


    Map m1(nodeVector, "region1", regions, continents, players);

    playerVector.at(0)->buildCity(m1);
    playerVector.at(0)->placeNewArmies(3, m1);

    m1.printNodes();
}

