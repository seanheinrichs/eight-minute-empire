#pragma once
#include "MapLoader.h"
#include "../Map/Map.h"

// print two maps
void validMapFileExamples();

// Example of malformed map file: Invalid continent
void invalidContinentFileExample();

// Example of malformed map file: No players
void noPlayersInFileExample();

// Example of malformed map file: Invalid land/sea connection
void invalidConnectionInFileExample();

// Example of malformed map file: Not enough delimiters to make Node
void missingDelitimerInFileExample();

// Example of graph that is not fully connected
void graphNotConnectedInFileExample();