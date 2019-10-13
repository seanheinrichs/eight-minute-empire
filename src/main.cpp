#include "MapDriver.h"
#include "MapLoaderDriver.h"

int main()
{
    std::cout << "Please see main.cpp and uncomment functions to show Map and map file rejections\n\n";
    ///// MapDriver Examples /////

    // valid map creation
    validMapExample();

    // rejection of invalid map data
    // uncomment sections below to cause program to fail

    // invalidRegionMapExample();
    // invalidContinentMapExample();
    // invalidOwnerMapExample();
    // invalidConnectionsMapExample();
    // invalidStartMapExample();

    ///// MapLoaderDriver Examples /////

    // valid file read and map creation example
    validMapFileExamples();

    // rejection of invalid map file
    // uncomment sections below to cause program to fail

    // void invalidContinentFileExample();
    // void noPlayersInFileExample();
    // void invalidConnectionInFileExample();
    // void missingDelitimerInFileExample();

    return 0;
}