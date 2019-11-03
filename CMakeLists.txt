cmake_minimum_required(VERSION 3.15)
project(eight_minute_empire)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(src/BiddingFacility)
include_directories(src/Cards)
include_directories(src/Map)
include_directories(src/MapLoader)
include_directories(src/Player)
include_directories(src/GameState)
include_directories(src/GameStartup)

add_executable(eight_minute_empire
    src/BiddingFacility/BiddingFacility.cpp
    src/BiddingFacility/BiddingFacility.h
    src/Cards/Cards.cpp
    src/Cards/Cards.h
    src/Map/Map.cpp
    src/Map/Map.h
    src/Map/MapDriver.cpp
    src/Map/MapDriver.h
    src/MapLoader/MapLoader.cpp
    src/MapLoader/MapLoader.h
    src/Player/Player.cpp
    src/Player/Player.h
    src/Player/PlayerDriver.cpp
    src/Player/PlayerDriver.h
    src/MainLoop/MainLoop.cpp
    src/MainLoop/MainLoop.h
    src/GameState/GameState.cpp
    src/GameState/GameState.h
    src/GameState/GameStateDriver.cpp
    src/GameState/GameStateDriver.h
    src/GameStartup/GameStartup.cpp
    src/GameStartup/GameStartup.h
    src/GameStartup/GameStartupDriver.cpp
    src/GameStartup/GameStartupDriver.h
    src/main.cpp)
