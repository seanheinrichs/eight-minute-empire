#include "Map/Map.h"
#include "Cards/Cards.h"
#include "Player/Player.h"

void PlayerMethodsDriver() {

    // TODO: Implement Real Map, and have Cards trigger the actions

    Player *sean = new Player("Sean", 3, 15);
    Player *mike = new Player("Mike", 3, 16);
    Player *jia = new Player("Jia", 3, 17);
    std:: vector <Player*> playerVector = {sean, mike, jia};

    std::vector<std::string> regions = {"region1", "region2", "region3"};
    std::vector<std::string> continents = {"continent1"};
    std::vector<std::string> players = {
            *playerVector.at(0)->getName(),
            *playerVector.at(1)->getName(),
            *playerVector.at(2)->getName()
    };

    Node n1{};
    Node n2{};
    Node n3{};
    n1.region = "region1";
    n1.continent = "continent1";
    //n1.owner = *playerVector.at(0)->getName();
    n1.armies.insert(make_pair(*playerVector.at(0)->getName(), std::pair<int, bool>(3, false)));
    n1.armies.insert(make_pair(*playerVector.at(1)->getName(), std::pair<int, bool>(3, false)));
    n1.armies.insert(make_pair(*playerVector.at(2)->getName(), std::pair<int, bool>(3, false)));
    n1.connectedTo.emplace_back(std::pair<std::string, bool>("region2", false));
    n1.connectedTo.emplace_back(std::pair<std::string, bool>("region3", true));

    n2.region = "region2";
    n2.continent = "continent1";
    //n2.owner = *playerVector.at(1)->getName();
    n2.connectedTo.emplace_back(std::pair<std::string, bool>("region1", false));
    n2.connectedTo.emplace_back(std::pair<std::string, bool>("region3", false));

    n3.region = "region3";
    n3.continent = "continent1";
    //n3.owner = *playerVector.at(2)->getName();
    n3.connectedTo.emplace_back(std::pair<std::string, bool>("region1", true));
    n3.connectedTo.emplace_back(std::pair<std::string, bool>("region2", false));

    std::vector<Node> nodeVector;
    nodeVector.emplace_back(n1);
    nodeVector.emplace_back(n2);
    nodeVector.emplace_back(n3);


    Map m1(nodeVector, "region1", regions, continents, players);

    m1.printNodes();

    playerVector.at(1)->moveArmies(2, m1, true);
    playerVector.at(1)->buildCity(m1);
    playerVector.at(1)->placeNewArmies(3, m1);
    playerVector.at(2)->destroyArmy(m1, playerVector);
    playerVector.at(0)->moveArmies(2, m1, false);

    m1.printNodes();
}

