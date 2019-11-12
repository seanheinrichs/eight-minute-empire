#include "Map/Map.h"
#include "Cards/Cards.h"
#include "Player/Player.h"

void playerMethodsDriver() {

    // create player vector
    Player *sean = new Player("Sean", 3, 15);
    Player *mike = new Player("Mike", 3, 16);
    Player *jia = new Player("Jia", 3, 17);
    std:: vector <Player*> playerVector = {sean, mike, jia};

    // create the map
    std::vector<std::string> regions = {"region1", "region2", "region3"};
    std::vector<std::string> continents = {"continent1"};
    std::vector<std::string> players = {
            playerVector.at(0)->getName(),
            playerVector.at(1)->getName(),
            playerVector.at(2)->getName()
    };

    Node n1{};
    Node n2{};
    Node n3{};
    n1.region = "region1";
    n1.continent = "continent1";
    n1.armies.insert(make_pair(playerVector.at(0)->getName(), std::pair<int, bool>(3, false)));
    n1.armies.insert(make_pair(playerVector.at(1)->getName(), std::pair<int, bool>(3, false)));
    n1.armies.insert(make_pair(playerVector.at(2)->getName(), std::pair<int, bool>(3, false)));
    n1.connectedTo.emplace_back(std::pair<std::string, bool>("region2", false));
    n1.connectedTo.emplace_back(std::pair<std::string, bool>("region3", true));

    n2.region = "region2";
    n2.continent = "continent1";
    n2.connectedTo.emplace_back(std::pair<std::string, bool>("region1", false));
    n2.connectedTo.emplace_back(std::pair<std::string, bool>("region3", false));

    n3.region = "region3";
    n3.continent = "continent1";
    n3.connectedTo.emplace_back(std::pair<std::string, bool>("region1", true));
    n3.connectedTo.emplace_back(std::pair<std::string, bool>("region2", false));

    std::vector<Node> nodeVector;
    nodeVector.emplace_back(n1);
    nodeVector.emplace_back(n2);
    nodeVector.emplace_back(n3);

    Map m1(nodeVector, "region1", regions, continents, players);

    // create cards to showcase all available actions
    Cards *card1 = new Cards(1,"Wild", "MOVE_OVER_WATER 2");
    Cards *card2 = new Cards(1,"Wild", "PLACE_NEW_ARMIES_ON_BOARD 2");
    Cards *card3 = new Cards(1,"Crystal", "MOVE_OVER_GROUND 2");
    Cards *card4 = new Cards(1,"Rock", "PLACE_NEW_ARMIES_ON_BOARD 3");
    Cards *card5 = new Cards(1,"Rock", "PLACE_NEW_ARMIES_ON_BOARD 2 OR BUILD_A_CITY 1");
    Cards *card6 = new Cards(1,"Carrot", "BUILD_A_CITY 1");
    Cards *card7 = new Cards(1,"Carrot", "DESTROY_ARMY 1 AND PLACE_NEW_ARMIES_ON_BOARD 1");

    // demo calls
    playerVector.at(0)->takeAction(*card1->getAction(), m1, playerVector);

    m1.printNodes();

    playerVector.at(1)->takeAction(*card2->getAction(), m1, playerVector);

    m1.printNodes();

    playerVector.at(2)->takeAction(*card3->getAction(), m1, playerVector);

    m1.printNodes();

    playerVector.at(0)->takeAction(*card4->getAction(), m1, playerVector);

    m1.printNodes();

    playerVector.at(1)->andOrAction(*card5->getAction(), m1, playerVector);

    m1.printNodes();

    playerVector.at(2)->takeAction(*card6->getAction(), m1, playerVector);

    m1.printNodes();

    playerVector.at(0)->andOrAction(*card7->getAction(), m1, playerVector);

    m1.printNodes();
}

