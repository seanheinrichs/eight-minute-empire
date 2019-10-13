#include "MapLoaderDriver.h"

void validMapFileExamples()
{
    MapLoader loader1;
    MapLoader loader2;

    Map m1 = loader1.generateMap("assets/map1.map");
    m1.printNodes();
    Map m2 = loader2.generateMap("assets/map6.map");
    m2.printNodes();
}

void invalidContinentFileExample()
{
    MapLoader loader;
    loader.generateMap("assets/map2.map");
}

void noPlayersInFileExample()
{
    MapLoader loader;
    loader.generateMap("assets/map3.map");
}

void invalidConnectionInFileExample()
{
    MapLoader loader;
    loader.generateMap("assets/map4.map");
}

void missingDelitimerInFileExample()
{
    MapLoader loader;
    loader.generateMap("assets/map5.map");
}